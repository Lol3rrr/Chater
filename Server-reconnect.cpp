#include "Server.h"

bool Server::reconnect(int tries) {
	bool success = false;

	cout << "Trying to reconnect to Server..." << endl;

	char testBuffer[1];
	testBuffer[0] = 'a';
	int testResult = -1;

	// Attempt to connect to an address until one succeeds
	for (int i = 0; i < tries; i++) {
		ptr = result;

		if (ptr != NULL) {
			// Create a SOCKET for connecting to server
			Socket = socket(ptr->ai_family, ptr->ai_socktype,
				ptr->ai_protocol);
			if (Socket == INVALID_SOCKET) {
				printf("socket failed with error: %ld\n", WSAGetLastError());
				WSACleanup();
			}

			// Connect to server.
			int iResult = connect(Socket, ptr->ai_addr, (int)ptr->ai_addrlen);
			if (iResult == SOCKET_ERROR) {
				closesocket(Socket);
				Socket = INVALID_SOCKET;
				continue;
			}

			testResult = send(Socket, testBuffer, 0, 0);
			if (testResult != -1) {
				success = true;
				break;
			}

			ptr = ptr->ai_next;
		}
		else {
			break;
		}

		Sleep(500);
	}

	freeaddrinfo(result);

	if (success) {
		cout << "Successfully reconnected" << endl;
	}
	else {
		cout << "Failed to reconnect" << endl;
	}

	return success;
}