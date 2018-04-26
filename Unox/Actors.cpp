#include "Actors.h"
//----------------------------------//
void New_Actor(int X, int Y, char Glyth, bool Visible, int ID)
{
	Actors Actor = Actors(X, Y, Glyth, Visible, ID);
	ActorBag.push_back(Actor);
}