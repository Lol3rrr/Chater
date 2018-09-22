#include "Server.h"

void Server::getChatRoom(string chatRoom, string list[3]) {

	Packet messageP;

	messageP.setID(0);
	string hash = "";
	messageP.setHash(hash);
	string roomMessage = "Room:" + chatRoom + ";";
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

	int iReceive = recv(Socket, buffer, 1024, 0);

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