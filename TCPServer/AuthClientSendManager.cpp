#include "AuthClientSendManager.h"
#include "Buffer.h"
#include "DLLPacketIncludes.h"
#include "AuthClient.h"
#include "DefineProtoBuffers.h"
#include "Server.h"

using namespace std;
AuthClientSendManager* AuthClientSendManager::m_pInstance = nullptr;
AuthClientSendManager::AuthClientSendManager()
{
}

AuthClientSendManager::~AuthClientSendManager()
{
}

AuthClientSendManager* AuthClientSendManager::GetInstance()
{
	if (nullptr == m_pInstance)
		m_pInstance = new AuthClientSendManager();
	return m_pInstance;
}

void AuthClientSendManager::DestroyInstance()
{
	if (nullptr != m_pInstance)
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}
}

void AuthClientSendManager::SendPacket(char* data, int length)
{
	int sendResult = send(m_pClient->m_socket, data, length, 0);
	if (sendResult == SOCKET_ERROR)
		m_pClient->DisconnectToServer();
}

void AuthClientSendManager::RequestCreateNewAccount(int clientId, string email, string password)
{
	if (nullptr == m_pClient)
		return;

	Buffer buffer(0);
	RequestCreateAccount request;
	request.set_requestid(CREATE_ACCOUNT);
	request.set_clientid(clientId);
	request.set_serverid(m_pClient->m_number);
	request.set_email(email);
	request.set_plaintextpassword(password);
	string serialize;
	request.SerializeToString(&serialize);

	int size = 0;
	Serialize(CREATE_ACCOUNT, serialize, buffer, size);

	SendPacket((char*)&(buffer.m_data[0]), size);
}

void AuthClientSendManager::RequestAuthenticateAnAccount(int clientId, std::string email, std::string password)
{
	if (nullptr == m_pClient)
		return;

	Buffer buffer(0);
	RequestAuthenticateAccount request;
	request.set_requestid(LOG_IN);
	request.set_clientid(clientId);
	request.set_serverid(m_pClient->m_number);
	request.set_email(email);
	request.set_plaintextpassword(password);
	string serialize;
	request.SerializeToString(&serialize);

	int size = 0;
	Serialize(LOG_IN, serialize, buffer, size);

	SendPacket((char*)&(buffer.m_data[0]), size);
}

void AuthClientSendManager::RequestNameChange(int clientId, std::string email, std::string newName)
{
	if (nullptr == m_pClient)
		return;

	Buffer buffer(0);
	RequestNameChangeBuf request;
	request.set_requestid(CHANGE_NAME);
	request.set_clientid(clientId);
	request.set_serverid(0);
	request.set_email(email);
	request.set_newname(newName);
	string serialize;
	request.SerializeToString(&serialize);

	int size = 0;
	Serialize(CHANGE_NAME, serialize, buffer, size);

	SendPacket((char*)&(buffer.m_data[0]), size);
}

void AuthClientSendManager::Serialize(unsigned int messageId, string packetInfo, Buffer& buffer, int& size)
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