#pragma once

#include <thread>

#include "Server.h"

Server s("31900", "128.0.120.48");

thread serverThread;
thread updateThread;

int main() {

	string list[2];

	string t;
	getline(cin, t);

	s.getChatRoom(t, list);

	cout << "Connect to: " << list[0] << " on Port: " << list[1] << endl;

	Server server((PCSTR) list[1].c_str(), (PCSTR)list[0].c_str());

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