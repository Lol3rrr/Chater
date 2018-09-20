#include "Packet.h"

void Packet::createByMessage(char message[]) {
	string temp(message);

	int start = temp.find("\r\n\r\n\r\n\r\n");

	if (start != string::npos) {
		start += 8;

		int end = temp.find("\r\n", start);

		string substr = temp.substr(start, end - start);
		this->id = stoi(substr, nullptr);

		start = end + 2;

		end = temp.find("\r\n", start);

		substr = temp.substr(start, end - start);
		this->hash = substr;

		start = end + 2;

		end = temp.find("\r\n\r\n\r\n\r\n", start);

		substr = temp.substr(start, end - start);
		this->message = substr;

		start = end + 2;
	}
}