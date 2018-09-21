#include "Server.h"

void Server::keepUptoDate() {

	Packet nullPacket;
	nullPacket.setID(-1);
	nullPacket.setHash("");
	nullPacket.setMessage("");

	int failed = 0;

	while (true) {
		string message = nullPacket.toString();
		int sent = send(Socket, message.c_str(), 1024, 0);

		if (sent == SOCKET_ERROR) {
			failed += 1;

			cout << "Sent: " << sent << endl;



			// Create a SOCKET for connecting to server
			Socket = socket(ptr->ai_family, ptr->ai_socktype,
				ptr->ai_protocol);
			if (Socket == INVALID_SOCKET) {
				//printf("socket failed with error: %ld\n", WSAGetLastError());
				WSACleanup();
			}

			// Connect to server.
			int iResult = connect(Socket, ptr->ai_addr, (int)ptr->ai_addrlen);
			if (iResult == SOCKET_ERROR) {
				closesocket(Socket);
				Socket = INVALID_SOCKET;
				continue;
			}

			Sleep(500);
		}
		else {
			failed = 0;
		}

		if (failed >= 3) {
		}

		Sleep(100);
	}

}