#include "Packet.h"

string Packet::toString() {
	string result = "";

	string limiter = "\r\n\r\n\r\n\r\n";
	string spacer = "\r\n";

	result += limiter;

	result += this->id;
	result += spacer;

	result += this->hash;
	result += spacer;

	result += this->message;

	result += limiter;

	return result;
}