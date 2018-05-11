#include "bearlibterminal.h"
#include "Character_Gen.h"
#include "main.h"

//Bool//
bool Lock;
//Int//
int Key;
int Index = 0;

//Player
std::string Name;
bool Gender;
int Strength, Willpower, Agility, Intelligence, Perception;

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
			terminal_print((80 / 2) - 5, (50 / 2) + 1, "*");
			terminal_refresh();
		}
		else if (Index == 2)
		{
			terminal_print((80 / 2) + 15, (50 / 2) + 1, "*");
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
	while (Lock)
	{
		terminal_clear();

		Char_Gen_UI();

		terminal_print(3, 3, "Hello! Please enter your character's name: ");

		if (Name.size() == 0)
		{
			Name = my_read_str(47, 3, 10);
		}

		terminal_print(47, 3, Name.c_str());

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


void Stats_Screen()
{

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

std::string my_read_str(int x, int y, int max)
{
	std::string s;

	while (true)
	{
		terminal_refresh();
		Char_Gen_UI();
		int key = terminal_read();

		if (key == TK_RETURN || key == TK_ESCAPE || key == TK_CLOSE)
		{
			// No distinction between confirmation and interruption
			break;
		}
		else if (key == TK_BACKSPACE && s.length() > 0)
		{
			// Remove one character
			s.resize(s.length() - 1);
		}
		else if (terminal_check(TK_WCHAR) && s.length() < max)
		{
			// Append one character
			s += (wchar_t)terminal_state(TK_WCHAR);
		}

		// Visual feedback
		terminal_print(x, y, s.c_str());
		terminal_refresh();
	}

	return s;
}