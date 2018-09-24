#include "Server.h"

Server::Server(PCSTR nport, PCSTR nip) {
	
	port = nport;
	ip = nip;

	// Initialize Winsock
	int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0) {
		printf("WSAStartup failed with error: %d\n", iResult);
	}

	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;

	// Resolve the server address and port
	iResult = getaddrinfo(ip, port, &hints, &result);
	if (iResult != 0) {
		printf("getaddrinfo failed with error: %d\n", iResult);
		WSACleanup();
	}

	char testBuffer[1];
	testBuffer[0] = 'a';
	int testResult = -1;

	ptr = result;

	// Create a SOCKET for connecting to server
	Socket = socket(ptr->ai_family, ptr->ai_socktype,
		ptr->ai_protocol);
	if (Socket == INVALID_SOCKET) {
		printf("socket failed with error: %ld\n", WSAGetLastError());
		WSACleanup();
	}

	// Connect to server.
	iResult = connect(Socket, ptr->ai_addr, (int)ptr->ai_addrlen);
	if (iResult == SOCKET_ERROR) {
		closesocket(Socket);
		Socket = INVALID_SOCKET;
	}

	freeaddrinfo(result);

	testResult = send(Socket, testBuffer, 0, 0);

	if (testResult == -1) {
		printf("Unable to connect to server!\n");
		
		reconnect(5);
	}
	else {
		printf("Connected to Server \n");
	}
}

Server::~Server() {

}