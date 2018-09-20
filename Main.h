#pragma once
#include <string>

#include "Server.h"
#include "GUI.h"

using namespace std;

class Main
{
public:

	void setVar(Gui* gui, Server* server);

	void sendServerMessage(string message);
	void sendGuiMessage(string message);

private:

	Gui* gui;
	Server* server;

};