#include "GUI.h"

void Gui::start() {

	while (true) {

		string line;
		getline(cin, line);

		this->output(line);

	}

}