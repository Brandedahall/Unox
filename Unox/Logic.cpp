#include "Logic.h"
#include "Actors.h"
#include "BearLibTerminal.h"
#include <iostream>
#include "Mapgen.h"
#include <utility>

//Variables//
bool ActorWalk = true;
bool SetWalk;
int Turn_Timer = 0;

int map_x, map_y;

int camera_x, camera_y;

bool _Look;

int Prev_Player_X, Prev_Player_Y;
int Prev_Player_Glyth = '@';

int Prev_X = 0;
int Prev_Y = 0;

extern int i;

extern std::vector<const char*> Logs(10, "");

std::default_random_engine rd(std::random_device{}());
std::mt19937 gen(rd());

std::string Weaponadverb[] = { "Awesomely", "Greatly", "Badly", "Super", "Ultra", "Mega", "Horrifyingly", "Accurately", "Very", "Really", "Disappointingly", "Seriously", "Willingly", "Sufficiently", "Largely", "Unbelievably", "Primarily", "Interestingly", "Brightly", "Secretly", "Downright", "Naturally", "Fairly", "Easily", "Intensely", "Blatantly", "Additionally", "Necessarily", "Truly", "Scarcely", "Hardly", "Significantly", "Curiously", "Happily", "Relatively", "Vastly", "Eminently", "Satisfactorily", "Ultimately", "Unbearably", "Awfully", "Intimately", "Desperately", "Conclusively", "Exhaustively", "Erratically", "Enigmatically", "Sarcastically" };

std::string WeaponAD[] = { "Powerful", "Horrible", "Bad", "Great", "Developed", "Killer", "Cool", "Stupid", "Battle",  "Awesome",  "Persistant",  "Accurate",  "Named",  "Useful",  "Frightning",  "Idiotic",  "Legendary",  "Dumb",  "Spiked",  "Enjoyable",  "Overlooked",  "Sickening",  "Unnecessary",  "Hardcore",  "Evil",  "Good",  "Maniacal",  "Devious",  "Overpowered",  "Underpowered",  "Mediocre",  "Mohawk",  "Invincible",  "Hipster",  "Gangsta",  "Sharp",  "Unsafe",  "Godlike", "Weird", "Hot", "Chaotic", "Smelly", "Bizarre", "Mighty", "Cardboard", "Deadly", "Soft",  "Potent",  "Suppressive",  "Death-dealing",  "Irritating",  "Explosive", };

std::string WeaponNouns[] = { "Smelling",  "Cooling",  "Flipping",  "Killing",  "Dehydrating",  "Doom",  "Destruction",  "Destroying",  "Poisoning",  "Electrocution",  "Freezing", "Execution",  "Decapitation",  "Eradication",  "Avenging",  "Torture",  "Horror",  "Pain",  "Demolition",  "Deprivation",  "Judgement",  "Disease" };

std::string Wtype[] = { "Sword", "Axe", "Daggers", "Spear", "Scythe" };

std::string WeaponEle[] = { "Normal", "Earth", "Fire", "Ice", "Air", "Electric", };

bool inventory;
bool Description;

//----------------------------------//

//The main game logic. The game runs through each of these methods, before moving back to main() and refreshing the terminal. One pass through equals one turn.
extern void GameStart()
{
	camera_x = ActorBag[0].Get_Location_X();
	camera_y = ActorBag[0].Get_Location_Y();
	terminal_clear();
	Keyboard();
	ActorLogic();
	PropLogic();
	SetLogic();
	FOV();
	Map();
	UI();
	terminal_refresh();
	Turn_Timer++;
}
//----------------------------------//

//LOGIC//
inline void ActorLogic()
{
	for (std::vector<Actors>::iterator BagIterator = ActorBag.begin(); BagIterator != ActorBag.end(); ++BagIterator)
	{
		if (BagIterator->Get_Logic() == true && BagIterator->Get_ID() > 0)
		{
			BagIterator->AI();
		}
	}
}

inline void PropLogic()
{
	for (std::vector<Props>::iterator BagIterator = PropBag.begin(); BagIterator != PropBag.end(); ++BagIterator)
	{

	}
}

inline void SetLogic()
{

}
//----------------------------------//

//FOV//
void FOV()
{
	int i, j;
	float x, y, l;
	for (i = 0; i < Map_Width; i++)
	{
		for (j = 0; j < Map_Height; j++)
		{
			x = i - (float)ActorBag[0].Get_Location_X();
			y = j - (float)ActorBag[0].Get_Location_Y();
			l = sqrt((x*x) + (y*y));
			if (l <= ActorBag[0].Get_FOV())
			{
				if (DoFov(i, j))
				{
					SetBag[i][j].Set_Visible(true);
					SetBag[i][j].Set_Fog(false);
				}
				else
				{

				}
			}
			else
			{
				SetBag[i][j].Set_Fog(true);
			}
		}
	}
}

bool DoFov(int x, int y)
{
	float vx, vy, ox, oy, l;
	int i;
	vx = x - (float)ActorBag[0].Get_Location_X();
	vy = y - (float)ActorBag[0].Get_Location_Y();
	ox = (float)x + 0.5f;
	oy = (float)y + 0.5f;
	l = sqrt((vx*vx) + (vy*vy));
	vx /= l;
	vy /= l;

	for (i = 0; i < (int)l + 1; i++)
	{
		if (!SetBag[(int)ox][(int)oy].Get_Walkable())
		{
			if (!SetBag[(int)ox][(int)oy].Get_Wall())
			{
				return false;
			}
		}
		ox += vx;
		oy += vy;
	}
	return true;
}
//----------------------------------//

//MOVEMENT//
void Keyboard() //Reads key inputs from the keyboard and moves the player, among other key commands.
{
	ActorWalk = true;
	int key = terminal_read();
	//Moves the player up one square
	if (key == TK_UP && ActorBag[0].Get_Location_Y() - 1 > 0)
	{
		for (std::vector<Actors>::iterator BagIterator = ActorBag.begin() + 1; BagIterator != ActorBag.end(); ++BagIterator)
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
	else if (key == TK_LEFT && ActorBag[0].Get_Location_X() - 1 > 0)
	{
		for (std::vector<Actors>::iterator BagIterator = ActorBag.begin() + 1; BagIterator != ActorBag.end(); ++BagIterator)
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
	else if (key == TK_DOWN && ActorBag[0].Get_Location_Y() + 1 < Map_Height)
	{
		for (std::vector<Actors>::iterator BagIterator = ActorBag.begin() + 1; BagIterator != ActorBag.end(); ++BagIterator)
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
	else if (key == TK_RIGHT && ActorBag[0].Get_Location_X() + 1 < Map_Width)
	{
		for (std::vector<Actors>::iterator BagIterator = ActorBag.begin() + 1; BagIterator != ActorBag.end(); ++BagIterator)
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

	else if (key == TK_I)
	{
		Player_Inventory();
		terminal_refresh();
	}

	//Allows the player to inspect the surroundings
	else if (key == TK_K)
	{
		K_Look();
		terminal_refresh();
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
			Prev_Y++;
		}
		//Moves the player left one square.
		else if (key == TK_LEFT)
		{
			ActorBag[0].Set_Location_X(-1);
			terminal_clear();
			Map();
			UI();
			terminal_refresh();
			Prev_X++;
		}

		//Moves the player right one square.
		else if (key == TK_DOWN)
		{
			ActorBag[0].Set_Location_Y(1);
			terminal_clear();
			Map();
			UI();
			terminal_refresh();

			Prev_Y--;
		}

		//Moves the player down one square.
		else if (key == TK_RIGHT)
		{
			ActorBag[0].Set_Location_X(1);
			terminal_clear();
			Map();
			UI();
			terminal_refresh();

			Prev_X--;
		}
		else if (key == TK_SPACE || key == TK_ESCAPE)
		{
			_Look = false;
			ActorBag[0].Set_Location_X(Prev_X);
			ActorBag[0].Set_Location_Y(Prev_Y);
			ActorBag[0].Set_Glyth(Prev_Player_Glyth);
			Prev_X = 0;
			Prev_Y = 0;
			terminal_clear();
			terminal_refresh();
		}
		//UI 28,31//

		for (std::vector<Actors>::iterator BagIterator = ActorBag.begin() + 1; BagIterator != ActorBag.end(); ++BagIterator)
		{
			if (ActorBag[0].Get_Location_X() == BagIterator->Get_Location_X() && ActorBag[0].Get_Location_Y() == BagIterator->Get_Location_Y())
			{
				//Name
				std::string Creature_Name = BagIterator->Get_Name();
				char const *pchar = Creature_Name.c_str();
				terminal_print(28, 32, "Name: ");
				terminal_print(34, 32, pchar);
				
				//Health
				int Creature_Health = BagIterator->Get_Health();
				std::string Health = std::to_string(Creature_Health);
				char const *C_Health = Health.c_str();
				terminal_print(28, 33, "Health: ");
				terminal_print(36, 33, C_Health);
			}
		}
	}
}
//----------------------------------//

//Basically places everything that's inside the bags onto the screen.
void Map()
{
	Move_Camera(ActorBag[0].Get_Location_X(), ActorBag[0].Get_Location_Y());

	for (int x = 0; x < Camera_Width - 1; x++)
	{
		for (int y = 0; y < Camera_Height - 1; y++)
		{
			map_x = camera_x + x;
			map_y = camera_y + y;
			if (SetBag[map_x][map_y].Get_Visible() && !SetBag[map_x][map_y].Get_Fog())
			{
				switch (SetBag[map_x][map_y].Get_Type())
				{
				case 1: //Water
				{
					terminal_color(color_from_name("cyan"));
					terminal_put(x, y, SetBag[map_x][map_y].Get_Glyth());
					break;
				}
				case 2: //Sand
				{
					terminal_color(color_from_name("red"));
					terminal_put(x, y, SetBag[map_x][map_y].Get_Glyth());
					break;
				}
				case 3: // Floors
				{
					terminal_color(color_from_name("light green"));
					terminal_put(x, y, SetBag[map_x][map_y].Get_Glyth());
					break;
				}
				case 4: //Trees
				{
					terminal_color(color_from_name("lightest green"));
					terminal_put(x, y, SetBag[map_x][map_y].Get_Glyth());
					break;
				}
				default:
				{

				}
				}
			}
			else if (SetBag[map_x][map_y].Get_Fog() && SetBag[map_x][map_y].Get_Visible())
			{
				switch (SetBag[map_x][map_y].Get_Type())
				{
				case 1: //Water
				{
					terminal_color(color_from_name("grey"));
					terminal_put(x, y, SetBag[map_x][map_y].Get_Glyth());
					break;
				}
				case 2: //Sand
				{
					terminal_color(color_from_name("grey"));
					terminal_put(x, y, SetBag[map_x][map_y].Get_Glyth());
					break;
				}
				case 3: // Floors
				{
					terminal_color(color_from_name("grey"));
					terminal_put(x, y, SetBag[map_x][map_y].Get_Glyth());
					break;
				}
				case 4: //Trees
				{
					terminal_color(color_from_name("grey"));
					terminal_put(x, y, SetBag[map_x][map_y].Get_Glyth());
					break;
				}
				default:
				{

				}
				}
			}
		}
	}

	for (auto Prop : PropBag)
	{
		Prop.Draw();
	}

	for (auto Actor : ActorBag)
	{
		terminal_color(color_from_name(Actor.Get_Color()));
		Actor.Draw();
	}
}

void MapFill()
{
	terminal_layer(1); //Sets the terminal layer. Dictates which layer to draw on.

	std::uniform_int_distribution<> X(1, Map_Height - 1);
	std::uniform_int_distribution<> Y(1, Map_Width - 1);

	int x = X(gen);
	int y = Y(gen);

	while (!SetBag[x][y].Get_Walkable())
	{
		x = X(gen);
		y = Y(gen);
	}

	New_Actor("Player", x, y, '@', true, false, 1, "white"); //Creates a new actor (the player) and pushes it into the Vector ActorBag.
	terminal_layer(2);
	ActorBag[0].Set_Level(1);
	ActorBag[0].Set_FOV(4);

	//New_Actor("Goblin", 31, 8, 0x47, true, false, 2);
	ActorBag[0].Set_Health(10);
	//New_Actor("Steve", 20, 12, '#', true, false);
	terminal_layer(1);
}
//----------------------------------//

//UI//
void UI()
{
	terminal_color("white");

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
	terminal_print(73, 1, pchar);

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

	//X//
	s = std::to_string(ActorBag[0].Get_Location_X());
	pchar = s.c_str();
	terminal_print(66, 12, "X: ");
	terminal_print(73, 12, pchar);
	//Y//
	s = std::to_string(ActorBag[0].Get_Location_Y());
	pchar = s.c_str();
	terminal_print(66, 13, "Y: ");
	terminal_print(73, 13, pchar);

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

	//Information//
	terminal_print(28, 31, "//--Information--\\\\");
	terminal_put(47, 30, 0xC2);
	for (int i = 31; i < 50; i++)
	{
		terminal_put(47, i, 0xB3);
	}

	//Logs//
	Log();
}

void Log()
{
	terminal_print(48, 31, "//--Log--\\\\");
	terminal_put(65, 30, 0xC1);

	for (int i = 66; i < 80; i++)
	{
		terminal_put(i, 30, 0xC4);
	}
	int x = 0;
	for (unsigned int i = 32; i < 43; i++)
	{
		if (x < 10)
		{
			terminal_print(48, i, Logs[x]);
		}
		x++;
	}
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

void Player_Inventory()
{	
	inventory = true;
	//X = 1, Y = 1 // Top left of the screen down to the bottom right of the screen

	while (inventory)
	{
		int index = 0;
		int i = 0;
		std::string s;
		char const *pchar;
		for (int i = 0; i <= Camera_Width; i++)
		{
			for (int j = 0; j <= Camera_Height; j++)
			{
				terminal_put(i, j, ' ');
			}
		}
		UI();
		Log();

		terminal_print(1,1, "//~~~~~Inventory~~~~~\\\\");

		if (ActorBag[0].Get_Inventory().size() == 0)
		{
			terminal_print(1, 3, "No Items in your inventory. Get looting!");
		}
		else
		{
			for each (auto item in ActorBag[0].Get_Inventory())
			{
					s = std::to_string(i);
					pchar = s.c_str();

					terminal_print(1, 3 + i, pchar);
					terminal_print(2, 3 + i, ".");

					pchar = ActorBag[0].Get_Inventory()[i].Get_Name().c_str();
					terminal_print(4, 3 + i, pchar);

					terminal_print(1, 3 + index, "*");
					i++;
			}
		}
		terminal_refresh();
		int key = terminal_read();
		if (key == TK_UP && index != 0)
		{
			index--;
		}
		else if (key == TK_DOWN && index < 20)
		{
			index++;
		}
		//Use item
		else if (key == TK_ENTER || key == TK_SPACE)
		{
			if (ActorBag[0].Get_Inventory().size() > 0)
			{
				if (ActorBag[0].Get_Inventory()[index].Get_Exists())
				{
					ActorBag[0].Get_Inventory()[index] = Props();
				}
				else
				{

				}
			}
		}
		//Look at item
		else if (key == TK_I)
		{
			if (ActorBag[0].Get_Inventory().size() > 0)
			{
				if (ActorBag[0].Get_Inventory()[index].Get_Exists())
				{
					DescriptionPanel(index);
				}
				else
				{

				}
			}
		}

		else if (key == TK_ESCAPE)
		{
			inventory = false;
			terminal_clear();
			terminal_refresh();
		}
	}
}

void DescriptionPanel(int index)
{
	Description = true;
	while (Description)
	{

		for (int i = 23; i < 33; i++)
		{
			for (int j = 5; j < 25; j++)
			{
				terminal_print(i, j, " ");
			}
		}

		const char *pchar = ActorBag[0].Get_Inventory()[index].Get_Description().c_str();
		terminal_print(24, 6, pchar);

		int key = terminal_read();
		if (key = TK_ESCAPE || TK_SPACE)
		{
			Description = false;
		}
	}

}

//----------------------------------//
//Required at startup to initialize the map.
void Init()
{
	for (int x = 0; x < Map_Width; x++)
	{
		SetBag.push_back(std::vector<Sets>());
		for (int y = 0; y < Map_Height; y++)
		{
			SetBag[x].push_back(Sets());
		}
	}
}