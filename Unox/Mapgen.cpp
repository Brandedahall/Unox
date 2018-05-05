#include "Mapgen.h"
#include <vector>
#include <random>
#include <iostream>
#include "bearlibterminal.h"
#include <algorithm>

using namespace std;

default_random_engine rd(std::random_device{}());
mt19937 gen(rd());
uniform_int_distribution<> Width(1, 390);
uniform_int_distribution<> LengthWidth(4, 12);
uniform_int_distribution<> Height(1, 170);
uniform_int_distribution<> LengthHeight(4, 12);
uniform_int_distribution<> features(50, 100);

uniform_int_distribution<> Direction(0, 1);

int Features = features(gen);
int W, H, LW, LH, Dir;
int i = 0;

vector<Rect> Rooms;

bool failed;

void init_Map()
{
	for (int x = 0; x < Features; x++)
	{
		Rooms.push_back(Rect());
	}
}

inline void Map_Gen()
{
	init_Map();
	for (int x = 0; x < Features; x++)
	{
		W = Width(gen);
		H = Height(gen);
		LW = LengthWidth(gen);
		LH = LengthHeight(gen);

		Dir = Direction(gen);

		if (Room(W, H, LW, LH))
		{
			if (i == 0)
			{
				New_Actor("Player", W + (LW / 2), H + (LH / 2), 0x01, true, false, 1); //Creates a new actor (the player) and pushes it into the Vector ActorBag.
			}
			i++;
		}
		else
		{
			x--;
		}
	}
}

bool Room(int X, int Y, int width, int height)
{
	if (i == 0)
	{
		Rect room = Rect(X, Y, width, height);
		room.PlaceRoom();
		Rooms[i] = room;
		return true;
	}
	else
	{
		Rect room = Rect(X, Y, width, height);
		failed = false;
		for (auto row : Rooms)
		{
			if (room.intersect(row))
			{
				failed = true;
				return false;
			}
		}
		if (!failed)
		{
			room.PlaceRoom();
			Rooms[i] = room;
			return true;
		}
	}
	return false;
}