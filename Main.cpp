#pragma once

#include <thread>

#include "Server.h"

Server server;

thread serverThread;

int main() {

	serverThread = thread(&Server::update, &server);

	while (true) {
		string t;
		getline(cin, t);

		server.sendMessage(t);

		cout << "Message: " << t << endl;
	}

	return 0;
}