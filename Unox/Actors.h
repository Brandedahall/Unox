#ifndef _ACTORS_H_    // To make sure you don't declare the function more than once by including the header multiple times.
#define _ACTORS_H_

#include <vector>

using namespace std;

class Actors
{
public:
	//Constructor and destructor.
	Actors(int X, int Y, char Glyth, bool Visible, int ID);
	~Actors();
	#pragma region Gets and Sets
	//Gets and sets for the private variables.
	int Get_Location_X();
	void Set_Location_X(int x);

	int Get_Location_Y();
	void Set_Location_Y(int y);

	string Get_Name();
	void Set_Name(string name);

	char Get_Glyth();

	char Set_Glyth(char glyth);

	int Get_ID();
	void Set_ID(int id);

	int Get_Reach();
	void Set_Reach(int reach);

	int Get_Type();
	void Set_Type(int type);

	bool Get_Attackable();
	void Set_Attackable(bool attackable);

	bool Get_Walkable();
	void Set_Walkable(bool walkable);

	bool Get_Visible();
	void Set_Visible(bool visible);

	bool Get_Logic();
	void Set_Logic(bool logic);
	#pragma endregion

private:
	//Int//
	int X; //X and Y coordinates for each Actor.
	int Y;

	int ID; //The Id of the Actor.
	int Reach; //How far the Actor can attack from.
	int Type; //Uses a lookup table to determine the type of Actor.

	//String//
	string Name; //Name of the actor.

	//Char//
	char Glyth;//The visible character which is drawn to the screen.

	//Bool//
	bool Attackable; //Checks whether the Actor can be attacked or not. Useful for invulnerable Actors.
	bool Visible; //Checks whether the Actor is currently invisibly on the Screen.
	bool Walkable; //Whether the Actor can be moved through.

	//Logic//
	bool Logic;
};

//----------------------------------//

class Props
{
public:
	//Constructor and destructor.
	Props(int X, int Y, char Glyth, int ID);
	~Props();

#pragma region Gets and Sets
	//Gets and sets for the private variables.

	int Get_Location_X();
	void Set_Location_X();

	int Get_Location_Y();
	void Set_Location_Y();

	int Get_ID();
	void Set_ID();

	int Get_Type();
	void Set_Type();

	string Get_Name();
	void Set_Name();

	char Get_Glyth();
	void Set_Glyth();

	bool Get_Equippable();
	void Set_Equippable();
	#pragma endregion

private:
	//Int//
	int X;
	int Y;
	int ID; //The ID of the Prop object.
	int Type; //Uses a lookup table to determine the type of object.

	//String//
	string Name; //Name of the Prop.

	//Char//
	char Glyth; //The visible character which is drawn to the screen.

	//Bool//
	bool Equippable; //Checks whether the item can be equipped or not.
};

//----------------------------------//

class Sets
{
public:
	//Constructor and destructor.
	Sets(int X, int Y, char Glyth, bool Visible, int ID);
	~Sets();

	#pragma region Gets and Sets
	//Gets and sets for the private variables.

	int Get_Location_X();
	void Set_Location_X();

	int Get_Location_Y();
	void Set_Location_Y();

	int Get_Damage();
	void Set_Damage();

	char Get_Glyth();
	void Set_Glyth();

	bool Get_Attackable();
	void Set_Attackable();

	bool Get_Walkable();
	void Set_Walkable();

	bool Get_Visible();
	void Set_Visible();

	bool Get_Damaging();
	void Set_Damaging();


	#pragma endregion

private:
	//Int//
	int X;
	int Y;
	int Damage; //If a character walks across a floor which has 'Damaging' set to true.
	int ID; //The ID of the set object.

	//Char//
	char Glyth; //The visible character which is drawn to the screen.

	//Bool//
	bool Attackable;
	bool Visible; //Whether the Set object is visible to the character/screen.
	bool Movable; //Whether characters can move the prop.
	bool Walkable;//Whether characters can walk through the prop.
	bool Damaging; //Whether the prop damages an actor if the actor walks across it.
};

//Gets and sets//

#pragma region Gets and sets | Actors

//Logic//
inline bool Actors::Get_Logic()
{
	return Logic;
}

inline void Actors::Set_Logic(bool logic)
{
	Logic = logic;
}

//ID//
inline int Actors::Get_ID()
{
	return ID;
}
inline void Actors::Set_ID(int id)
{
	ID = id;
}

//Reach//
inline int Actors::Get_Reach()
{
	return Reach;
}
inline void Actors::Set_Reach(int reach)
{
	Reach = reach;
}

//Type
inline int Actors::Get_Type()
{
	return Type;
}
inline void Actors::Set_Type(int type)
{
	Type = type;
}

//Name
inline string Actors::Get_Name()
{
	return Name;
}
inline void Actors::Set_Name(string name)
{
	Name = name;
}

//Glyth
inline char Actors::Get_Glyth()
{
	return Glyth;
}
inline char Actors::Set_Glyth(char glyth)
{
	Glyth = glyth;
}

//Attackable//
inline bool Actors::Get_Attackable()
{
	return Attackable;
}
inline void Actors::Set_Attackable(bool attackable)
{
	Attackable = attackable;
}

//Walkable//
inline bool Actors::Get_Walkable()
{
	return Walkable;
}
inline void Actors::Set_Walkable(bool walkable)
{
	Walkable = walkable;
}

//visible//
inline bool Actors::Get_Visible()
{
	return Visible;
}
inline void Actors::Set_Visible(bool visible)
{
	Visible = visible;
}

//Location
inline int Actors::Get_Location_X()
{
	return X;
}

inline void Actors::Set_Location_X(int x)
{
	X = x;
}

inline int Actors::Get_Location_Y()
{
	return Y;
}

inline void Actors::Set_Location_Y(int y)
{
	Y = y;
}


#pragma endregion

#pragma region Gets and Sets | Props
//ID//
inline int Props::Get_ID()
{
	return ID;
}
inline void Props::Set_ID()
{
}

//Type//
inline int Props::Get_Type()
{
	return Type;
}
inline void Props::Set_Type()
{
}

//Name//
inline string Props::Get_Name()
{
	return Name;
}
inline void Props::Set_Name()
{
}

//Glyth//
inline char Props::Get_Glyth()
{
	return Glyth;
}
inline void Props::Set_Glyth()
{
}

//Equippable//
inline bool Props::Get_Equippable()
{
	return Equippable;
}
inline void Props::Set_Equippable()
{
}

//Location
inline int Props::Get_Location_X()
{
	return X;
}

inline void Props::Set_Location_X()
{
}

inline int Props::Get_Location_Y()
{
	return Y;
}

inline void Props::Set_Location_Y()
{
}
#pragma endregion

#pragma region Gets and Sets | Sets
//Damage//
inline int Sets::Get_Damage()
{
	return Damage;
}
inline void Sets::Set_Damage()
{
}

//Glyth//
inline char Sets::Get_Glyth()
{
	return Glyth;
}
inline void Sets::Set_Glyth()
{
}

//Attackable//
inline bool Sets::Get_Attackable()
{
	return Attackable;
}
inline void Sets::Set_Attackable()
{
}

//Walkable//
inline bool Sets::Get_Walkable()
{
	return Walkable;
}
inline void Sets::Set_Walkable()
{
}

//Visible//
inline bool Sets::Get_Visible()
{
	return false;
}
inline void Sets::Set_Visible()
{
}

//Damaging//
inline bool Sets::Get_Damaging()
{
	return Damaging;
}
inline void Sets::Set_Damaging()
{
}

//Location
inline int Sets::Get_Location_X()
{
	return X;
}

inline void Sets::Set_Location_X()
{
}

inline int Sets::Get_Location_Y()
{
	return Y;
}

inline void Sets::Set_Location_Y()
{
}
#pragma endregion

#pragma region Methods definitions
//These methods create new Actors, Props, and Sets.
void New_Actor(int X, int Y, char Glyth, bool Visible);
void New_Prop(int X, int Y, char Glyth);
void New_Set(int X, int Y, char Glyth, bool Visible);


#pragma endregion
//----------------------------------//
//Bags//
//These are used to store the numerous Creatures, Objects and Destructable Enviroments in the game.
extern vector<Actors> ActorBag;
extern vector<Props> PropBag;
extern vector<Sets> SetBag;

extern int ActorID;
extern int ProbID;
extern int SetID;

#endif