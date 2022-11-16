#include "AuthServerSendManager.h"
#include "Buffer.h"
#include "DLLPacketIncludes.h"
#include "AuthClientInfo.h"
#include "AuthServer.h"
#include "DefineProtoBuffers.h"

using namespace std;
AuthServerSendManager* AuthServerSendManager::m_pInstance = nullptr;
AuthServerSendManager::AuthServerSendManager()
{
	m_pAuthServer = nullptr;
}

AuthServerSendManager::~AuthServerSendManager()
{
}

AuthServerSendManager* AuthServerSendManager::GetInstance()
{
	if (nullptr == m_pInstance)
		m_pInstance = new AuthServerSendManager();
	return m_pInstance;
}

void AuthServerSendManager::DestroyInstance()
{
	if (nullptr != m_pInstance)
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}
}

void AuthServerSendManager::SendPacket(AuthClientInfo* pClient, char* data, int length)
{
	int sendResult = send(pClient->m_socket, data, length, 0);
	if (sendResult == SOCKET_ERROR)
		pClient->m_bConnected = false;
}

void AuthServerSendManager::AcceptClient(AuthClientInfo* pClient)
{
	Buffer buffer(0);
	pResponseMessage response;
	response.m_header.messageId = CONNECT;
	response.clientId = pClient->m_number;
	response.Serialize(buffer);

	SendPacket(pClient, (char*)&(buffer.m_data[0]), response.m_header.length);
}

void AuthServerSendManager::SendError(AuthClientInfo* pClient, int clientId, MessageType type, string errorMsg)
{
	if (nullptr == pClient)
		return;

	Buffer buffer(0);
	ResponseError error;
	error.set_requestid(ERROR_PROTO);
	error.set_clientid(clientId);
	error.set_serverid(pClient->m_number);
	error.set_errorid(type);
	error.set_errmessage(errorMsg);
	string serialize;
	error.SerializeToString(&serialize);

	int size = 0;
	Serialize(ERROR_PROTO, serialize, buffer, size);
	SendPacket(pClient, (char*)&(buffer.m_data[0]), size);
}

void AuthServerSendManager::SendCreateSuccessResponse(AuthClientInfo* pClient, int clientId, sUserInfo userInfo)
{
	if (nullptr == pClient)
		return;

	Buffer buffer(0);
	ResponseCreateAccount response;
	response.set_requestid(CREATE_ACCOUNT);
	response.set_clientid(clientId);
	response.set_serverid(pClient->m_number);
	response.set_userid(userInfo.userId);
	response.set_email(userInfo.email);
	response.set_username(userInfo.username);
	response.set_lastlogin(userInfo.lastlogin);
	response.set_creationdate(userInfo.creationdate);
	string serialize;
	response.SerializeToString(&serialize);

	int size = 0;
	Serialize(CREATE_ACCOUNT, serialize, buffer, size);
	SendPacket(pClient, (char*)&(buffer.m_data[0]), size);
}

void AuthServerSendManager::SendAuthenticateSuccessResponse(AuthClientInfo* pClient, int clientId, sUserInfo userInfo)
{
	if (nullptr == pClient)
		return;

	Buffer buffer(0);
	ResponseAuthenticateAccount response;
	response.set_requestid(LOG_IN);
	response.set_clientid(clientId);
	response.set_serverid(pClient->m_number);
	response.set_userid(userInfo.userId);
	response.set_email(userInfo.email);
	response.set_username(userInfo.username);
	response.set_lastlogin(userInfo.lastlogin);
	response.set_creationdate(userInfo.creationdate);
	string serialize;
	response.SerializeToString(&serialize);

	int size = 0;
	Serialize(LOG_IN, serialize, buffer, size);
	SendPacket(pClient, (char*)&(buffer.m_data[0]), size);
}

void AuthServerSendManager::SendChangeNameSuccessResponse(AuthClientInfo* pClient, int clientId, string newName)
{
	if (nullptr == pClient)
		return;

	Buffer buffer(0);
	ResponseNameChangeBuf response;
	response.set_requestid(CHANGE_NAME);
	response.set_clientid(clientId);
	response.set_serverid(pClient->m_number);
	response.set_newname(newName);
	string serialize;
	response.SerializeToString(&serialize);

	int size = 0;
	Serialize(CHANGE_NAME, serialize, buffer, size);
	SendPacket(pClient, (char*)&(buffer.m_data[0]), size);
}



void AuthServerSendManager::Serialize(unsigned int messageId, string packetInfo, Buffer& buffer, int& size)
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