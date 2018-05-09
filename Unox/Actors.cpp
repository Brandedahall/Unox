#include "Actors.h"
#include "bearlibterminal.h"
#include "Logic.h"

//----------------------------------//
//Bags//
//These are used to store the numerous Creatures, Objects and Destructable Enviroments in the game.
std::vector<Actors> ActorBag = {};
std::vector<Props> PropBag = {};
std::vector<std::vector<Sets>> SetBag(Map_Width, std::vector<Sets>(Map_Height, Sets()));
std::vector<std::vector<Sets>> Overworld(30, std::vector<Sets>(130, Sets()));

int ActorId = 0;
int PropId = 0;
int SetId = 0;

bool Walk_ = true;

#pragma region Methods
//----------------------------------//
void New_Actor(std::string Name, int X, int Y, char Glyth, bool Visible, bool Walkable, int Type)
{
	Actors Actor = Actors(Name, X, Y, Glyth, Visible, Walkable, ActorId, Type);
	ActorId +=1;
	ActorBag.push_back(Actor);
}
void New_Prop(int X, int Y, char Glyth, std::string Name)
{
	Props Prop = Props(X, Y, Glyth, PropId, Name);
	PropId++;
	PropBag.push_back(Prop);
	SetBag[X][Y].Set_Inventory(Prop);
}
void New_Set(int X, int Y, char Glyth, bool Visible, bool Walkable, int Type, bool Wall, bool Placement)
{
	Sets Set = Sets(X, Y, Glyth, Visible, SetId, Walkable, Type, Wall, true);
	SetId++;
	SetBag[X][Y] = Set;
}

void Actors::AI()
{
	Movement();
	//Attack//
}

void Actors::Draw()
{
	Camera_Coords(X, Y);
	terminal_put(X, Y, Get_Glyth());
}

void Actors::Camera_Coords(int x, int y)
{
	int A = x - camera_x;
	int B = y - camera_y;

	if (x < 0 || y < 0 || x >= Camera_Width || y >= Camera_Height)
	{

	}
	X = A;
	Y = B;
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

void Props::Draw()
{
	terminal_put(Get_Location_X(), Get_Location_Y(), Get_Glyth());
}
#pragma endregion

bool walk(int X, int Y)
{
	Walk_ = true;
	for (std::vector<Actors>::iterator BagIterator = ActorBag.begin(); BagIterator != ActorBag.end(); ++BagIterator)
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


