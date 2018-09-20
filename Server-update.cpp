#include "Server.h"

void Server::update() {

	Packet nullPacket;
	this->queue[0] = nullPacket;

	while (true)
	{
		Packet p = this->queue[0];

		if (p.id == nullPacket.id) {
			char buffer[1024];
			char bufferLen = 1024;

			int iResult = recv(Socket, buffer, bufferLen, 0);

			Packet p = nullPacket;
			p.createByMessage(buffer);

			if (p.id != nullPacket.id) {
				cout << p.toString() << endl;
			}
		}
		else {
			string message = p.toString();
			int iResult = send(Socket, message.c_str(), (int)strlen(message.c_str()), 0);
			if (iResult == SOCKET_ERROR) {
				printf("send failed with error: %d\n", WSAGetLastError());
				closesocket(Socket);
				WSACleanup();
			}
			this->queue[0] = nullPacket;
		}

		Sleep(100);
	}

}