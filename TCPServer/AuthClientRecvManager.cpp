#include "AuthClientRecvManager.h"
#include "AuthClient.h"
#include "DLLPacketIncludes.h"
#include "Buffer.h"
#include "DefineProtoBuffers.h"
#include "ServerSendManager.h"
#include "Server.h"
#include "ClientInfo.h"

using namespace std;
AuthClientRecvManager* AuthClientRecvManager::m_pInstance = nullptr;
AuthClientRecvManager::AuthClientRecvManager()
{
	m_pClient = nullptr;
	m_data.clear();
	m_bNewPacket = true;
	m_fullLength = 0;
}

AuthClientRecvManager::~AuthClientRecvManager()
{
}

AuthClientRecvManager* AuthClientRecvManager::GetInstance()
{
	if (nullptr == m_pInstance)
		m_pInstance = new AuthClientRecvManager();
	return m_pInstance;
}

void AuthClientRecvManager::DestroyInstance()
{
	if (nullptr != m_pInstance)
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}
}

void AuthClientRecvManager::DeserializePacket(char* rawData, int size, int rawIndex)
{
	if (m_data.size() + size < 4)
	{
		AddData(rawData, size, rawIndex);
	}
	else
	{
		if (m_bNewPacket)
		{
			int headerSize = 4 - m_data.size();
			AddData(rawData, headerSize, rawIndex);
			m_fullLength = ReadLengthInfo();
			int remainedSize = size - headerSize;
			if (m_fullLength <= remainedSize + m_data.size())
			{
				int additionalSize = m_fullLength - m_data.size();
				AddData(rawData, additionalSize, rawIndex + headerSize);
				int nextRawIndex = headerSize + additionalSize;
				ProcessMessage();
				ResetMessageStatus();

				if (size > nextRawIndex)
				{
					DeserializePacket(rawData, size - nextRawIndex, nextRawIndex + rawIndex);
				}
			}
			else
			{
				m_bNewPacket = false;
				AddData(rawData, remainedSize, headerSize + rawIndex);
			}
		}
		else
		{
			if (m_fullLength <= size + m_data.size())
			{
				int needSize = m_fullLength - m_data.size();
				AddData(rawData, needSize, rawIndex);
				int nextRawIndex = needSize;
				ProcessMessage();
				ResetMessageStatus();

				if (size > nextRawIndex)
				{
					DeserializePacket(rawData, size - nextRawIndex, nextRawIndex + rawIndex);
				}
			}
		}
	}
}

void AuthClientRecvManager::AddData(char* rawData, int size, int rawIndex)
{
	int prevIndex = m_data.size();
	m_data.resize(size + m_data.size());
	memcpy(&(m_data[prevIndex]), &(rawData[rawIndex]), size);
}

void AuthClientRecvManager::ProcessMessage()
{
	MessageType type = (MessageType)ReadMessageId();

	switch (type)
	{
	case CONNECT:			ResponseConnect();					break;
	case CREATE_ACCOUNT:	ResponseCreateNewAccount();			break;
	case LOG_IN:			ResponseAuthenticateAnAccount();	break;
	case ERROR_PROTO:		ResponseErrorMsg();					break;
	case CHANGE_NAME:		ResponseChangeNameBroadcast();				break;
	}
}

void AuthClientRecvManager::ResetMessageStatus()
{
	m_fullLength = 0;
	m_data.clear();
	m_bNewPacket = true;
}

uint32_t AuthClientRecvManager::ReadLengthInfo()
{
	uint32_t value = 0;
	value = m_data[3];
	value |= m_data[2] << 8;
	value |= m_data[1] << 16;
	value |= m_data[0] << 24;
	return value;
}

uint32_t AuthClientRecvManager::ReadMessageId()
{
	uint32_t value = 0;
	value = m_data[7];
	value |= m_data[6] << 8;
	value |= m_data[5] << 16;
	value |= m_data[4] << 24;
	return value;
}

void AuthClientRecvManager::ResponseConnect()
{
	pResponseConnect packet;
	packet.Deserialize((char*)&(m_data[0]), m_fullLength);
	if (nullptr != m_pClient)
	{
		m_pClient->m_number = packet.clientId;
	}
}

void AuthClientRecvManager::ResponseCreateNewAccount()
{
	string packetInfo;

	Deserialize((char*)&(m_data[0]), m_fullLength, packetInfo);

	ResponseCreateAccount response;
	bool success = response.ParseFromString(packetInfo);
	if (success)
	{
		int clientId = response.clientid();
		ClientInfo* pClient = m_pServer->GetClient(clientId);
		ServerSendManager::GetInstance()->SendCreateAccountResponse(pClient, packetInfo);
	}
}

void AuthClientRecvManager::ResponseAuthenticateAnAccount()
{
	string packetInfo;

	Deserialize((char*)&(m_data[0]), m_fullLength, packetInfo);

	ResponseAuthenticateAccount response;
	bool success = response.ParseFromString(packetInfo);
	if (success)
	{
		int clientId = response.clientid();
		int64_t userId = response.userid();
		string email = response.email();
		string username = response.username();
		string lastlogin = response.lastlogin();
		string creationdate = response.creationdate();

		ClientInfo* pClient = m_pServer->GetClient(clientId);
		pClient->m_userInfo.userId = response.userid();
		pClient->m_userInfo.email = response.email();
		pClient->m_userInfo.username = response.username();
		pClient->m_userInfo.lastlogin = response.lastlogin();
		pClient->m_userInfo.creationdate = response.creationdate();

		ServerSendManager::GetInstance()->SendAuthenticateResponse(pClient, packetInfo);
	}
}

void AuthClientRecvManager::ResponseChangeNameBroadcast()
{
	string packetInfo;

	Deserialize((char*)&(m_data[0]), m_fullLength, packetInfo);

	ResponseNameChangeBuf response;
	bool success = response.ParseFromString(packetInfo);
	if (success)
	{
		int clientId = response.clientid();
		string newname = response.newname();
		ClientInfo* pClient = m_pServer->GetClient(clientId);

		ServerSendManager::GetInstance()->SendNameChange(pClient, newname);
	}
}

void AuthClientRecvManager::ResponseErrorMsg()
{
	string packetInfo;

	Deserialize((char*)&(m_data[0]), m_fullLength, packetInfo);

	ResponseError error;
	bool success = error.ParseFromString(packetInfo);
	if (success)
	{
		int clientId = error.clientid();
		int serverId = error.serverid();
		int errorId = error.errorid();
		string msg = error.errmessage();
		cout << "GetErrorMsg: " << msg << endl;

		ClientInfo* pClient = m_pServer->GetClient(clientId);
		ServerSendManager::GetInstance()->SendProtoErrMsg(pClient, serverId, errorId, msg);
	}
}

void AuthClientRecvManager::Deserialize(char* data, unsigned int length, string& packetInfo)
{
	Buffer buffer(length);
	memcpy(&(buffer.m_data[0]), data, length);

	unsigned int header_length = buffer.ReadInt();
	unsigned int header_messageId = buffer.ReadInt();

	int size = buffer.ReadInt();
	packetInfo = buffer.ReadString(size);
}