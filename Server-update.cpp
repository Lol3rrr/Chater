#include "Server.h"

void Server::update() {

	while (true)
	{
		Packet p;

		char* buffer = new char[1024];
		char bufferLen = 1024;

		int iResult = recv(Socket, buffer, 1024, 0);

		p.createByMessage(buffer);

		if (p.id == 1) {
			cout << p.message << endl;
		}

		Sleep(10);
	}

}