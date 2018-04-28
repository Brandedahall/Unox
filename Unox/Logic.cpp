#include "Logic.h"
#include "Actors.h"
#include "BearLibTerminal.h"
#include <vector>
#include <iostream>

using namespace std;

bool ActorWalk = true;
bool SetWalk;

extern void GameStart() //The main game logic. The game runs through each of these methods, before moving back to main() and refreshing the terminal. One pass through equals one turn.
{
	Keyboard();
	terminal_clear();
	terminal_refresh();
	ActorLogic();
	PropLogic();
	SetLogic();
	Map();
	UI();
	//FOV//
}

inline void ActorLogic()
{
	for (vector<Actors>::iterator BagIterator = ActorBag.begin(); BagIterator != ActorBag.end(); ++BagIterator)
	{
		if (BagIterator->Get_Logic() == true && BagIterator->Get_ID() > 0)
		{
			BagIterator->AI();
		}
	}
}

inline void PropLogic()
{
	for (vector<Props>::iterator BagIterator = PropBag.begin(); BagIterator != PropBag.end(); ++BagIterator)
	{

	}
}

inline void SetLogic()
{
	for (vector<Sets>::iterator BagIterator = SetBag.begin(); BagIterator != SetBag.end(); ++BagIterator)
	{

	}
}

//FOV//



//MOVEMENT//
void Keyboard() //Reads key inputs from the keyboard and moves the player, among other key commands.
{
	int key = terminal_read();
	//Moves the player up one square
	if (key == TK_W && ActorBag[0].Get_Location_Y() > 1)
	{
		for (vector<Actors>::iterator BagIterator = ActorBag.begin() + 1; BagIterator != ActorBag.end(); ++BagIterator)
		{
			if (ActorBag[0].Get_Location_X() == BagIterator->Get_Location_X() && ActorBag[0].Get_Location_Y() -1 == BagIterator->Get_Location_Y())
			{
				if (!BagIterator->Get_Walkable())
				{
					ActorWalk = false;
				}
				else
				{
					ActorWalk = true;
				}
			}
		}

		for (vector<Sets>::iterator BagIterator = SetBag.begin(); BagIterator != SetBag.end(); ++BagIterator)
		{
			if (ActorBag[0].Get_Location_X() == BagIterator->Get_Location_X() && ActorBag[0].Get_Location_Y() - 1 == BagIterator->Get_Location_Y())
			{
				if (BagIterator->Get_Walkable())
				{
					SetWalk = true;
				}
			}
		}

		if (ActorWalk && SetWalk)
		{
			ActorBag[0].Set_Location_Y(-1);
			ActorBag[0].Set_Logic(true);
		}
	}

	//Moves the player left one square.
	else if (key == TK_A && ActorBag[0].Get_Location_X() > 1)
	{
		for (vector<Actors>::iterator BagIterator = ActorBag.begin() + 1; BagIterator != ActorBag.end(); ++BagIterator)
		{
			if (ActorBag[0].Get_Location_X() -1 == BagIterator->Get_Location_X() && ActorBag[0].Get_Location_Y() == BagIterator->Get_Location_Y())
			{
				if (!BagIterator->Get_Walkable())
				{
					ActorWalk = false;
				}
				else
				{
					ActorWalk = true;
				}
			}
		}

		for (vector<Sets>::iterator BagIterator = SetBag.begin(); BagIterator != SetBag.end(); ++BagIterator)
		{
			if (ActorBag[0].Get_Location_X() - 1 == BagIterator->Get_Location_X() && ActorBag[0].Get_Location_Y() == BagIterator->Get_Location_Y())
			{
				if (BagIterator->Get_Walkable())
				{
					SetWalk = true;
				}
			}
		}

		if (ActorWalk && SetWalk)
		{
			ActorBag[0].Set_Location_X(-1);
			ActorBag[0].Set_Logic(true);
		}
	}

	//Moves the player right one square.
	else if (key == TK_S && ActorBag[0].Get_Location_Y() < 29)
	{
		for (vector<Actors>::iterator BagIterator = ActorBag.begin() + 1; BagIterator != ActorBag.end(); ++BagIterator)
		{
			if (ActorBag[0].Get_Location_X() == BagIterator->Get_Location_X() && ActorBag[0].Get_Location_Y() +1 == BagIterator->Get_Location_Y())
			{
				if (!BagIterator->Get_Walkable())
				{
					ActorWalk = false;
				}
				else
				{
					ActorWalk = true;
				}
			}
		}

		for (vector<Sets>::iterator BagIterator = SetBag.begin(); BagIterator != SetBag.end(); ++BagIterator)
		{
			if (ActorBag[0].Get_Location_X() == BagIterator->Get_Location_X() && ActorBag[0].Get_Location_Y() +1 == BagIterator->Get_Location_Y())
			{
				if (BagIterator->Get_Walkable())
				{
					SetWalk = true;
				}
			}
		}

		if (ActorWalk && SetWalk)
		{
			ActorBag[0].Set_Location_Y(1);
			ActorBag[0].Set_Logic(true);
		}
	}

	//Moves the player down one square.
	else if (key == TK_D && ActorBag[0].Get_Location_X() < 129)
	{
		for (vector<Actors>::iterator BagIterator = ActorBag.begin() + 1; BagIterator != ActorBag.end(); ++BagIterator)
		{
			if (ActorBag[0].Get_Location_X() +1 == BagIterator->Get_Location_X() && ActorBag[0].Get_Location_Y() == BagIterator->Get_Location_Y())
			{
				if (!BagIterator->Get_Walkable())
				{
					ActorWalk = false;
				}
				else
				{
					ActorWalk = true;
				}
			}
		}

		for (vector<Sets>::iterator BagIterator = SetBag.begin(); BagIterator != SetBag.end(); ++BagIterator)
		{
			if (ActorBag[0].Get_Location_X() +1 == BagIterator->Get_Location_X() && ActorBag[0].Get_Location_Y() == BagIterator->Get_Location_Y())
			{
				if (BagIterator->Get_Walkable())
				{
					SetWalk = true;
				}
			}
		}

		if (ActorWalk && SetWalk)
		{
			ActorBag[0].Set_Location_X(1);
			ActorBag[0].Set_Logic(true);
		}
	}

	//Increments the game logic by one turn.
	else if (key == TK_SPACE)
	{

	}

	//Closes the program.
	else if (key == TK_ESCAPE)
	{
		terminal_close();
	}
	//If the user enters a random key, nothing happens.
	else
	{
		Keyboard();
	}
}

inline void Map() //Basically places everything that's inside the bags onto the screen.
{
	for (vector<Sets>::iterator BagIterator = SetBag.begin(); BagIterator != SetBag.end(); ++BagIterator)
	{
		terminal_put(BagIterator->Get_Location_X(), BagIterator->Get_Location_Y(), BagIterator->Get_Glyth());
	}
	for (vector<Actors>::iterator BagIterator = ActorBag.begin(); BagIterator != ActorBag.end(); ++BagIterator)
	{
		terminal_put(BagIterator->Get_Location_X(), BagIterator->Get_Location_Y(), BagIterator->Get_Glyth());
	}
	for (vector<Props>::iterator BagIterator = PropBag.begin(); BagIterator != PropBag.end(); ++BagIterator)
	{
		terminal_put(BagIterator->Get_Location_X(), BagIterator->Get_Location_Y(), BagIterator->Get_Glyth());
	}
} 

void MapFill()
{
	terminal_layer(1); //Sets the terminal layer. Dictates which layer to draw on.
	for (int i = 0; i < 130; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			New_Set(i, j, '*', true, true); //Creates 130x30 floor tiles.
		}
	}
	terminal_layer(2);
	New_Actor("Player", 39, 12, '@', true, false); //Creates a new actor (the player) and pushes it into the Vector ActorBag.
	//New_Actor("Steve", 20, 12, '#', true, false);
	terminal_layer(1);
}

void UI()
{
	for (int i = 0; i < 31; i++)
	{
		terminal_print(131, i, "|");
	}
	for (int i = 0; i < 131; i++)
	{
		terminal_print(i, 30, "-");
	}

	//Stats//




	//Items//




	//Help//

}
