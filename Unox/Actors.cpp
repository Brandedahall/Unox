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
	ActorBag.push_back(Actor);
}
extern void New_Prop(int X, int Y, char Glyth)
{
	Props Prop = Props(X, Y, Glyth, PropId);
	PropBag.push_back(Prop);
}
extern void New_Set(int X, int Y, char Glyth, bool Visible)
{
	Sets Set = Sets(X, Y, Glyth, Visible, SetId);
	SetBag.push_back(Set);
}
#pragma endregion

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
}

inline Actors::~Actors()
{
}

void Actors::AI()
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

inline Sets::Sets(int x, int y, char glyth, bool visible, int id)
{
	X = x;
	Y = y;
	Glyth = glyth;
	Visible = visible;
	ID = id;
}

inline Sets::~Sets()
{

}
#pragma endregion