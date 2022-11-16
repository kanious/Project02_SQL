#ifndef _AUTHSERVERSENDMANAGER_H_
#define _AUTHSERVERSENDMANAGER_H_

#include "DLLStruct.h"
#include "AuthClientInfo.h"

class Buffer;
class AuthServer;
class AuthClientInfo;
class AuthServerSendManager
{
private:
	static AuthServerSendManager*	m_pInstance;

private:
	AuthServer*						m_pAuthServer;

public:
	explicit AuthServerSendManager();
	~AuthServerSendManager();
	static AuthServerSendManager* GetInstance();
	void DestroyInstance();

public:
	void SetAuthServer(AuthServer* pServer) { m_pAuthServer = pServer; }

public:
	void SendPacket(AuthClientInfo* pClient, char* data, int length);
	void AcceptClient(AuthClientInfo* pClient);
	void SendError(AuthClientInfo* pClient, int clientId, MessageType type, std::string errorMsg);
	void SendCreateSuccessResponse(AuthClientInfo* pClient, int clientId, sUserInfo userInfo);
	void SendAuthenticateSuccessResponse(AuthClientInfo* pClient, int clientId, sUserInfo userInfo);
	void SendChangeNameSuccessResponse(AuthClientInfo* pClient, int clientId, std::string newName);

private:
	void Serialize(unsigned int messageId, std::string packetInfo, Buffer& buffer, int& size);
};

#endif //_SERVERSENDMANAGER_H_