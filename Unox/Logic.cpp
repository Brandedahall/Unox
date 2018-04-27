#include "Logic.h"
#include "Actors.h"
#include "BearLibTerminal.h"
#include <vector>
#include <iostream>

using namespace std;

extern void GameStart()
{
	Keyboard();
	terminal_clear();
	terminal_refresh();
	ActorLogic();
	PropLogic();
	SetLogic();
	Map();
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
void Keyboard()
{
	int key = terminal_read();
	if (key == TK_W && ActorBag[0].Get_Location_Y() > 1)
	{
		ActorBag[0].Set_Location_Y(-1);
		ActorBag[0].Set_Logic(true);
	}
	else if (key == TK_A && ActorBag[0].Get_Location_X() > 1)
	{
		ActorBag[0].Set_Location_X(-1);
		ActorBag[0].Set_Logic(true);
	}
	else if (key == TK_S && ActorBag[0].Get_Location_Y() < 23)
	{
		ActorBag[0].Set_Location_Y(1);
		ActorBag[0].Set_Logic(true);
	}
	else if (key == TK_D && ActorBag[0].Get_Location_X() < 78)
	{
		ActorBag[0].Set_Location_X(1);
		ActorBag[0].Set_Logic(true);
	}
	else
	{

	}
}

inline void Map()
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
	terminal_layer(1);
	for (int i = 0; i < 80; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			New_Set(i, j, '*', true, true);
		}
	}
	terminal_layer(2);
	cout << (terminal_check(TK_LAYER));
	New_Actor("Player", 39, 12, '@', true);
	New_Actor("Steve", 20, 20, '#', true);
	terminal_layer(1);
}
