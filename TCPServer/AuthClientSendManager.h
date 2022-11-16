#ifndef _AUTHCLIENTSENDMANAGER_H_
#define _AUTHCLIENTSENDMANAGER_H_

#include "Define.h"

class Buffer;
class AuthClient;
class Server;

class AuthClientSendManager
{
private:
	static AuthClientSendManager* m_pInstance;

private:
	AuthClient*		m_pClient;
	Server*			m_pServer;

public:
	explicit AuthClientSendManager();
	~AuthClientSendManager();
	static AuthClientSendManager* GetInstance();
	void DestroyInstance();

public:
	void SetClient(AuthClient* pClient) { m_pClient = pClient; }
	void SetServer(Server* pServer)		{ m_pServer = pServer; }

public:
	void SendPacket(char* data, int length);
public:
	void RequestCreateNewAccount(int clientId, std::string email, std::string password);
	void RequestAuthenticateAnAccount(int clientId, std::string email, std::string password);
	void RequestNameChange(int clientId, std::string email, std::string newName);

private:
	void Serialize(unsigned int messageId, std::string packetInfo, Buffer& buffer, int& size);
};

#endif //_AUTHCLIENTSENDMANAGER_H_