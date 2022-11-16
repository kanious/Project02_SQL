#ifndef _SERVERSENDMANAGER_H_
#define _SERVERSENDMANAGER_H_

#include "Define.h"

class Server;
class ClientInfo;
class ServerSendManager
{
private:
	static ServerSendManager*	m_pInstance;

private:
	Server*						m_pServer;

public:
	explicit ServerSendManager();
	~ServerSendManager();
	static ServerSendManager* GetInstance();
	void DestroyInstance();

public:
	void SetServer(Server* pServer) { m_pServer = pServer; }

public:
	void SendPacket(ClientInfo* pClient, char* data, int length);
	void AcceptClient(ClientInfo* pClient);
	void SendErrorMessageToClient(ClientInfo* pClient, std::string errMsg);
	void SendMessageToClient(ClientInfo* pClient, char* data, unsigned int length);
	void BroadcastMessageToClients(char* data, unsigned int length);
	void SendSystemMessageToClient(ClientInfo* pClient, std::string message);
	void BroadcastChannelMakeMessage(std::string channelName);
	void BroadcastChannelDeleteMessage(std::string channelName);
	void BroadcastChannelJoinMessage(std::string channelName);
	void BroadcastChannelLeaveMessage(ClientInfo* pClient, std::string channelName);
	void SendDisconnectResponse(ClientInfo* pClient);
	void BroadcastChannelUpdateMessage(std::string channelName);

public:
	void SendProtoErrMsg(ClientInfo* pClient, int serverId, int errorId, std::string msg);
	void SendCreateAccountResponse(ClientInfo* pClient, std::string packetInfo);
	void SendAuthenticateResponse(ClientInfo* pClient, std::string packetInfo);
	void SendLogInInfo(ClientInfo* pClient);
	void SendNameChange(ClientInfo* pClient, std::string newName);

private:
	void Serialize(unsigned int messageId, std::string packetInfo, Buffer& buffer, int& size);
};

#endif //_SERVERSENDMANAGER_H_