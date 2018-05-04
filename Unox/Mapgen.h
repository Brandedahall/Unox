#ifndef _MAPGEN_H_    // To make sure you don't declare the function more than once by including the header multiple times.
#define _MAPGEN_H_

#include <random>
#include <vector>
#include <iostream>
#include "Actors.h"

extern void Map_Gen();

bool Room(int X, int Y, int width, int height);

void init_Map();

class Rect
{
public:
	Rect(int x, int y, int w, int l);
	Rect();
	~Rect();

	inline bool intersect(Rect A);
	inline void center();
	inline void PlaceRoom();

public:
	int X1, Y1, X2, Y2;
	int center_x, center_y;
};

inline Rect::Rect() {};

inline Rect::Rect(int x, int y, int w, int l)
{
	X1 = x;
	Y1 = y;
	X2 = x + w;
	Y2 = y + l;
}

inline Rect::~Rect()
{
}

inline void Rect::center()
{
	center_x = (X1 + X2) / 2;
	center_y = (Y1  + Y2) / 2;
}

inline bool Rect::intersect(Rect A)
{
	return (X1 <= A.X2 && X2 >= A.X1 && Y1 <= A.Y2 && Y2 >= A.Y1);
}

inline void Rect::PlaceRoom()
{
	for (int x = X1; x <= X2; x++)
	{
		for (int y = Y1; y <= Y2; y++)
		{
			if (x == X1 || x == X2 || y == Y1 || y == Y2)
			{
				New_Set(x, y, '%', true, false, 2, true);
			}
			else
			{
				New_Set(x, y, '~', true, true, 1, true);
			}
		}
	}
}

extern vector<Rect> Rooms;
#endif