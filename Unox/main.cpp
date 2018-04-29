// Unox.cpp : Defines the entry point for the console application.
//
#include "BearLibTerminal.h"
#include "main.h"
#include "Actors.h"
#include "Logic.h"
#include "Mapgen.h"

void main() //Main entry point of the program.
{
	srand(time(NULL));
	Init_Map();
	terminal_open(); //Opens the terminal window.
	terminal_set("window: title='Unox', size=160x50, minimum-size=80x25"); //Sets with title, size and minimum size of the terminal.
	MapFill(); //Places the ground and temporary player character. \\TO BE REPLACED//
	Num_Gen();
	terminal_refresh(); //Refreshes the terminal so that it shows up.
	while (true) //Cannot be exited out of, by normal means.
	{
		GameStart(); //This is the main logic of the program.
		terminal_refresh(); //Refreshes the terminal so that any graphical updates that occur will show up on screen.
	}
}