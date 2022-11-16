#include "Buffer.h"
#include "AuthServerRecvManager.h"
#include "AuthServer.h"
#include "LoginDB.h"
#include "AuthServerSendManager.h"
#include "DefineProtoBuffers.h"

using namespace std;
AuthServerRecvManager* AuthServerRecvManager::m_pInstance = nullptr;
AuthServerRecvManager::AuthServerRecvManager()
{
	m_pAuthServer = nullptr;
	m_data.clear();
	m_bNewPacket = true;
	m_fullLength = 0;
}

AuthServerRecvManager::~AuthServerRecvManager()
{
}

AuthServerRecvManager* AuthServerRecvManager::GetInstance()
{
	if (nullptr == m_pInstance)
		m_pInstance = new AuthServerRecvManager();
	return m_pInstance;
}

void AuthServerRecvManager::DestroyInstance()
{
	if (nullptr != m_pInstance)
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}
}
void AuthServerRecvManager::DeserializePacket(char* rawData, int size, int rawIndex)
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

void AuthServerRecvManager::AddData(char* rawData, int size, int rawIndex)
{
	int prevIndex = m_data.size();
	m_data.resize(size + m_data.size());
	memcpy(&(m_data[prevIndex]), &(rawData[rawIndex]), size);
}

void AuthServerRecvManager::ProcessMessage()
{
	MessageType type = (MessageType)ReadMessageId();

	switch (type)
	{
	case CREATE_ACCOUNT:			RequestCreateNewAccount();			break;
	case LOG_IN:					RequestAuthenticateAnAccount();		break;
	case CHANGE_NAME:				RequestChangeName();				break;
	}
}

void AuthServerRecvManager::ResetMessageStatus()
{
	m_fullLength = 0;
	m_data.clear();
	m_bNewPacket = true;
}

uint32_t AuthServerRecvManager::ReadLengthInfo()
{
	uint32_t value = 0;
	value = m_data[3];
	value |= m_data[2] << 8;
	value |= m_data[1] << 16;
	value |= m_data[0] << 24;
	return value;
}

uint32_t AuthServerRecvManager::ReadMessageId()
{
	uint32_t value = 0;
	value = m_data[7];
	value |= m_data[6] << 8;
	value |= m_data[5] << 16;
	value |= m_data[4] << 24;
	return value;
}

void AuthServerRecvManager::RequestCreateNewAccount()
{
	string packetInfo;

	Deserialize((char*)&(m_data[0]), m_fullLength, packetInfo);

	RequestCreateAccount request;
	bool success = request.ParseFromString(packetInfo);
	if (success)
	{
		int clientId = request.clientid();
		int serverId = request.serverid();
		string email = request.email();
		string password = request.plaintextpassword();
		AuthClientInfo* pAuthClient = m_pAuthServer->GetClient(serverId);

		bool isNewEmail = LoginDB::GetInstance()->EmailCheckFromAuthTable(email);
		if (isNewEmail)
		{
			string result;
			sUserInfo userInfo;
			if (LoginDB::GetInstance()->AddUser(email, password, result, userInfo))
			{
				AuthServerSendManager::GetInstance()->SendCreateSuccessResponse(pAuthClient, clientId, userInfo);
			}
			else
			{
				AuthServerSendManager::GetInstance()->SendError(pAuthClient, clientId, ERROR_PROTO, result);
			}
		}
		else
		{
			string errorMsg("* Create Account Failed *\n\nEmail is alreay exist");
			AuthServerSendManager::GetInstance()->SendError(pAuthClient, clientId, ERROR_PROTO, errorMsg);
		}
	}
}

void AuthServerRecvManager::RequestAuthenticateAnAccount()
{
	string packetInfo;

	Deserialize((char*)&(m_data[0]), m_fullLength, packetInfo);

	RequestAuthenticateAccount request;
	bool success = request.ParseFromString(packetInfo);
	if (success)
	{
		int clientId = request.clientid();
		int serverId = request.serverid();
		string email = request.email();
		string password = request.plaintextpassword();
		AuthClientInfo* pAuthClient = m_pAuthServer->GetClient(serverId);

		string result;
		sUserInfo userInfo;
		bool isPasswordRight = LoginDB::GetInstance()->CheckPassword(email, password, result, userInfo);
		if (isPasswordRight)
		{
			AuthServerSendManager::GetInstance()->SendAuthenticateSuccessResponse(pAuthClient, clientId, userInfo);
		}
		else
		{
			AuthServerSendManager::GetInstance()->SendError(pAuthClient, clientId, ERROR_PROTO, result);
		}
	}
}

void AuthServerRecvManager::RequestChangeName()
{
	string packetInfo;

	Deserialize((char*)&(m_data[0]), m_fullLength, packetInfo);

	RequestNameChangeBuf request;
	bool success = request.ParseFromString(packetInfo);
	if (success)
	{
		int clientId = request.clientid();
		int serverId = request.serverid();
		string email = request.email();
		string newName = request.newname();
		AuthClientInfo* pAuthClient = m_pAuthServer->GetClient(serverId);

		bool isNameChanged = LoginDB::GetInstance()->UpdateUserName(email, newName);
		if (isNameChanged)
		{
			AuthServerSendManager::GetInstance()->SendChangeNameSuccessResponse(pAuthClient, clientId, newName);
		}
		else
		{
			string errorMsg("* Username Change Failed *\n\nAuth Server SQL Error");
			AuthServerSendManager::GetInstance()->SendError(pAuthClient, clientId, ERROR_PROTO, errorMsg);
		}
	}
}

void AuthServerRecvManager::Deserialize(char* data, unsigned int length, string& packetInfo)
{
	Buffer buffer(length);
	memcpy(&(buffer.m_data[0]), data, length);

	unsigned int header_length = buffer.ReadInt();
	unsigned int header_messageId = buffer.ReadInt();

	int size = buffer.ReadInt();
	packetInfo = buffer.ReadString(size);
}