// Unox.cpp : Defines the entry point for the console application.
//
#include "BearLibTerminal.h"
#include "main.h"
#include "Actors.h"

int main()
{
	terminal_open();
	terminal_color("flame");
	while (true)
	{
		terminal_refresh();
	}
	return 0;
}