#include "Logic.h"
#include "Actors.h"
#include "BearLibTerminal.h"
#include <vector>
#include <iostream>
#include "Mapgen.h"
#include <utility>

using namespace std;

bool ActorWalk = true;
bool SetWalk;
int Turn_Timer = 0;

int map_x, map_y;

int camera_x, camera_y;

bool _Look;

int Prev_Player_X, Prev_Player_Y;
int Prev_Player_Glyth = 0x01;

int Prev_X = 0;
int Prev_Y = 0;

extern void GameStart() //The main game logic. The game runs through each of these methods, before moving back to main() and refreshing the terminal. One pass through equals one turn.
{
	camera_x = ActorBag[0].Get_Location_X();
	camera_y = ActorBag[0].Get_Location_Y();
	Keyboard();
	terminal_clear();
	terminal_refresh();
	ActorLogic();
	PropLogic();
	SetLogic();
	Map();
	UI();
	FOV();
	Turn_Timer++;
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
	if (key == TK_UP)
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
	else if (key == TK_LEFT)
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
		else
		{

		}
	}

	//Moves the player right one square.
	else if (key == TK_DOWN)
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
	else if (key == TK_RIGHT)
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

	//Allows the player to inspect the surroundings
	else if (key == TK_K)
	{
		K_Look();
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

void K_Look()
{
	Prev_Player_X = ActorBag[0].Get_Location_X();
	Prev_Player_Y = ActorBag[0].Get_Location_Y();
	Prev_Player_Glyth = ActorBag[0].Get_Glyth();

	_Look = true;
	while (_Look)
	{
		ActorBag[0].Set_Glyth(0x0FA);
		terminal_clear();
		Map();
		UI();
		terminal_refresh();

		camera_x = ActorBag[0].Get_Location_X();
		camera_y = ActorBag[0].Get_Location_Y();

		terminal_refresh();
		int key = terminal_read();
		//Moves the player up one square.
		if (key == TK_UP)
		{
			ActorBag[0].Set_Location_Y(-1);
			terminal_clear();
			Map();
			UI();
			terminal_refresh();
			Prev_Y ++;
		}
		//Moves the player left one square.
		else if (key == TK_LEFT)
		{
			ActorBag[0].Set_Location_X(-1);
			terminal_clear();
			Map();
			UI();
			terminal_refresh();
			Prev_X ++;
		}

		//Moves the player right one square.
		else if (key == TK_DOWN)
		{
			ActorBag[0].Set_Location_Y(1);
			terminal_clear();
			Map();
			UI();
			terminal_refresh();

			Prev_Y --;
		}

		//Moves the player down one square.
		else if (key == TK_RIGHT)
		{
			ActorBag[0].Set_Location_X(1);
			terminal_clear();
			Map();
			UI();
			terminal_refresh();

			Prev_X --;
		}
		else if (key == TK_SPACE)
		{
			_Look = false;
			ActorBag[0].Set_Location_X(Prev_X);
			ActorBag[0].Set_Location_Y(Prev_Y);
			ActorBag[0].Set_Glyth(Prev_Player_Glyth);
			Prev_X = 0;
			Prev_Y = 0;
		}
		//UI 28,31//
		terminal_print(28, 32, "Creature Name: ");

		for (vector<Actors>::iterator BagIterator = ActorBag.begin() + 1; BagIterator != ActorBag.end(); ++BagIterator)
		{
			if (ActorBag[0].Get_Location_X() == BagIterator->Get_Location_X() && ActorBag[0].Get_Location_Y() == BagIterator->Get_Location_Y())
			{
				string Creature_Name = BagIterator->Get_Name();
				char const *pchar = Creature_Name.c_str();
				terminal_print(43, 32, pchar);
			}
		}
	}
}

inline void Map() //Basically places everything that's inside the bags onto the screen.
{
	Move_Camera(ActorBag[0].Get_Location_X(), ActorBag[0].Get_Location_Y());

	for (int x = 0; x < Camera_Width; x++)
	{
		for (int y = 0; y < Camera_Height; y++)
		{
			map_x = camera_x + x;
			map_y = camera_y + y;
			if (SetBag[map_x][map_y].Get_Visible())
			{
				switch (SetBag[map_x][map_y].Get_Type())
				{
				case 1:
				{
					terminal_color("red");
					terminal_put(x, y, SetBag[map_x][map_y].Get_Glyth());
					terminal_color("white");
				}
				case 2:
				{
					terminal_color("brown");
					terminal_put(x, y, SetBag[map_x][map_y].Get_Glyth());
					terminal_color("white");
				}
				default:
				{
					break;
				}
				}
			}
			else
			{

			}
		}
	}

	for (auto Prop : PropBag)
	{
		Prop.Draw();
	}

	for (auto Actor : ActorBag)
	{
		Actor.Draw();
	}
}

void MapFill()
{
	terminal_layer(1); //Sets the terminal layer. Dictates which layer to draw on.

	Map_Gen();

	//New_Prop(34, 8, 0x115C, "Short Sword");
	//New_Prop(34, 8, 0x115C, "Long Sword");

	terminal_layer(2);
	ActorBag[0].Set_Level(1);

	//New_Actor("Goblin", 31, 8, 0x47, true, false, 2);
	ActorBag[0].Set_Health(10);
	//New_Actor("Steve", 20, 12, '#', true, false);
	terminal_layer(1);
}

void UI()
{
	for (int i = 0; i < 30; i++)
	{
		terminal_put(65, i, 0xB3);
	}
	for (int i = 0; i < 65; i++)
	{
		terminal_put(i, 30, 0xC4);
	}
	terminal_put(65, 30, 0xD9);

	//Stats//
	terminal_print(66, 0, "Statistics");

	//Health//
	int Health = ActorBag[0].Get_Health();
	std::string s = std::to_string(Health);
	char const *pchar = s.c_str();
	terminal_print(66, 1, "Health: ");
	terminal_print(93, 1, pchar);

	//Mana//
	int Mana = ActorBag[0].Get_Mana();
	s = std::to_string(Mana);
	pchar = s.c_str();
	terminal_print(66, 2, "Mana: ");
	terminal_print(73, 2, pchar);

	//Experience//
	int Experience = ActorBag[0].Get_Experience();
	s = std::to_string(Experience);
	pchar = s.c_str();
	terminal_print(66, 3, "Exp: ");
	terminal_print(73, 3, pchar);

	int Level = ActorBag[0].Get_Level();
	s = std::to_string(Level);
	pchar = s.c_str();
	terminal_print(66, 4, "Level: ");
	terminal_print(73, 4, pchar);

	//----------//

	terminal_print(66, 5, "--Attributes--");

	//----------//

	//Strength
	int Strength = ActorBag[0].Get_Strength();
	s = std::to_string(Strength);
	pchar = s.c_str();
	terminal_print(66, 6, "Str: ");
	terminal_print(73, 6, pchar);

	//Willpower//
	int Willpower = ActorBag[0].Get_Wisdom();
	s = std::to_string(Willpower);
	pchar = s.c_str();
	terminal_print(66, 7, "Wil: ");
	terminal_print(73, 7, pchar);

	//Agility//
	int Agility = ActorBag[0].Get_Agility();
	s = std::to_string(Agility);
	pchar = s.c_str();
	terminal_print(66, 8, "Agi: ");
	terminal_print(73, 8, pchar);

	//Intelligence//
	int Intelligence = ActorBag[0].Get_Intelligence();
	s = std::to_string(Intelligence);
	pchar = s.c_str();
	terminal_print(66, 9, "Int: ");
	terminal_print(73, 9, pchar);

	//Perception//
	int Perception = ActorBag[0].Get_Perception();
	s = std::to_string(Perception);
	pchar = s.c_str();
	terminal_print(66, 10, "Per: ");
	terminal_print(73, 10, pchar);

	//Turn Timer//
	s = std::to_string(Turn_Timer);
	pchar = s.c_str();
	terminal_print(66, 11, "Turn: ");
	terminal_print(73, 11, pchar);


	//Items//
	terminal_print(0, 31, "//--Items on the ground--\\\\");


	terminal_put(27, 30, 0xC2);
	for (int i = 31; i < 50; i++)
	{
		terminal_put(27, i, 0xB3);
	}

	int Num_Items = SetBag[ActorBag[0].Get_Location_X()][ActorBag[0].Get_Location_Y()].Get_Inventory().size();

	if (Num_Items == 0)
	{
		terminal_print(0, 32, "No Items on the ground");
	}
	else
	{
		for (int i = 0; i < Num_Items; i++)
		{
			s = std::to_string(i);
			pchar = s.c_str();
			terminal_print(0, 32 + i, pchar);
			terminal_print(1, 32 + i, ".");
			terminal_print(3, 32 + i, SetBag[ActorBag[0].Get_Location_X()][ActorBag[0].Get_Location_Y()].Get_Inventory()[i].Get_Name().c_str());
		}
	}

	terminal_print(28, 31, "//--Information--\\\\");
}

void Move_Camera(int target_x, int target_y)
{
	int x = target_x - (Camera_Width / 2);
	int y = target_y - (Camera_Height / 2);

	if (x < 0) { x = 0; }
	if (y < 0) { y = 0; }
	if (x > Map_Width - (Camera_Width - 1)) { x = Map_Width - (Camera_Width - 1); }
	if (y > Map_Height - (Camera_Height - 1)) { y = Map_Height - (Camera_Height - 1); }

	camera_x = x;
	camera_y = y;
}

//Required at startup to initialize the map.
void Init_Map()
{
	for (int x = 0; x < Map_Width; x++)
	{
		SetBag.push_back(vector<Sets>());
		for (int y = 0; y < Map_Height; y++)
		{
			SetBag[x].push_back(Sets());
		}
	}
}