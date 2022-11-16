#include "ClientSendManager.h"
#include "Client.h"
#include "Buffer.h"
#include "DLLPacketIncludes.h"
#include "DefineProtoBuffers.h"

using namespace std;
ClientSendManager* ClientSendManager::m_pInstance = nullptr;
ClientSendManager::ClientSendManager()
{
	m_pClient = nullptr;
}

ClientSendManager::~ClientSendManager()
{
}

ClientSendManager* ClientSendManager::GetInstance()
{
	if (nullptr == m_pInstance)
		m_pInstance = new ClientSendManager();
	return m_pInstance;
}

void ClientSendManager::DestroyInstance()
{
	if (nullptr != m_pInstance)
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}
}

void ClientSendManager::MessageParcing(string channelName, string message)
{
	if (message[0] == '/')
	{
		string token(message);
		token.erase(0, 1);
		size_t pos = token.find(' ');
		string command = token.substr(0, pos);
		token.erase(0, command.size() + 1);
		
		if ("connect" == command)
		{
			if (token.size() == 0)
				MSGBox("IP Address information is missing");
			else
			{
				RequestConnectToServer(token.c_str());
				return;
			}
		}
		else
		{
			if (!CheckServerStatus())
			{
				MSGBox("Server is not connected"); 
				return;
			}
		}

		token.erase(remove(token.begin(), token.end(), ' '), token.end());

		if ("disconnect" == command)
		{
			RequestDisconnectToServer();
		}
		else if ("make" == command)
		{
			if (token.size() == 0)
				MSGBox("Channel name is missing");

			RequestMakeChannel(token);
		}
		else if ("delete" == command)
		{
			if (token.size() == 0)
				MSGBox("Channel name is missing");

			RequestDeleteChannel(token);
		}
		else if ("join" == command)
		{
			if (token.size() == 0)
				MSGBox("Channel name is missing");

			RequestJoinChannel(token);
		}
		else if ("leave" == command)
		{
			if (token.size() == 0)
				MSGBox("Channel name is missing");

			RequestLeaveChannel(token);
		}
		else if ("quit" == command)
		{
			RequestQuit();
		}
		else if ("name" == command)
		{
			if (token.size() == 0)
				MSGBox("Name is missing");

			RequestChangeName(token);
		}
	}
	else
	{
		if (!CheckServerStatus())
		{
			MSGBox("Server is not connected");
			return;
		}

		RequestSendMessageToServer(channelName, message);
	}
}

bool ClientSendManager::CheckServerStatus()
{
	if (nullptr == m_pClient)
		return false;

	return m_pClient->GetServerStatus();
}

void ClientSendManager::SendPacket(char* data, int length)
{
	int sendResult = send(m_pClient->m_socket, data, length, 0);
	if (sendResult == SOCKET_ERROR)
		m_pClient->DisconnectToServer();
}

void ClientSendManager::RequestConnectToServer(const char* ipAddress)
{
	if (nullptr == m_pClient)
		return;

	m_pClient->ConnectToServer(ipAddress);
}

void ClientSendManager::RequestDisconnectToServer()
{
	if (nullptr == m_pClient)
		return;

	Buffer buffer(0);
	pRequestDisconnect packet;
	packet.m_header.messageId = DISCONNECT;
	packet.clientId = m_pClient->m_number;
	packet.Serialize(buffer);

	SendPacket((char*)&(buffer.m_data[0]), packet.m_header.length);
}

void ClientSendManager::RequestSendMessageToServer(string channelName, string message)
{
	if (nullptr == m_pClient)
		return;

	Buffer buffer(0);
	pRequestMessage packet;
	packet.m_header.messageId = SEND_MSG;
	packet.clientId = m_pClient->m_number;
	packet.channelName = channelName;
	packet.message = message;
	packet.Serialize(buffer);

	SendPacket((char*)&(buffer.m_data[0]), packet.m_header.length);
}

void ClientSendManager::RequestMakeChannel(string channelName)
{
	if (nullptr == m_pClient)
		return;

	Buffer buffer(0);
	pRequestChannel packet;
	packet.m_header.messageId = MAKE_CHANNEL;
	packet.clientId = m_pClient->m_number;
	packet.channelName = channelName;
	packet.Serialize(buffer);

	SendPacket((char*)&(buffer.m_data[0]), packet.m_header.length);
}

void ClientSendManager::RequestDeleteChannel(string channelName)
{
	if (nullptr == m_pClient)
		return;

	Buffer buffer(0);
	pRequestChannel packet;
	packet.m_header.messageId = DELETE_CHANNEL;
	packet.clientId = m_pClient->m_number;
	packet.channelName = channelName;
	packet.Serialize(buffer);

	SendPacket((char*)&(buffer.m_data[0]), packet.m_header.length);
}

void ClientSendManager::RequestJoinChannel(string channelName)
{
	if (nullptr == m_pClient)
		return;

	Buffer buffer(0);
	pRequestChannel packet;
	packet.m_header.messageId = JOIN_CHANNEL;
	packet.clientId = m_pClient->m_number;
	packet.channelName = channelName;
	packet.Serialize(buffer);

	SendPacket((char*)&(buffer.m_data[0]), packet.m_header.length);
}

void ClientSendManager::RequestLeaveChannel(string channelName)
{
	if (nullptr == m_pClient)
		return;

	Buffer buffer(0);
	pRequestChannel packet;
	packet.m_header.messageId = LEAVE_CHANNEL;
	packet.clientId = m_pClient->m_number;
	packet.channelName = channelName;
	packet.Serialize(buffer);

	SendPacket((char*)&(buffer.m_data[0]), packet.m_header.length);
}
void ClientSendManager::RequestChangeName(string name)
{
	if (nullptr == m_pClient)
		return;

	Buffer buffer(0);
	RequestNameChangeBuf request;
	request.set_requestid(CHANGE_NAME);
	request.set_clientid(m_pClient->m_number);
	request.set_serverid(0);
	request.set_email(m_pClient->m_myInfo.email);
	request.set_newname(name);
	string serialize;
	request.SerializeToString(&serialize);

	int size = 0;
	Serialize(CHANGE_NAME, serialize, buffer, size);

	SendPacket((char*)&(buffer.m_data[0]), size);

	//if (nullptr == m_pClient)
	//	return;

	//Buffer buffer(0);
	//pRequestChangeName packet;
	//packet.m_header.messageId = CHANGE_NAME;
	//packet.clientId = m_pClient->m_number;
	//packet.changeName = name;
	//packet.Serialize(buffer);

	//SendPacket((char*)&(buffer.m_data[0]), packet.m_header.length);
}

void ClientSendManager::RequestQuit()
{
	RequestDisconnectToServer();

	if (nullptr == m_pClient)
		return;
	m_pClient->QuitProgram();
}

void ClientSendManager::RequestCreateNewAccount(string email, string password)
{
	if (nullptr == m_pClient)
		return;

	Buffer buffer(0);
	RequestCreateAccount request;
	request.set_requestid(CREATE_ACCOUNT);
	request.set_clientid(m_pClient->m_number);
	request.set_serverid(0);
	request.set_email(email);
	request.set_plaintextpassword(password);
	string serialize;
	request.SerializeToString(&serialize);

	int size = 0;
	Serialize(CREATE_ACCOUNT, serialize, buffer, size);

	SendPacket((char*)&(buffer.m_data[0]), size);
}

void ClientSendManager::RequestAuthenticateUserAccount(std::string email, std::string password)
{
	if (nullptr == m_pClient)
		return;

	Buffer buffer(0);
	RequestAuthenticateAccount request;
	request.set_requestid(LOG_IN);
	request.set_clientid(m_pClient->m_number);
	request.set_serverid(0);
	request.set_email(email);
	request.set_plaintextpassword(password);
	string serialize;
	request.SerializeToString(&serialize);

	int size = 0;
	Serialize(LOG_IN, serialize, buffer, size);

	SendPacket((char*)&(buffer.m_data[0]), size);
}

void ClientSendManager::Serialize(unsigned int messageId, string packetInfo, Buffer& buffer, int& size)
{
	size = sizeof(unsigned int)
		+ sizeof(unsigned int)
		+ sizeof(unsigned int)
		+ packetInfo.size();

	buffer.Resize(size);
	buffer.WriteInt(size);
	buffer.WriteInt(messageId);
	buffer.WriteInt(packetInfo.size());
	buffer.WriteString(packetInfo);
}