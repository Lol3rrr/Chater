#pragma once

#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>

// Need to link with Ws2_32.lib, Mswsock.lib, and Advapi32.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

#include <string>

using namespace std;

class Packet
{
public:
	
	void setID(int nID);
	void setHash(string nHash);
	void setMessage(string nMessage);
	void createByMessage(char hMessage[]);

	static Packet receivePacket(SOCKET socket);
	int sendPacket(SOCKET socket);

	string toString();

	int id;
	string hash;
	string message;

private:

};