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

//----------------------------------//
void New_Actor(int X, int Y, char Glyth, bool Visible)
{
	Actors Actor = Actors(X, Y, Glyth, Visible, ActorId);
	ActorBag.push_back(Actor);
}
void New_Prop(int X, int Y, char Glyth)
{
	Props Prop = Props(X, Y, Glyth, PropId);
	PropBag.push_back(Prop);
}
void New_Set(int X, int Y, char Glyth, bool Visible)
{
	Sets Set = Sets(X, Y, Glyth, Visible, SetId);
	SetBag.push_back(Set);
}

//----------------------------------//
#pragma region Constructors
//Constructors//
Actors::Actors(int x, int y, char glyth, bool visible, int id)
{
	X = x;
	Y = y;
	Glyth = glyth;
	Visible = visible;
	ID = id;
}

Actors::~Actors()
{
}

Props::Props(int x, int y, char glyth, int id)
{
	X = x;
	Y = y;
	Glyth = glyth;
	ID = id;
}

Props::~Props()
{
}

Sets::Sets(int x, int y, char glyth, bool visible, int id)
{
	X = x;
	Y = y;
	Glyth = glyth;
	Visible = visible;
	ID = id;
}

Sets::~Sets()
{

}
#pragma endregion