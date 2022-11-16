#include "ClientRecvManager.h"
#include "Client.h"
#include "GUIManager.h"
#include "DLLPacketIncludes.h"
#include "Buffer.h"
#include "DefineProtoBuffers.h"
#include <sstream>

using namespace std;
ClientRecvManager* ClientRecvManager::m_pInstance = nullptr;
ClientRecvManager::ClientRecvManager()
{
	m_pClient = nullptr;
	m_data.clear();
	m_bNewPacket = true;
	m_fullLength = 0;
	m_pGUIManager = GUIManager::GetInstance();
}

ClientRecvManager::~ClientRecvManager()
{
}

ClientRecvManager* ClientRecvManager::GetInstance()
{
	if (nullptr == m_pInstance)
		m_pInstance = new ClientRecvManager();
	return m_pInstance;
}

void ClientRecvManager::DestroyInstance()
{
	if (nullptr != m_pInstance)
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}
}

void ClientRecvManager::DeserializePacket(char* rawData, int size, int rawIndex)
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

void ClientRecvManager::AddData(char* rawData, int size, int rawIndex)
{
	int prevIndex = m_data.size();
	m_data.resize(size + m_data.size());
	memcpy(&(m_data[prevIndex]), &(rawData[rawIndex]), size);
}

void ClientRecvManager::ProcessMessage()
{
	MessageType type = (MessageType)ReadMessageId();

	switch (type)
	{
	case CONNECT:					ResponseConnect();				break;
	case ERROR_MSG:					ResponseErrorMessage();			break;
	case SEND_MSG:					ResponseRecvMessage();			break;
	case MAKE_CHANNEL:				ResponseMakeChannel();			break;
	case DELETE_CHANNEL:			ResponseDeleteChannel();		break;
	case JOIN_CHANNEL:				ResponseJoinChannel();			break;
	case LEAVE_CHANNEL:				ResponseLeaveChannel();			break;
	case DISCONNECT:				ResponseDisconnect();			break;
	case CHANGE_NAME_BROADCAST:		ResponseChangeNameBroadcast();	break;
	case CHANGE_NAME:				ResponseChangeName();			break;
	case ERROR_PROTO:				ResponseErrorProto();			break;
	case CREATE_ACCOUNT:			ResponseCreateNewAccount();		break;
	case LOG_IN:					ResponseLogIn();				break;
	case LOG_IN_INFO:				ResponseLogInInfo();			break;
	}
}

void ClientRecvManager::ResetMessageStatus()
{
	m_fullLength = 0;
	m_data.clear();
	m_bNewPacket = true;
}

uint32_t ClientRecvManager::ReadLengthInfo()
{
	uint32_t value = 0;
	value = m_data[3];
	value |= m_data[2] << 8;
	value |= m_data[1] << 16;
	value |= m_data[0] << 24;
	return value;
}

uint32_t ClientRecvManager::ReadMessageId()
{
	uint32_t value = 0;
	value = m_data[7];
	value |= m_data[6] << 8;
	value |= m_data[5] << 16;
	value |= m_data[4] << 24;
	return value;
}

void ClientRecvManager::ResponseConnect()
{
	m_pGUIManager->SetAuthAccountWindow(true);

	pResponseMessage packet;
	packet.Deserialize((char*)&(m_data[0]), m_fullLength);
	if (nullptr != m_pClient)
		m_pClient->m_number = packet.clientId;
}

void ClientRecvManager::ResponseErrorMessage()
{
	pResponseError packet;
	packet.Deserialize((char*)&(m_data[0]), m_fullLength);
	m_pGUIManager->AddConvo(packet.clientId, packet.channelName, packet.clientName, packet.errorMsg);
}

void ClientRecvManager::ResponseRecvMessage()
{
	pResponseMessage packet;
	packet.Deserialize((char*)&(m_data[0]), m_fullLength);
	m_pGUIManager->AddConvo(packet.clientId, packet.channelName, packet.clientName, packet.message);
}

void ClientRecvManager::ResponseMakeChannel()
{
	pResponseChannel packet;
	packet.Deserialize((char*)&(m_data[0]), m_fullLength);
	for (int i = 0; i < packet.vecAllChannels.size(); ++i)
		m_pGUIManager->AddAllChannelList(packet.vecAllChannels[i]);
	for (int i = 0; i < packet.vecJoinedChannels.size(); ++i)
		m_pGUIManager->UpdateJoinedChannelMap(packet.vecJoinedChannels[i]);
}

void ClientRecvManager::ResponseDeleteChannel()
{
	pResponseChannel packet;
	packet.Deserialize((char*)&(m_data[0]), m_fullLength);
	m_pGUIManager->RemoveFromAllChannel(packet.channelName);
}

void ClientRecvManager::ResponseJoinChannel()
{
	pResponseChannel packet;
	packet.Deserialize((char*)&(m_data[0]), m_fullLength);
	for (int i = 0; i < packet.vecJoinedChannels.size(); ++i)
		m_pGUIManager->UpdateJoinedChannelMap(packet.vecJoinedChannels[i]);
}

void ClientRecvManager::ResponseLeaveChannel()
{
	pResponseChannel packet;
	packet.Deserialize((char*)&(m_data[0]), m_fullLength);
	for (int i = 0; i < packet.vecJoinedChannels.size(); ++i)
	{
		ChannelInfo info = packet.vecJoinedChannels[i];
		bool isJoined = false;
		list<string>::iterator iter;
		for (iter = info.listClient.begin(); iter != info.listClient.end(); ++iter)
		{
			if (*iter == m_pClient->m_myInfo.username)
			{
				isJoined = true;
				break;
			}
		}
		if (isJoined)
			m_pGUIManager->UpdateJoinedChannelMap(packet.vecJoinedChannels[i]);
		else
			m_pGUIManager->RemoveJoinedChannel(info.name);
	}
}

void ClientRecvManager::ResponseDisconnect()
{
	if (nullptr != m_pClient)
		m_pClient->DisconnectToServer();

	m_pGUIManager->InitAllInformation();
}

void ClientRecvManager::ResponseChangeNameBroadcast()
{
	if (nullptr == m_pClient)
		return;

	pResponseChannel packet;
	packet.Deserialize((char*)&(m_data[0]), m_fullLength);
	m_pClient->m_myInfo.username = packet.clientName;
	for (int i = 0; i < packet.vecJoinedChannels.size(); ++i)
		m_pGUIManager->UpdateJoinedChannelMap(packet.vecJoinedChannels[i]);

	m_pGUIManager->UpdateSystemChannel(m_pClient->m_myInfo.username);
}

void ClientRecvManager::ResponseErrorProto()
{
	string packetInfo;
	Deserialize((char*)&(m_data[0]), m_fullLength, packetInfo);

	ResponseError error;
	bool success = error.ParseFromString(packetInfo);
	if (success)
	{
		string msg = error.errmessage();

		m_pGUIManager->SetConfirmPopup(true, msg);
		m_pGUIManager->SetNetwork(false);
	}
}

void ClientRecvManager::ResponseCreateNewAccount()
{
	string packetInfo;

	Deserialize((char*)&(m_data[0]), m_fullLength, packetInfo);

	ResponseCreateAccount response;
	bool success = response.ParseFromString(packetInfo);
	if (success)
	{
		int64_t userId = response.userid();
		string email = response.email();
		string username = response.username();
		string lastlogin = response.lastlogin();
		string creationdate = response.creationdate();

		stringstream ss;
		ss << "Your account is created successfully!\n\n";
		ss << "User ID : " << userId << "\n";
		ss << "User Name : " << username << "\n";
		ss << "Last Login : " << lastlogin << "\n";
		ss << "Creation Date : " << creationdate << "\n\n";
		ss << "Please Log in 1 more time. Thank you.";

		m_pGUIManager->SetConfirmPopup(true, ss.str());
		m_pGUIManager->SetNetwork(false);
		m_pGUIManager->ClearConfirmPopupText(false, true);
	}
}

void ClientRecvManager::ResponseLogIn()
{
	string packetInfo;

	Deserialize((char*)&(m_data[0]), m_fullLength, packetInfo);

	ResponseAuthenticateAccount response;
	bool success = response.ParseFromString(packetInfo);
	if (success)
	{
		if (nullptr != m_pClient)
		{
			m_pClient->m_myInfo.userId = response.userid();
			m_pClient->m_myInfo.email = response.email();;
			m_pClient->m_myInfo.username = response.username();
			m_pClient->m_myInfo.lastlogin = response.lastlogin();
			m_pClient->m_myInfo.creationdate = response.creationdate();
		}

		m_pGUIManager->SetNetwork(false);
		m_pGUIManager->ClearConfirmPopupText(true, true);
		m_pGUIManager->SetAuthAccountWindow(false);
	}
}

void ClientRecvManager::ResponseLogInInfo()
{
	pResponseConnect packet;
	packet.Deserialize((char*)&(m_data[0]), m_fullLength);

	for (int i = 0; i < packet.vecAllChannels.size(); ++i)
		m_pGUIManager->AddAllChannelList(packet.vecAllChannels[i]);
	for (int i = 0; i < packet.vecJoinedChannels.size(); ++i)
		m_pGUIManager->UpdateJoinedChannelMap(packet.vecJoinedChannels[i]);
}

void ClientRecvManager::ResponseChangeName()
{
	string packetInfo;

	Deserialize((char*)&(m_data[0]), m_fullLength, packetInfo);

	ResponseNameChangeBuf response;
	bool success = response.ParseFromString(packetInfo);
	if (success)
	{
		if (nullptr != m_pClient)
		{
			m_pClient->m_myInfo.username = response.newname();
			m_pGUIManager->UpdateSystemChannel(response.newname());
		}
	}
}

void ClientRecvManager::Deserialize(char* data, unsigned int length, string& packetInfo)
{
	Buffer buffer(length);
	memcpy(&(buffer.m_data[0]), data, length);

	unsigned int header_length = buffer.ReadInt();
	unsigned int header_messageId = buffer.ReadInt();

	int size = buffer.ReadInt();
	packetInfo = buffer.ReadString(size);
}