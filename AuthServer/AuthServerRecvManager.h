#ifndef _AUTHSERVERRECVMANAGER_H_
#define _AUTHSERVERRECVMANAGER_H_

#include "Define.h"

class AuthServer;
class AuthClientInfo;
class AuthServerRecvManager
{
private:
	static AuthServerRecvManager*	m_pInstance;

private:
	AuthServer*						m_pAuthServer;
	std::vector<uint8_t>			m_data;
	bool							m_bNewPacket;
	uint32_t						m_fullLength;

public:
	explicit AuthServerRecvManager();
	~AuthServerRecvManager();
	static AuthServerRecvManager* GetInstance();
	void DestroyInstance();

public:
	void SetAuthServer(AuthServer* pServer) { m_pAuthServer = pServer; }

public:
	void DeserializePacket(char* rawData, int size, int rawIndex);
private:
	void AddData(char* rawData, int size, int rawIndex);
	void ProcessMessage();
	void ResetMessageStatus();
	uint32_t ReadLengthInfo();
	uint32_t ReadMessageId();
private:
	void RequestCreateNewAccount();
	void RequestAuthenticateAnAccount();
	void RequestChangeName();

private:
	void Deserialize(char* data, unsigned int length, std::string& packetInfo);
};

#endif //_AUTHSERVERRECVMANAGER_H_