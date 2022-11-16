#ifndef _AUTHCLIENTRECVMANAGER_H_
#define _AUTHCLIENTRECVMANAGER_H_

#include "Define.h"

class AuthClient;
class Server;

class AuthClientRecvManager
{
private:
	static AuthClientRecvManager* m_pInstance;

private:
	AuthClient*					m_pClient;
	Server*						m_pServer;

	std::vector<uint8_t>		m_data;
	bool						m_bNewPacket;
	uint32_t					m_fullLength;

public:
	explicit AuthClientRecvManager();
	~AuthClientRecvManager();
	static AuthClientRecvManager* GetInstance();
	void DestroyInstance();

public:
	void SetClient(AuthClient* pClient) { m_pClient = pClient; }
	void SetServer(Server* pServer)		{ m_pServer = pServer; }

public:
	void DeserializePacket(char*, int, int);
private:
	void AddData(char*, int, int);
	void ProcessMessage();
	void ResetMessageStatus();
	uint32_t ReadLengthInfo();
	uint32_t ReadMessageId();
private:
	void ResponseConnect();
	void ResponseCreateNewAccount();
	void ResponseAuthenticateAnAccount();
	void ResponseChangeNameBroadcast();
	void ResponseErrorMsg();

private:
	void Deserialize(char* data, unsigned int length, std::string& packetInfo);
};

#endif //_AUTHCLIENTRECVMANAGER_H_