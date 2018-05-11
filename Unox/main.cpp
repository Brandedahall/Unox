// Unox.cpp : Defines the entry point for the console application.
//
#include "BearLibTerminal.h"
#include "main.h"
#include "Actors.h"
#include "Logic.h"
#include "Mapgen.h"
#include "Character_Gen.h"

void main() //Main entry point of the program.
{
	//Networking//
	

	std::default_random_engine rd(std::random_device{}());
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> X(1, 2147483647);

	Init(); //Required to fill the 2d vector with objects.
	MapMaker(X(gen));
	terminal_open(); //Opens the terminal window.
	terminal_set("window: title='Unox', size=80x50"); //Sets with title, size and minimum size of the terminal.
	terminal_set("font: tileset.bmp, size = 16x16");
	terminal_clear();
	terminal_refresh(); //Refreshes the terminal so that it shows up.

	Start_Screen();
	MapFill(); //Places the temporary player character. \\TO BE REPLACED//

	while (true) //Cannot be exited out of, by normal means.
	{
		GameStart(); //This is the main logic of the program.
		terminal_refresh(); //Refreshes the terminal so that any graphical updates that occur will show up on screen.
	}
}