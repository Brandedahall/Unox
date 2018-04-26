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
	while (true)
	{
		terminal_put(ActorBag[0].Get_Location_X(), ActorBag[0].Get_Location_Y(), ActorBag[0].Get_Glyth());
		terminal_refresh();
	}
	terminal_refresh();
	return 0;
}