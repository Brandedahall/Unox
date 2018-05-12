#include "bearlibterminal.h"
#include "Character_Gen.h"
#include "main.h"
#include "Actors.h"
#include "Logic.h"
#include "Mapgen.h"

//Bool//
bool Lock;
bool ChosenGender;


//Int//
int Key;
int Index;

//Player
std::string Name;
int Gender;

//Variables
int Strength, Willpower, Agility, Intelligence, Perception, Charisma;


void Start_Screen()
{
	Lock = true;

	while (Lock)
	{

		terminal_clear();

		terminal_print((80 / 2) - 8, (50 / 2), "Welcome to Unox!");
		terminal_print((80 / 2) - 26, (50 / 2) + 1, "1. New Character     2. Load Character     3. Exit");

		if (Index == 0)
		{
			terminal_print((80 / 2) - 27, (50 / 2) + 1, "*");
			terminal_refresh();
		}
		else if (Index == 1)
		{
			terminal_print((80 / 2) - 6, (50 / 2) + 1, "*");
			terminal_refresh();
		}
		else if (Index == 2)
		{
			terminal_print((80 / 2) + 16, (50 / 2) + 1, "*");
			terminal_refresh();
		}

		terminal_refresh();
		Key = terminal_read();
		if (Key == TK_LEFT && Index > -1)
		{
			Index--;
			if (Index < 0)
			{
				Index = 0;
			}
		}
		if (Key == TK_RIGHT && Index < 3)
		{
			Index++;
			if (Index > 2)
			{
				Index = 2;
			}
		}

		if (Key == TK_ENTER)
		{
			switch (Index)
			{
			case 0:
			{
				Character_Gen();
				break;
			}
			case 1:
			{

				break;
			}
			case 2:
			{
				Close();
				break;
			}
			}
		}
	}

}

void Character_Gen()
{
	Lock = true;
	Index = 0;
	ChosenGender = false;
	while (Lock)
	{
		terminal_clear();

		Char_Gen_UI();

#pragma region Name
		terminal_print(3, 3, "Hello! Please enter your character's name: ");

		if (Name.size() == 0)
		{
			std::string s;

			while (true)
			{
				terminal_clear();
				Char_Gen_UI();
				terminal_print(3, 3, "Hello! Please enter your character's name: ");
				// Visual feedback
				terminal_print(47, 3, s.c_str());
				terminal_refresh();

				int key = terminal_read();

				if (key == TK_RETURN || key == TK_ESCAPE || key == TK_CLOSE)
				{
					// No distinction between confirmation and interruption
					Name = s;
					break;
				}
				else if (key == TK_BACKSPACE && s.length() > 0)
				{
					// Remove one character
					s.resize(s.length() - 1);
				}
				else if (terminal_check(TK_WCHAR) && s.length() < 10)
				{
					// Append one character
					s += (char)terminal_state(TK_WCHAR);
				}
				terminal_refresh();
			}
		}

		terminal_print(47, 3, Name.c_str());

		terminal_refresh();
#pragma endregion

		terminal_print(3, 5, "What gender would you like your character to be: ");

		terminal_print(3, 6, "1. Male     2. Female");

		switch (Index)
		{
			case 0:
			{
				terminal_print(3, 6, "*");
				terminal_refresh();
				break;
			}
			case 1:
			{
				terminal_print(15, 6, "*");
				terminal_refresh();
				break;
			}
		}

		if (ChosenGender == false)
		{
			Key = terminal_read();
			if (Key == TK_LEFT && Index > -1)
			{
				Index--;
				if (Index < 0)
				{
					Index = 0;
				}
			}
			if (Key == TK_RIGHT && Index < 2)
			{
				Index++;
				if (Index > 1)
				{
					Index = 1;
				}
			}
			if (Key == TK_ENTER)
			{
				Gender = Index;
				ChosenGender = true;
			}
		}
		else
		{
			Stats();
			Lock = false;
			Skills();
		}
		terminal_refresh();
	}
}

void Char_Gen_UI()
{
	//Down//
	for (int x = 2; x < PROGRAM_WIDTH - 2; x++)
	{
		terminal_put(x, 1, 0xC4);
	}

	for (int x = 2; x < PROGRAM_WIDTH - 2; x++)
	{
		terminal_put(x, PROGRAM_HEIGHT - 2, 0xC4);
	}

	//Across//
	for (int y = 2; y < PROGRAM_HEIGHT - 2; y++)
	{
		terminal_put(1, y, 0xB3);
	}

	for (int y = 2; y < PROGRAM_HEIGHT - 2; y++)
	{
		terminal_put(PROGRAM_WIDTH - 2, y, 0xB3);
	}

	terminal_put(1, 1, 0xDA);
	terminal_put(1, PROGRAM_HEIGHT - 2, 0xC0);
	terminal_put(PROGRAM_WIDTH - 2, 1, 0xBF);
	terminal_put(PROGRAM_WIDTH - 2, PROGRAM_HEIGHT - 2, 0xD9);
}

void Stats()
{
	bool Statchoose = true;
	while (true)
	{
		if (Statchoose == true)
		{
			std::default_random_engine rd(std::random_device{}());
			std::mt19937 gen(rd());
			std::uniform_int_distribution<> X(2, 16);

			std::string s;
			char const *pchar;

			terminal_print(4, 9, "~~~~~~Stats~~~~~~~~");

			terminal_print(4, 10, "~~~~~Strength~~~~~");
			Strength = (X(gen) + 2) * 5;
			s = std::to_string(Strength);
			pchar = s.c_str();
			terminal_print(12, 11, pchar);

			terminal_print(4, 12, "~~~~~Willpower~~~~");
			Willpower = (X(gen) + 2) * 5;
			s = std::to_string(Willpower);
			pchar = s.c_str();
			terminal_print(12, 13, pchar);

			terminal_print(4, 14, "~~~~~Agility~~~~~~");
			Agility = (X(gen) + 2) * 5;
			s = std::to_string(Agility);
			pchar = s.c_str();
			terminal_print(12, 15, pchar);

			terminal_print(4, 16, "~~~~~Intelligence~");
			Intelligence = (X(gen) + 2) * 5;
			s = std::to_string(Intelligence);
			pchar = s.c_str();
			terminal_print(12, 17, pchar);

			terminal_print(4, 18, "~~~~~Perception~~~");
			Perception = (X(gen) + 2) * 5;
			s = std::to_string(Perception);
			pchar = s.c_str();
			terminal_print(12, 19, pchar);

			terminal_print(4, 20, "~~~~~Charisma~~~~~");
			Charisma = (X(gen) + 2) * 5;
			s = std::to_string(Charisma);
			pchar = s.c_str();
			terminal_print(12, 21, pchar);

			//Down//
			for (int x = 3; x < 23; x++)
			{
				terminal_put(x, 8, 0xC4);
			}

			for (int x = 3; x < 23; x++)
			{
				terminal_put(x, 22, 0xC4);
			}

			//Across//
			for (int y = 8; y < 23; y++)
			{
				terminal_put(3, y, 0xB3);
			}

			for (int y = 8; y < 22; y++)
			{
				terminal_put(22, y, 0xB3);
			}

			terminal_put(3, 8, 0xDA);
			terminal_put(3, 22, 0xC0);
			terminal_put(22, 22, 0xD9);
			terminal_put(22, 8, 0xBF);
		}

		terminal_refresh();
		Key = terminal_read();
		if (Key == TK_R)
		{

		}
		else if (Key == TK_ENTER)
		{
			break;
		}
	}
}

void Skills()
{
	terminal_print(25, 9, "Skills:");


	//Down//
	for (int x = 25; x < 44; x++)
	{
		terminal_put(x, 8, 0xC4);
	}

	for (int x = 25; x < 44; x++)
	{
		terminal_put(x, 22, 0xC4);
	}

	//Across//
	for (int y = 9; y < 22; y++)
	{
		terminal_put(24, y, 0xB3);
	}

	for (int y = 9; y < 22; y++)
	{
		terminal_put(44, y, 0xB3);
	}

	terminal_put(24, 8, 0xDA);
	terminal_put(24, 22, 0xC0);
	terminal_put(44, 22, 0xD9);// Bottom right
	terminal_put(44, 8, 0xBF); //Top right
}


void Close()
{
	terminal_clear();
	terminal_print((80 / 2) - 7, (50 / 2), "Are you sure?");
	terminal_print((80 / 2) - 12, (50 / 2) + 1, "Y = Close, N = Continue");
	terminal_refresh();
	Key = terminal_read();
	if (Key == TK_Y)
	{
		terminal_close();
	}
	else if (Key == TK_N)
	{
		terminal_clear();
	}
}
