#pragma once

#include <thread>

#include "Server.h"

Server s("31900", "128.0.120.48");

thread serverThread;
thread updateThread;

int main() {
	string list[3];

	s.getChatRoom(list);

	if (list[2] != "error") {
		Server server((PCSTR)list[1].c_str(), (PCSTR)list[0].c_str());

		serverThread = thread(&Server::update, &server);

		while (true) {
			string t;
			getline(cin, t);
			cout << endl;

			server.sendMessage(t);
		}
	}
	else {
		cout << "An error occured while connection to the Room" << endl;
	}

	return 0;
}