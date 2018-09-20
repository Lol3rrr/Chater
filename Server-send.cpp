#include "Server.h"

void Server::sendMessage(string message) {

	Packet messageP;
	messageP.setMessage(message);
	messageP.setID(1);
	string hash = "";
	messageP.setHash(hash);

	this->queue[0] = messageP;

}