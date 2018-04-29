#include "Mapgen.h"
#include <vector>
#include "Actors.h"
#include <random>
#include <iostream>

using namespace std;

//Creates a square room at a random location on the map.
inline void Num_Gen()
{
	for (int i = 0; i < 25; i++)
	{
		int X = getRand(10, 120);
		int Y = getRand(5, 20);

		int Xlength = getRand(4, 8);
		int Ylength = getRand(4, 8);


		Room(X, Y, Xlength, Ylength);
	}
}

long oldseed;

int getRand(int min, int max)
{
	time_t seed;
	seed = time(NULL) + oldseed;
	oldseed = seed;

	srand(seed);

	int n = max - min + 1;
	int i = rand() % n;

	if (i < 0)
		i = -i;

	return min + i;
}

inline void Corridor()
{

}

inline void Room(int x, int y, int xmax, int ymax)
{

	for (int i = x; i <= x + xmax; i++)
	{
		for (int j = y; j <= y + ymax; j++)
		{
			if (i > x && i < (x + xmax) && j > y && j < (y + ymax))
			{
				New_Set(i, j, '~', true, true);
			}
			else
			{
				New_Set(i, j, '%', true, false);
			}
		}
	}
}