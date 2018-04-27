#include "Logic.h"
#include "Actors.h"
#include "BearLibTerminal.h"
#include <vector>

using namespace std;

extern void GameStart()
{
	KeyboardMovement();
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
		if (BagIterator->Get_Logic() == true && BagIterator->Get_ID() > 2)
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
void KeyboardMovement()
{
	int key = terminal_read();
	if (key == TK_W)
	{
		ActorBag[0].Set_Location_Y(-1);
		ActorBag[0].Set_Logic(true);
	}
	else if (key == TK_A)
	{
		ActorBag[0].Set_Location_X(-1);
		ActorBag[0].Set_Logic(true);
	}
	else if (key == TK_S)
	{
		ActorBag[0].Set_Location_Y(1);
		ActorBag[0].Set_Logic(true);
	}
	else if (key == TK_D)
	{
		ActorBag[0].Set_Location_X(1);
		ActorBag[0].Set_Logic(true);
	}
}

inline void Map()
{
	for (vector<Actors>::iterator BagIterator = ActorBag.begin(); BagIterator != ActorBag.end(); ++BagIterator)
	{
			terminal_clear();
			terminal_put(BagIterator->Get_Location_X(), BagIterator->Get_Location_Y(), BagIterator->Get_Glyth());
	}
	for (vector<Props>::iterator BagIterator = PropBag.begin(); BagIterator != PropBag.end(); ++BagIterator)
	{
			terminal_clear();
			terminal_put(BagIterator->Get_Location_X(), BagIterator->Get_Location_Y(), BagIterator->Get_Glyth());
	}
	for (vector<Sets>::iterator BagIterator = SetBag.begin(); BagIterator != SetBag.end(); ++BagIterator)
	{
			terminal_clear();
			terminal_put(BagIterator->Get_Location_X(), BagIterator->Get_Location_Y(), BagIterator->Get_Glyth());
	}
}