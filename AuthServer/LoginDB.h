#ifndef _LOGINDB_H_
#define _LOGINDB_H_

#include "DLLStruct.h"

namespace sql
{
	class Driver;
	class Connection;
	class ResultSet;
	class Statement;
	class PreparedStatement;
}

class LoginDB
{
private:
	static LoginDB* m_pInstance;
private:
	sql::Driver*				m_pDriver;
	sql::Connection*			m_pConnection;
	sql::ResultSet*				m_pResultSet;
	sql::Statement*				m_pStatement;
	sql::PreparedStatement*		m_pSELECT_Email_FromAuth;
	sql::PreparedStatement*		m_pSELECT_UserInfo_FromUser;
	sql::PreparedStatement*		m_pINSERT_User;
	sql::PreparedStatement*		m_pINSERT_Auth;
	sql::PreparedStatement*		m_pUPDATE_User_login;
	sql::PreparedStatement*		m_pUPDATE_User_username;

public:
	explicit LoginDB();
	~LoginDB();
	static LoginDB* GetInstance();
	void DestroyInstance();

public:
	bool Connect(std::string hostName, std::string userName, std::string password);
	void Disconnect();
	
public:
	bool EmailCheckFromAuthTable(std::string email);
	bool AddUser(std::string email, std::string plainPassword, std::string& result, sUserInfo& userInfo);
	bool GetUserIdFromUserTable(std::string email, sUserInfo& userInfo);
	bool AddAuthInfo(std::string email, std::string salt, std::string hashedpass, int64_t userId);
	bool CheckPassword(std::string email, std::string plainPassword, std::string& result, sUserInfo& userInfo);
	bool UpdateLastLogin(std::string email);
	bool UpdateUserName(std::string email, std::string newName);

private:
	bool CheckInputs(std::string email, std::string password, std::string& result);

private:
};

#endif //_LOGINDB_H_