#include "Packet.h"

void Packet::encrypt() {

	int currentOffset = 0;

	for (int i = 0; i < strlen(this->message.c_str()); i++) {
		currentOffset = i;
		while (currentOffset > maxEncryptOffset) {
			currentOffset -= 16;
		}

		this->message[i] = this->message[i] + currentOffset;
	}

}