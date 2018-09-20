#include "Server.h"

void Server::keepUptoDate() {

	Packet nullPacket;
	nullPacket.setID(-1);
	nullPacket.setHash("");
	nullPacket.setMessage("");

	while (true) {
		string message = nullPacket.toString();
		send(Socket, message.c_str(), 1024, 0);

		Sleep(100);
	}

}