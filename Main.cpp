#pragma once

#include <thread>

#include "Server.h"

Server server;

thread serverThread;
thread updateThread;

int main() {

	serverThread = thread(&Server::update, &server);
	updateThread = thread(&Server::keepUptoDate, &server);

	while (true) {
		string t;
		getline(cin, t);
		cout << endl;

		server.sendMessage(t);
	}

	return 0;
}