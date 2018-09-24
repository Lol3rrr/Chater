#include "Server.h"

void Server::sendMessage(string message) {

	Packet messageP;
	messageP.setMessage(message);
	messageP.setID(1);
	string hash = "";
	messageP.setHash(hash);

	int iResult = messageP.sendPacket(Socket);
	if (iResult == SOCKET_ERROR) {
		printf("Sending message failed with error: %d\n", WSAGetLastError());
		closesocket(Socket);
		WSACleanup();
	}

}