#include "Packet.h"

Packet Packet::receivePacket(SOCKET socket) {
	Packet packet;

	char buffer[1024];
	int result = recv(socket, buffer, 1024, 0);

	packet.createByMessage(buffer);

	packet.decrypt();

	return packet;
}