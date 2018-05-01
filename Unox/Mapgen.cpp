#include "Mapgen.h"
#include <vector>
#include <random>
#include <iostream>

using namespace std;

inline void Map_Gen()
{
	default_random_engine rd(std::random_device{}());
	mt19937 gen(rd());
	uniform_int_distribution<> Width(1, 59);
	uniform_int_distribution<> Height(1, 9);

	//Creates a random room.
	Room(Width(gen), Height(gen), 5, 5);

	

}

void Room(int X, int Y, int width, int height)
{
	for (int x = X; x <= X + width; x++)
	{
		for (int y = Y; y <= Y + height; y++)
		{
			if (x == X || x == X + width || y == Y || y == Y + height)
			{
				New_Set(x, y, '%', true, false, 2);
			}
			else
			{
				New_Set(x, y, '~', true, true, 1);
			}
		}
	}
}