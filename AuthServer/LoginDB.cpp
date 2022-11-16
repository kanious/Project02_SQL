#include "LoginDB.h"
#include "jdbc/mysql_driver.h"
#include "jdbc/mysql_connection.h"
#include "jdbc/mysql_error.h"
#include "jdbc/cppconn/statement.h"
#include "jdbc/cppconn/prepared_statement.h"
#include "jdbc/cppconn/resultset.h"
#include "bcrypt\bcrypt.h"
#include "bcrypt\BCrypt.hpp"
#include "StaticFunc.h"
#include <sstream>
#include <Rpc.h>
#pragma comment(lib, "Rpcrt4.lib")

using namespace sql;
using namespace std;

LoginDB* LoginDB::m_pInstance = nullptr;
LoginDB::LoginDB()
	: m_pDriver(nullptr), m_pConnection(nullptr), m_pResultSet(nullptr)
	, m_pStatement(nullptr), m_pSELECT_Email_FromAuth(nullptr) , m_pSELECT_UserInfo_FromUser(nullptr)
	, m_pINSERT_User(nullptr), m_pINSERT_Auth(nullptr), m_pUPDATE_User_login(nullptr)
	, m_pUPDATE_User_username(nullptr)
{
}

LoginDB::~LoginDB()
{
}

LoginDB* LoginDB::GetInstance()
{
	if (nullptr == m_pInstance)
		m_pInstance = new LoginDB();
	return m_pInstance;
}

void LoginDB::DestroyInstance()
{
	Disconnect();

	if (nullptr != m_pInstance)
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}
}

bool LoginDB::Connect(string hostName, string userName, string password)
{
	//Get.Driver
	printf("  Get Driver . . . ");
	try
	{
		m_pDriver = mysql::get_driver_instance();
	}
	catch (SQLException e)
	{
		cout << "falied: " << e.what() << endl;
		return false;
	}
	if (nullptr == m_pDriver) return false;
	printf("OK!\n");

	//Connect.To.SQL
	printf("  Connect To SQL . . . ");
	try
	{
 		m_pConnection = m_pDriver->connect(hostName, userName, password);
		if (nullptr == m_pConnection)
		{
			cout << "failed" << endl;
			return false;
		}
		m_pConnection->setSchema("authentication_service");
	}
	catch (SQLException e)
	{
		cout << "falied: " << e.what() << endl;
		return false;
	}
	printf("OK!\n");

	//Setting.SQL.instances
	printf("  Preparing SQL Query . . . ");
	try
	{
		m_pStatement = m_pConnection->createStatement();
		stringstream query;
		query << "SELECT * FROM `authentication_service`.`web_auth`";
		query << " WHERE email=?";
		m_pSELECT_Email_FromAuth = m_pConnection->prepareStatement(query.str());

		query.str("");
		query << "SELECT * FROM `authentication_service`.`user`";
		query << " WHERE email=?";
		m_pSELECT_UserInfo_FromUser = m_pConnection->prepareStatement(query.str());

		query.str("");
		query << "INSERT INTO `authentication_service`.`user`";
		query << " (`username`, `email`, `last_login`, `creation_date`)";
		query << " VALUES (?, ?, now(), now());";
		m_pINSERT_User = m_pConnection->prepareStatement(query.str());

		query.str("");
		query << "INSERT INTO `authentication_service`.`web_auth`";
		query << " (`email`, `salt`, `hashed_password`, `user_id`)";
		query << " VALUES (?, ?, ?, ?);";
		m_pINSERT_Auth = m_pConnection->prepareStatement(query.str());

		query.str("");
		query << "UPDATE `authentication_service`.`user`";
		query << " SET `last_login`=now()";
		query << " WHERE email=?;";
		m_pUPDATE_User_login = m_pConnection->prepareStatement(query.str());

		query.str("");
		query << "UPDATE `authentication_service`.`user`";
		query << " SET `username`=?";
		query << " WHERE email=?;";
		m_pUPDATE_User_username = m_pConnection->prepareStatement(query.str());
	}
	catch (SQLException e)
	{
		cout << "falied: " << e.what() << endl;
		return false;
	}
	printf("OK!\n\n\n");

	return true;
}

void LoginDB::Disconnect()
{
	printf("  Disconnect SQL . . . ");
	try
	{
		if (nullptr != m_pConnection)
		{
			m_pConnection->close();
			m_pConnection = nullptr;
		}
	}
	catch (SQLException e)
	{
		cout << "falied: " << e.what() << endl;
		return;
	}

	SafeDelete(m_pResultSet);
	SafeDelete(m_pStatement);
	SafeDelete(m_pSELECT_Email_FromAuth);
	SafeDelete(m_pSELECT_UserInfo_FromUser);
	SafeDelete(m_pINSERT_User);
	SafeDelete(m_pINSERT_Auth);
	SafeDelete(m_pUPDATE_User_login);
	SafeDelete(m_pUPDATE_User_username);

	printf("OK!\n");
}

bool LoginDB::EmailCheckFromAuthTable(string email)
{
	m_pSELECT_Email_FromAuth->setString(1, email);

	try
	{
		m_pResultSet = m_pSELECT_Email_FromAuth->executeQuery();
	}
	catch (SQLException e)
	{
		cout << endl << "Email Check falied: " << e.what() << endl;
		return false;
	}

	if (0 == m_pResultSet->rowsCount())
		return true;

	return false;
}

bool LoginDB::AddUser(string email, string plainPassword, string& result, sUserInfo& userInfo)
{
	if (!CheckInputs(email, plainPassword, result))
	{
		return false;
	}

	m_pINSERT_User->setString(1, email);
	m_pINSERT_User->setString(2, email);

	try
	{
		m_pINSERT_User->execute();
	}
	catch (SQLException e)
	{
		cout << e.what() << endl;
		result = "* Create Account Failed *\n\nAuth Server SQL Error";
		return false;
	}

	cout << "Insert User Success" << endl;
	if (GetUserIdFromUserTable(email, userInfo))
	{
		// Add Auth Information
		UUID uuid;
		RPC_STATUS ret_val = ::I_UuidCreate(&uuid);
		wchar_t* wUuid = NULL;
		if (ret_val == RPC_S_OK)
			::UuidToStringW(&uuid, (RPC_WSTR*)&wUuid);
		wstring ws(wUuid);
		string salt(ws.begin(), ws.end());
		//string salt;
		string salt_password = salt + plainPassword;
		string hashedPassword = bcrypt::generateHash(salt_password, 12);

		if (AddAuthInfo(email, salt, hashedPassword, userInfo.userId))
		{
			return true;
		}
	}

	result = "* Create Account Failed *\n\nAuth Server SQL Error";
	return false;
}

bool LoginDB::GetUserIdFromUserTable(string email, sUserInfo& userInfo)
{
	m_pSELECT_UserInfo_FromUser->setString(1, email);

	try
	{
		m_pResultSet = m_pSELECT_UserInfo_FromUser->executeQuery();
	}
	catch (SQLException e)
	{
		cout << e.what() << endl;
		return false;
	}

	if (0 >= m_pResultSet->rowsCount())
	{
		return false;
	}

	m_pResultSet->next();
	userInfo.userId = m_pResultSet->getInt64("id");
	userInfo.email = m_pResultSet->getString("email");
	userInfo.username = m_pResultSet->getString("username");
	userInfo.lastlogin = m_pResultSet->getString("last_login");
	userInfo.creationdate = m_pResultSet->getString("creation_date");

	return true;
}

bool LoginDB::AddAuthInfo(string email, string salt, string hashedpass, int64_t userId)
{
	m_pINSERT_Auth->setString(1, email);
	m_pINSERT_Auth->setString(2, salt);
	m_pINSERT_Auth->setString(3, hashedpass);
	m_pINSERT_Auth->setInt64(4, userId);

	try
	{
		m_pINSERT_Auth->execute();
	}
	catch (SQLException e)
	{
		cout << e.what() << endl;
		return false;
	}

	return true;
}

bool LoginDB::CheckPassword(string email, string plainPassword, string& result, sUserInfo& userInfo)
{
	m_pSELECT_Email_FromAuth->setString(1, email);

	try
	{
		m_pResultSet = m_pSELECT_Email_FromAuth->executeQuery();
	}
	catch (SQLException e)
	{
		cout << e.what() << endl;
		result = "* Finding Account Failed *\n\nAuth Server SQL Error";
		return false;
	}


	if (0 >= m_pResultSet->rowsCount())
	{
		result = "* Finding Account Failed *\n\nCannot find your email id.";
		return false;
	}
	m_pResultSet->next();
	string salt = m_pResultSet->getString("salt");;
	string hashedPassword = m_pResultSet->getString("hashed_password");
	string inputPassword = salt + plainPassword;
	bool isSame = bcrypt::validatePassword(inputPassword, hashedPassword);
	if (isSame)
	{
		if (UpdateLastLogin(email))
		{
			m_pSELECT_UserInfo_FromUser->setString(1, email);
			try
			{
				m_pResultSet = m_pSELECT_UserInfo_FromUser->executeQuery();
			}
			catch (SQLException e)
			{
				cout << e.what() << endl;
				result = "* Finding Account Failed *\n\nAuth Server SQL Error";
				return false;
			}
			if (0 >= m_pResultSet->rowsCount())
			{
				result = "* Finding Account Failed *\n\nCannot find your email id.";
				return false;
			}
			m_pResultSet->next();
			userInfo.userId = m_pResultSet->getInt64("id");
			userInfo.email = m_pResultSet->getString("email");
			userInfo.username = m_pResultSet->getString("username");
			userInfo.lastlogin = m_pResultSet->getString("last_login");
			userInfo.creationdate = m_pResultSet->getString("creation_date");

			return true;
		}
		else
		{
			result = "* Finding Account Failed *\n\nAuth Server SQL Error";
			return false;
		}
	}

	result = "* Password Error *\n\nPassword is not matched.";
	return false;
}

bool LoginDB::UpdateLastLogin(string email)
{
	m_pUPDATE_User_login->setString(1, email);

	try
	{
		m_pUPDATE_User_login->execute();
	}
	catch (SQLException e)
	{
		cout << e.what() << endl;
		return false;
	}

	return true;
}

bool LoginDB::UpdateUserName(std::string email, std::string newName)
{
	m_pUPDATE_User_username->setString(1, newName);
	m_pUPDATE_User_username->setString(2, email);

	try
	{
		m_pUPDATE_User_username->execute();
	}
	catch (SQLException e)
	{
		cout << e.what() << endl;
		return false;
	}

	return true;
}

bool LoginDB::CheckInputs(string email, string password, string& result)
{
	size_t pos1 = email.find('@');
	size_t pos2 = email.find('.');
	if (pos1 == string::npos || pos2 == string::npos)
	{
		result = "* Format Error *\n\nThe email id does not match the mail format.\nPlease enter a valid email.";
		return false;
	}

	if (password.length() < 8 || password.length() > 20)
	{
		result = " * Password Error *\n\nThe password is too short or long.\nPlease enter a password between 8 and 20 characters.";
		return false;
	}

	return true;
}
