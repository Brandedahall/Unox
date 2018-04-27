// Unox.cpp : Defines the entry point for the console application.
//
#include "BearLibTerminal.h"
#include "main.h"
#include "Actors.h"
#include "Logic.h"

void main()
{
	terminal_open();
	terminal_color("flame");
	New_Actor("Player", 2, 2, '@', true);
	while (true)
	{
		GameStart();
		terminal_refresh();
	}
}