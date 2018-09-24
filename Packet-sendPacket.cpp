#include "Packet.h"

int Packet::sendPacket(SOCKET socket) {
	int result = -1;

	string sendMessage = this->toString();
	result = send(socket, sendMessage.c_str(), 1024, 0);

	return result;
}