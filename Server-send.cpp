#include "Server.h"

void Server::sendMessage(string message) {

	Packet messageP;
	messageP.setMessage(message);
	messageP.setID(1);
	string hash = "";
	messageP.setHash(hash);

	string messageStr = messageP.toString();
	int iResult = send(Socket, messageStr.c_str(), 1024, 0);
	if (iResult == SOCKET_ERROR) {
		printf("send failed with error: %d\n", WSAGetLastError());
		closesocket(Socket);
		WSACleanup();
	}

}