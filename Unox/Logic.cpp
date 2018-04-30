#include "Logic.h"
#include "Actors.h"
#include "BearLibTerminal.h"
#include <vector>
#include <iostream>
//#include "Mapgen.h"

using namespace std;

#define MAP_WIDTH = 130;
#define MAP_HEIGHT = 30;

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
	FOV();
}

//LOGIC//
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

}

//FOV//

void FOV()
{

}

//MOVEMENT//
void Keyboard() //Reads key inputs from the keyboard and moves the player, among other key commands.
{
	ActorWalk = true;
	int key = terminal_read();
	//Moves the player up one square
	if (key == TK_UP && ActorBag[0].Get_Location_Y() > 1)
	{
		for (vector<Actors>::iterator BagIterator = ActorBag.begin() + 1; BagIterator != ActorBag.end(); ++BagIterator)
		{
			if (ActorBag[0].Get_Location_X() == BagIterator->Get_Location_X() && ActorBag[0].Get_Location_Y() - 1 == BagIterator->Get_Location_Y())
			{
				if (BagIterator->Get_Walkable())
				{
					ActorWalk = true;
				}
				else
				{
					ActorWalk = false;
				}
			}
		}
		if (ActorWalk && SetBag[ActorBag[0].Get_Location_X()][ActorBag[0].Get_Location_Y() - 1].Get_Walkable())
		{
			ActorBag[0].Set_Location_Y(-1);
			ActorBag[0].Set_Logic(true);
		}
	}
	//Moves the player left one square.
	else if (key == TK_LEFT && ActorBag[0].Get_Location_X() > 1)
	{
		for (vector<Actors>::iterator BagIterator = ActorBag.begin() + 1; BagIterator != ActorBag.end(); ++BagIterator)
		{
			if (ActorBag[0].Get_Location_X() - 1 == BagIterator->Get_Location_X() && ActorBag[0].Get_Location_Y() == BagIterator->Get_Location_Y())
			{
				if (BagIterator->Get_Walkable())
				{
					ActorWalk = true;
				}
				else
				{
					ActorWalk = false;
				}
			}
		}

		if (ActorWalk && SetBag[ActorBag[0].Get_Location_X() - 1][ActorBag[0].Get_Location_Y()].Get_Walkable())
		{
			ActorBag[0].Set_Location_X(-1);
			ActorBag[0].Set_Logic(true);
		}
	}

	//Moves the player right one square.
	else if (key == TK_DOWN && ActorBag[0].Get_Location_Y() < 29)
	{
		for (vector<Actors>::iterator BagIterator = ActorBag.begin() + 1; BagIterator != ActorBag.end(); ++BagIterator)
		{
			if (ActorBag[0].Get_Location_X() == BagIterator->Get_Location_X() && ActorBag[0].Get_Location_Y() + 1 == BagIterator->Get_Location_Y())
			{
				if (BagIterator->Get_Walkable())
				{
					ActorWalk = true;
				}
				else
				{
					ActorWalk = false;
				}
			}
		}
		if (ActorWalk && SetBag[ActorBag[0].Get_Location_X()][ActorBag[0].Get_Location_Y() + 1].Get_Walkable())
		{
			ActorBag[0].Set_Location_Y(1);
			ActorBag[0].Set_Logic(true);
		}
	}

	//Moves the player down one square.
	else if (key == TK_RIGHT && ActorBag[0].Get_Location_X() < 129)
	{
		for (vector<Actors>::iterator BagIterator = ActorBag.begin() + 1; BagIterator != ActorBag.end(); ++BagIterator)
		{
			if (ActorBag[0].Get_Location_X() + 1 == BagIterator->Get_Location_X() && ActorBag[0].Get_Location_Y() == BagIterator->Get_Location_Y())
			{
				if (BagIterator->Get_Walkable())
				{
					ActorWalk = true;
				}
				else
				{
					ActorWalk = false;
				}
			}
		}
		if (ActorWalk && SetBag[ActorBag[0].Get_Location_X() + 1][ActorBag[0].Get_Location_Y()].Get_Walkable())
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
	for (auto row : SetBag)
	{
		for (auto tile : row)
		{
			if (tile.Get_Visible())
			{
				switch (tile.Get_Type())
				{
				case 1:
				{
					terminal_color("orange");
					terminal_put(tile.Get_Location_X(), tile.Get_Location_Y(), tile.Get_Glyth());
					terminal_color("white");
				}
				case 2:
				{
					terminal_color("red");
					terminal_put(tile.Get_Location_X(), tile.Get_Location_Y(), tile.Get_Glyth());
					terminal_color("white");
				}
				default:
					break;
				}
			}
			else
			{

			}
		}
	}

	for (auto Prop : PropBag)
	{
		terminal_put(Prop.Get_Location_X(), Prop.Get_Location_Y(), Prop.Get_Glyth());
	}

	for (auto Actor : ActorBag)
	{
		terminal_put(Actor.Get_Location_X(), Actor.Get_Location_Y(), Actor.Get_Glyth());
	}
}

void MapFill()
{
	terminal_layer(1); //Sets the terminal layer. Dictates which layer to draw on.
	for (int i = 0; i < 65; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			New_Set(i, j, 0x1001, true, true, 1); //Creates 130x30 floor tiles.
		}
	}

	New_Prop(34, 8, '/', "Short Sword");
	New_Prop(34, 8, '/', "Long Sword");

	terminal_layer(2);
	New_Actor("Player", 33, 8, '@', true, false, 1); //Creates a new actor (the player) and pushes it into the Vector ActorBag.
	ActorBag[0].Set_Level(1);

	New_Actor("Goblin", 31, 8, 'g', true, false, 2);
	ActorBag[0].Set_Health(10);
	//New_Actor("Steve", 20, 12, '#', true, false);
	terminal_layer(1);
}

void UI()
{
	for (int i = 0; i < 16; i++)
	{
		terminal_print(65, i, "|");
	}
	for (int i = 0; i < 66; i++)
	{
		terminal_print(i, 15, "-");
	}
	//Stats//
	terminal_print(68, 0, "Statistics");

	//Health//
	int Health = ActorBag[0].Get_Health();
	std::string s = std::to_string(Health);
	char const *pchar = s.c_str();
	terminal_print(66, 1, "Health: ");
	terminal_print(78, 1, pchar);

	//Mana//
	int Mana = ActorBag[0].Get_Mana();
	s = std::to_string(Mana);
	pchar = s.c_str();
	terminal_print(66, 2, "Mana: ");
	terminal_print(78, 2, pchar);

	//Experience//
	int Experience = ActorBag[0].Get_Experience();
	s = std::to_string(Experience);
	pchar = s.c_str();
	terminal_print(66, 3, "Exp: ");
	terminal_print(78, 3, pchar);

	int Level = ActorBag[0].Get_Level();
	s = std::to_string(Level);
	pchar = s.c_str();
	terminal_print(66, 4, "Level: ");
	terminal_print(78, 4, pchar);

	//----------//

	terminal_print(66, 5, "--Attributes--");

	//----------//

	//Strength
	int Strength = ActorBag[0].Get_Strength();
	s = std::to_string(Strength);
	pchar = s.c_str();
	terminal_print(66, 6, "Str: ");
	terminal_print(72, 6, pchar);

	//Willpower//
	int Willpower = ActorBag[0].Get_Wisdom();
	s = std::to_string(Willpower);
	pchar = s.c_str();
	terminal_print(66, 7, "Wil: ");
	terminal_print(72, 7, pchar);

	//Agility//
	int Agility = ActorBag[0].Get_Agility();
	s = std::to_string(Agility);
	pchar = s.c_str();
	terminal_print(66, 8, "Agi: ");
	terminal_print(72, 8, pchar);
	
	//Intelligence//
	int Intelligence = ActorBag[0].Get_Intelligence();
	s = std::to_string(Intelligence);
	pchar = s.c_str();
	terminal_print(66, 9, "Int: ");
	terminal_print(72, 9, pchar);

	//Perception//
	int Perception = ActorBag[0].Get_Perception();
	s = std::to_string(Perception);
	pchar = s.c_str();
	terminal_print(66, 10, "Per: ");
	terminal_print(72, 10, pchar);


	//Items//
	terminal_print(0, 16, "//--Items on the ground--\\\\");

	for (int i = 16; i < 25; i++)
	{
		terminal_print(27, i, "|");
	}

	int Num_Items = SetBag[ActorBag[0].Get_Location_X()][ActorBag[0].Get_Location_Y()].Get_Inventory().size();
	if (Num_Items == 0)
	{
		terminal_print(0, 17, "No Items on the ground");
	}
	else
	{
		for (int i = 0; i < Num_Items; i++)
		{
			s = std::to_string(i);
			pchar = s.c_str();
			terminal_print(0, 17 + i, pchar);
			terminal_print(1, 17 + i, ".");
			terminal_print(3, 17 + i, SetBag[ActorBag[0].Get_Location_X()][ActorBag[0].Get_Location_Y()].Get_Inventory()[i].Get_Name().c_str());
		}
	}



	//Help//

}


//Required at startup to initialize the map.
void Init_Map()
{
	for (int x = 0; x < 130; x++) 
	{
		SetBag.push_back(vector<Sets>());
		for (int y = 0; y < 30; y++) 
		{
			SetBag[x].push_back(Sets());
		}
	}

	for (int x = 0; x < 130; x++) 
	{
		Overworld.push_back(vector<Sets>());
		for (int y = 0; y < 30; y++) 
		{
			Overworld[x].push_back(Sets());
		}
	}
}