// Unox.cpp : Defines the entry point for the console application.
//
#include "BearLibTerminal.h"
#include "main.h"
#include "Actors.h"
#include "Logic.h"
#include "Mapgen.h"

void main() //Main entry point of the program.
{
	default_random_engine rd(std::random_device{}());
	mt19937 gen(rd());
	uniform_int_distribution<> X(1, 2147483647);


	Init();
	gen_Perlin(X(gen));
	terminal_open(); //Opens the terminal window.
	terminal_set("window: title='Unox', size=80x50"); //Sets with title, size and minimum size of the terminal.
	terminal_set("font: tileset.bmp, size = 16x16");
	MapFill(); //Places the temporary player character. \\TO BE REPLACED//
	terminal_refresh(); //Refreshes the terminal so that it shows up.
	while (true) //Cannot be exited out of, by normal means.
	{
		GameStart(); //This is the main logic of the program.
		terminal_refresh(); //Refreshes the terminal so that any graphical updates that occur will show up on screen.
	}
}