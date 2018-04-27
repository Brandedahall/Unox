// Unox.cpp : Defines the entry point for the console application.
//
#include "BearLibTerminal.h"
#include "main.h"
#include "Actors.h"
#include "Logic.h"

int main()
{
	terminal_open();
	terminal_color("flame");
	while (true)
	{
		GameStart();
		terminal_refresh();
	}
	return 0;
}