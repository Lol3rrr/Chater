#include "Server.h"

void Server::update() {

	while (true)
	{
		Packet p = Packet::receivePacket(Socket);

		if (p.id == 1) {
			cout << p.message << endl;
			cout << endl;
		}
		else if (p.id == 4) {
			cout << p.message << endl;
		}

		Sleep(10);
	}

}