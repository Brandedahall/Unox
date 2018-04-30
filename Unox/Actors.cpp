#include "Actors.h"

//----------------------------------//
//Bags//
//These are used to store the numerous Creatures, Objects and Destructable Enviroments in the game.
vector<Actors> ActorBag = {};
vector<Props> PropBag = {};
vector<vector<Sets>> SetBag(30,vector<Sets>(130, Sets()));

int ActorId = 0;
int PropId = 0;
int SetId = 0;

bool Walk_ = true;

#pragma region Methods
//----------------------------------//
void New_Actor(string Name, int X, int Y, char Glyth, bool Visible, bool Walkable, int Type)
{
	Actors Actor = Actors(Name, X, Y, Glyth, Visible, Walkable, ActorId, Type);
	ActorId +=1;
	ActorBag.push_back(Actor);
}
void New_Prop(int X, int Y, char Glyth, string Name)
{
	Props Prop = Props(X, Y, Glyth, PropId, Name);
	PropId++;
	PropBag.push_back(Prop);
	SetBag[X][Y].Set_Inventory(Prop);
}
void New_Set(int X, int Y, char Glyth, bool Visible, bool Walkable, int Type)
{
	Sets Set = Sets(X, Y, Glyth, Visible, SetId, Walkable, Type);
	SetId++;
	SetBag[X][Y] = Set;
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
		if (walk(Get_Location_X() + 1, Get_Location_Y()))
		{
			Set_Location_X(1);
		}
		else
		{

		}
	}
	if (ActorBag[0].Get_Location_Y() > Get_Location_Y())
	{
		if (walk(Get_Location_X(), Get_Location_Y() + 1))
		{
			Set_Location_Y(1);
		}
		else
		{

		}
	}
	if (ActorBag[0].Get_Location_X() < Get_Location_X())
	{
		if (walk(Get_Location_X() - 1, Get_Location_Y()))
		{
			Set_Location_X(-1);
		}
		else
		{

		}
	}
	if (ActorBag[0].Get_Location_Y() < Get_Location_Y())
	{
		if (walk(Get_Location_X(), Get_Location_Y() - 1))
		{
			Set_Location_Y(-1);
		}
		else
		{

		}
	}

	//Diagonal
	if (ActorBag[0].Get_Location_X() > Get_Location_X() && ActorBag[0].Get_Location_Y() > Get_Location_Y())
	{
		if (walk(Get_Location_X() + 1, Get_Location_Y() + 1))
		{
			Set_Location_X(1);
			Set_Location_Y(1);
		}
		else
		{

		}
	}
	if (ActorBag[0].Get_Location_X() < Get_Location_X() && ActorBag[0].Get_Location_Y() < Get_Location_Y())
	{
		if (walk(Get_Location_X() - 1, Get_Location_Y() - 1))
		{
			Set_Location_X(-1);
			Set_Location_Y(-1);
		}
		else
		{

		}
	}
	if (ActorBag[0].Get_Location_X() > Get_Location_X() && ActorBag[0].Get_Location_Y() < Get_Location_Y())
	{
		if (walk(Get_Location_X() + 1, Get_Location_Y() - 1))
		{
			Set_Location_X(1);
			Set_Location_Y(-1);
		}
		else
		{

		}
	}
	if (ActorBag[0].Get_Location_X() < Get_Location_X() && ActorBag[0].Get_Location_Y() > Get_Location_Y())
	{
		if (walk(Get_Location_X() - 1, Get_Location_Y() + 1))
		{
			Set_Location_X(-1);
			Set_Location_Y(1);
		}
		else
		{

		}
	}
}

#pragma endregion

bool walk(int X, int Y)
{
	Walk_ = true;
	for (vector<Actors>::iterator BagIterator = ActorBag.begin(); BagIterator != ActorBag.end(); ++BagIterator)
	{
		if (BagIterator->Get_Location_X() == X && BagIterator->Get_Location_Y() == Y)
		{
			if (BagIterator->Get_Walkable())
			{
				Walk_ = true;
			}
			else
			{
				Walk_ = false;
			}
		}
	}

	if (SetBag[X][Y].Get_Walkable() && Walk_)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//----------------------------------//
#pragma region Constructors
//Base Constructors//
inline Actors::Actors(string name, int x, int y, char glyth, bool visible, bool walkable, int id, int type)
{
	Name = name;
	X = x;
	Y = y;
	Glyth = glyth;
	Visible = visible;
	ID = id;
	Logic = true;
	Walkable = walkable;
	Type = type;
}

inline Actors::~Actors()
{
}

inline Props::Props(int x, int y, char glyth, int id, string name)
{
	X = x;
	Y = y;
	Glyth = glyth;
	ID = id;
	Name = name;
}

inline Props::~Props()
{
}

inline Sets::Sets() {}

inline Sets::Sets(int x, int y, char glyth, bool visible, int id, bool walkable, int type)
{
	X = x;
	Y = y;
	Glyth = glyth;
	Visible = visible;
	ID = id;
	Walkable = walkable;
	Type = type;
}

inline Sets::~Sets()
{

}

#pragma endregion

