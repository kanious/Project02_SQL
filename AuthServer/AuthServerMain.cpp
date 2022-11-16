#include "LoginDB.h"
#include "AuthServer.h"
#include "AuthServerRecvManager.h"
#include "AuthServerSendManager.h"
#include <string>
#include <iostream>
#include <sstream>
#include <crtdbg.h>
using namespace std;

int main(int argc, char** argv)
{
	_CrtDumpMemoryLeaks();
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_DEBUG);
	//_CrtSetBreakAlloc(156);

	srand((unsigned int)time(NULL));

	AuthServer server;
	printf("Server Opening . . . \n");
	int result = server.AuthServerOpen();
	if (result != 0)
		return result;
	printf("Server Opened.\n\n");

	AuthServerRecvManager::GetInstance()->SetAuthServer(&server);
	AuthServerSendManager::GetInstance()->SetAuthServer(&server);

	cout << endl << "SQL Connecting..." << endl << endl;
	cout << "Ip address (Default:127.0.0.1) > ";
	string ipAddress;
	while (cin.get() != '\n')
	{
		cin >> ipAddress;
	}
	if ("" == ipAddress)
		ipAddress = "127.0.0.1";

	cout << "Port number (Default:3306) > ";
	string portNumber;
	while (cin.get() != '\n')
	{
		cin >> portNumber;
	}
	if ("" == portNumber)
		portNumber = "3306";

	cout << "UserName (Default:root) > ";
	string userName;
	while (cin.get() != '\n')
	{
		cin >> userName;
	}
	if ("" == userName)
		userName = "root";

	cout << "Password > ";
	string password;
	cin >> password;

	cout << endl;

	stringstream ss;
	ss << ipAddress << ":" << portNumber;
	if (!LoginDB::GetInstance()->Connect(ss.str(), userName, password))
		return 1;

	server.Select();
	server.Close();
	
	LoginDB::GetInstance()->DestroyInstance();
	return 0;
}