#include "Packet.h"
#include <iostream>

string Packet::toString() {
	string result = "";

	string limiter = "\r\n\r\n\r\n\r\n";
	string spacer = "\r\n";

	result += limiter;

	result += to_string(id);
	result += spacer;

	result += this->hash;
	result += spacer;

	result += this->message;

	result += limiter;

	int totalLength = strlen(result.c_str());
	if (totalLength < 1024) {
		for (int i = 0; i < 1024 - totalLength; i++) {
			result += "/";
		}
	}

	return result;
}