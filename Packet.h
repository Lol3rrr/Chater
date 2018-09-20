#pragma once

#include <string>

using namespace std;

class Packet
{
public:
	
	void setID(int nID);
	void setHash(string nHash);
	void setMessage(string nMessage);
	void createByMessage(char hMessage[]);

	string toString();

	int id;
	string hash;
	string message;

private:

};