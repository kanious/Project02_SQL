#ifndef _CLIENTINFO_H_
#define _CLIENTINFO_H_

#include "Define.h"
#include "DLLStruct.h"

class ClientInfo
{
public:
	SOCKET				m_socket;
	bool				m_bConnected;
	unsigned int		m_number;
	sUserInfo			m_userInfo;

public:
	explicit ClientInfo() {}
	~ClientInfo() {}
};

#endif //_CLIENTINFO_H_