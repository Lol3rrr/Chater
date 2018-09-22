#include "Server.h"

void Server::getChatRoom(string list[3]) {

	char roomBuffer[1024];
	int iReceive = recv(Socket, roomBuffer, 1024, 0);

	Packet roomPacket;
	roomPacket.createByMessage(roomBuffer);

	string roomMessage = roomPacket.message;
	while (roomMessage.find("\n") != string::npos) {
		int lineEnd = roomMessage.find("\n");

		cout << roomMessage.substr(0, lineEnd) << endl;

		roomMessage = roomMessage.substr(lineEnd + 1);
	}

	cout << "Which Room would you like to connect to?" << endl;

	string chatRoom;
	getline(cin, chatRoom);

	Packet messageP;
	messageP.setID(0);
	string hash = "";
	messageP.setHash(hash);
	roomMessage = "Room:" + chatRoom + ";";
	messageP.setMessage(roomMessage);

	string messageStr = messageP.toString();
	int iResult = send(Socket, messageStr.c_str(), 1024, 0);
	if (iResult == SOCKET_ERROR) {
		printf("send failed with error: %d\n", WSAGetLastError());
		closesocket(Socket);
		WSACleanup();
	}

	char buffer[1024];
	char bufferLength = 1024;

	iReceive = recv(Socket, buffer, 1024, 0);

	Packet p;
	p.createByMessage(buffer);

	string rMessage = p.message;
	
	int spacerPos = rMessage.find("::");
	
	if (spacerPos != string::npos) {
		string ip = rMessage.substr(0, spacerPos);
		string port = rMessage.substr(spacerPos + 2, 5);

		list[0] = ip;
		list[1] = port;
	}
	else {
		list[2] = "error";
	}
	
}