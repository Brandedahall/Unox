// Unox.cpp : Defines the entry point for the console application.
//
#include "BearLibTerminal.h"
#include "main.h"
#include "Actors.h"

int main()
{
	terminal_open();
	terminal_color("flame");
	New_Actor(2, 2, '@', true, 1);
	terminal_refresh();
	return 0;
}