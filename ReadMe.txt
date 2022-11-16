- How to build and run the project.
  There are 4 projects.
  1) PacketDLL : Has buffer and all request/response packet information, DLL project. 
  2) TCPServer : Chat server program.
  3) Client : Chat user program.
  4) AuthServer : Login server connected with SQL

  This project can be run with Debug, Release mode in x64 build except AuthServer.
  * AuthServer * must be run with Release mode due to SQL connection.
  I uploaded all execution files in GitHub. You can run two servers / multi clients with them. (Root Folder > x64 > Debug/Release folder)


- Description
  When you run the client for the first time, no information will be displayed because it isn't connected to the server yet.
  When you connect to chat server with /connect command, you can see a popup window to handle account information.
  Description of popup window is in UI Format2.png file. (UI Format1.png is same with project 1 version.)
  Demo video with detailed description is on Youtube link.

- SQL data file:
root/LoginDB.zip

- GitHub Link:
https://github.com/kanious/Project02_SQL

- Video Link:
https://youtu.be/alfd38AOwa8


** If you are using a bitdefender, it sometimes catches execution files as viruses.
   Please exclude the path of the project folder from the antivirus scanning.


- User Input Options
  When you press enter in the client window, the input text box will be focused.
  Or you can just click the input text box for writing.
  < Commands >
  1. "/connect [ip address]" : connect to server (/connect 127.0.0.1)
  2. "/disconnect" : disconnect from server
  3. "/make [channel name]" : make and automatically join to channel (/make NewChannel)
  4. "/delete [channel name]" : delete channel (only master can) (/delete NewChannel)
  5. "/join [channel name]" : join existed channel (/join NewChannel)
  6. "/leave [channel name]" : leave joined channel (/leave NewChannel)
  7. "/name [user name]" : change user name (/name John)
  8. "/quit" : disconnect from server and quit the program
  9. "[message]" : send message to the channel (without '/')
