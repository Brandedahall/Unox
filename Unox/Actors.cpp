#include "Actors.h"

//----------------------------------//
//Bags//
//These are used to store the numerous Creatures, Objects and Destructable Enviroments in the game.
vector<Actors> ActorBag = {};
vector<Props> PropBag = {};
vector<Sets> SetBag = {};

int ActorId = 0;
int PropId = 0;
int SetId = 0;
#pragma region Methods
//----------------------------------//
extern void New_Actor(string Name, int X, int Y, char Glyth, bool Visible)
{
	Actors Actor = Actors(Name, X, Y, Glyth, Visible, ActorId);
	ActorId +=1;
	ActorBag.push_back(Actor);
}
extern void New_Prop(int X, int Y, char Glyth)
{
	Props Prop = Props(X, Y, Glyth, PropId);
	PropId++;
	PropBag.push_back(Prop);
}
extern void New_Set(int X, int Y, char Glyth, bool Visible, bool Walkable)
{
	Sets Set = Sets(X, Y, Glyth, Visible, SetId, Walkable);
	SetId++;
	SetBag.push_back(Set);
}

void Actors::AI()
{
	Movement();
	//Attack//

}

void Actors::Movement()
{
	//Straight
	if (ActorBag[0].Get_Location_X() > Get_Location_X())
	{
		bool Walkable = walk(Get_Location_X()+1, Get_Location_Y());
		if (Walkable)
		{
			Set_Location_X(1);
		}
	}
	if (ActorBag[0].Get_Location_Y() > Get_Location_Y())
	{
		bool Walkable = walk(Get_Location_X(), Get_Location_Y()+1);
		if (Walkable)
		{
			Set_Location_Y(1);
		}
	}
	if (ActorBag[0].Get_Location_X() < Get_Location_X())
	{
		bool Walkable = walk(Get_Location_X()-1, Get_Location_Y());
		if (Walkable)
		{
			Set_Location_X(-1);
		}
	}
	if (ActorBag[0].Get_Location_Y() < Get_Location_Y())
	{
		bool Walkable = walk(Get_Location_X(), Get_Location_Y()-1);
		if (Walkable)
		{
			Set_Location_Y(-1);
		}
	}

	//Diagonal
	if (ActorBag[0].Get_Location_X() > Get_Location_X() && ActorBag[0].Get_Location_Y() > Get_Location_Y())
	{
		bool Walkable = walk(Get_Location_X() + 1, Get_Location_Y()+1);
		if (Walkable)
		{
			Set_Location_X(1);
			Set_Location_Y(1);
		}
	}
	if (ActorBag[0].Get_Location_X() < Get_Location_X() && ActorBag[0].Get_Location_Y() < Get_Location_Y())
	{
		bool Walkable = walk(Get_Location_X()-1, Get_Location_Y()-1);
		if (Walkable)
		{
			Set_Location_X(-1);
			Set_Location_Y(-1);
		}
	}
	if (ActorBag[0].Get_Location_X() > Get_Location_X() && ActorBag[0].Get_Location_Y() < Get_Location_Y())
	{
		bool Walkable = walk(Get_Location_X() + 1, Get_Location_Y()-1);
		if (Walkable)
		{
			Set_Location_X(1);
			Set_Location_Y(-1);
		}
	}
	if (ActorBag[0].Get_Location_X() < Get_Location_X() && ActorBag[0].Get_Location_Y() > Get_Location_Y())
	{
		bool Walkable = walk(Get_Location_X()-1, Get_Location_Y()+1);
		if (Walkable)
		{
			Set_Location_X(-1);
			Set_Location_Y(1);
		}
	}
}
#pragma endregion

bool walk(int X, int Y)
{
	for (vector<Sets>::iterator BagIterator = SetBag.begin(); BagIterator != SetBag.end(); ++BagIterator)
	{
		if (BagIterator->Get_Location_X() == X && BagIterator->Get_Location_Y())
		{
			if (BagIterator->Get_Walkable())
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}

//----------------------------------//
#pragma region Constructors
//Constructors//
inline Actors::Actors(string name, int x, int y, char glyth, bool visible, int id)
{
	Name = name;
	X = x;
	Y = y;
	Glyth = glyth;
	Visible = visible;
	ID = id;
	Logic = true;
}

inline Actors::~Actors()
{
}

inline Props::Props(int x, int y, char glyth, int id)
{
	X = x;
	Y = y;
	Glyth = glyth;
	ID = id;
}

inline Props::~Props()
{
}

inline Sets::Sets(int x, int y, char glyth, bool visible, int id, bool walkable)
{
	X = x;
	Y = y;
	Glyth = glyth;
	Visible = visible;
	ID = id;
	Walkable = walkable;
}

inline Sets::~Sets()
{

}
#pragma endregion