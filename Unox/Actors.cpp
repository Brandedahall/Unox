#include "Actors.h"

//----------------------------------//
//Bags//
//These are used to store the numerous Creatures, Objects and Destructable Enviroments in the game.
vector<Actors> ActorBag = {};
vector<Props> PropBag = {};
vector<Set> SetBag = {};

int ActorId = 0;
int PropId = 0;
int SetId = 0;

//----------------------------------//
void New_Actor(int X, int Y, char Glyth, bool Visible, int ID)
{
	Actors Actor = Actors(X, Y, Glyth, Visible, ID);
	ActorBag.push_back(Actor);
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

Props::Props()
{
}

Props::~Props()
{
}

Set::Set()
{

}

Set::~Set()
{

}
#pragma endregion