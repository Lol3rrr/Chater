#pragma once

#include <iostream>

#include "Main.h"

using namespace std;

class Gui
{
public:
	Gui(Main *main);
	~Gui();

	void output(string message);
	void start();

private:

	Main* main;

};