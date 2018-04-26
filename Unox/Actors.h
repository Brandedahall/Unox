#pragma once
#include <vector>

using namespace std;

class Actors
{
public:
	//Constructor and destructor.
	Actors();
	~Actors();
	#pragma region Gets and Sets
	//Gets and sets for the private variables.
	int Get_Color();
	void Set_Color();

	string Get_Name();
	void Set_Name();

	char Get_Glyth();

	char Set_Glyth();

	int Get_ID();
	void Set_ID();

	int Get_Reach();
	void Set_Reach();

	int Get_Type();
	void Set_Type();

	bool Get_Attackable();
	void Set_Attackable();

	bool Get_Walkable();
	void Set_Walkable();

	bool Get_Visible();
	void Set_Visible();
	#pragma endregion

private:
	//Int//
	int Color[3]; //Sets the colour of the glyth.
	int ID; //The Id of the Actor.
	int Reach; //How far the Actor can attack from.
	int Type; //Uses a lookup table to determine the type of Actor.

	//String//
	string Name; //Name of the actor.

	//Char//
	char glyth;//The visible character which is drawn to the screen.

	//Bool//
	bool Attackable; //Checks whether the Actor can be attacked or not. Useful for invulnerable Actors.
	bool Visible; //Checks whether the Actor is currently invisibly on the Screen.
	bool Walkable; //Whether the Actor can be moved through.
};

Actors::Actors()
{
}

Actors::~Actors()
{
}

//----------------------------------//

class Props
{
public:
	//Constructor and destructor.
	Props();
	~Props();
	//Gets and sets for the private variables.
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


private:
	//Int//
	int ID; //The ID of the Prop object.
	int Type; //Uses a lookup table to determine the type of object.

	//String//
	string Name; //Name of the Prop.

	//Char//
	char Glyth; //The visible character which is drawn to the screen.

	//Bool//
	bool Equippable; //Checks whether the item can be equipped or not.
};

Props::Props()
{
}

Props::~Props()
{
}

//----------------------------------//

class Set
{
public:
	//Constructor and destructor.
	Set();
	~Set();

	#pragma region Gets and Sets
	//Gets and sets for the private variables.
	int Get_Colour();
	void Set_Colour();

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
	int Colour[3]; //Sets the colour of the glyth
	int Damage; //If a character walks across a floor which has 'Damaging' set to true.
	int ID; //The ID of the set object.

	//Char//
	char Glyth; //The visible character which is drawn to the screen.

	//Bool//
	bool Visible; //Whether the Set object is visible to the character/screen.
	bool Movable; //Whether characters can move the prop.
	bool Walkable;//Whether characters can walk through the prop.
	bool Damaging; //Whether the prop damages an actor if the actor walks across it.
};

Set::Set()
{

}

Set::~Set()
{

}

//Gets and sets//

#pragma region Gets and sets | Actors
//Colour//
inline int Actors::Get_Color()
{
	return 0;
}
inline void Actors::Set_Color()
{
}

//ID//
inline int Actors::Get_ID()
{
	return 0;
}
inline void Actors::Set_ID()
{
}

//Reach//
inline int Actors::Get_Reach()
{
	return 0;
}
inline void Actors::Set_Reach()
{
}

//Type
inline int Actors::Get_Type()
{
	return 0;
}
inline void Actors::Set_Type()
{
}

//Name
inline string Actors::Get_Name()
{
	return 0;
}
inline void Actors::Set_Name()
{
}

//Glyth
inline char Actors::Get_Glyth()
{
	return 0;
}
inline char Actors::Set_Glyth()
{
}

//Attackable//
inline bool Actors::Get_Attackable()
{
	return 0;
}
inline void Actors::Set_Attackable()
{
}

//Walkable//
inline bool Actors::Get_Walkable()
{
	return 0;
}
inline void Actors::Set_Walkable()
{
}

//visible//
inline bool Actors::Get_Visible()
{
	return 0;
}
inline void Actors::Set_Visible()
{
}
#pragma endregion

#pragma region Gets and Sets | Props
//ID//
inline int Props::Get_ID()
{
	return 0;
}
inline void Props::Set_ID()
{
}

//Type//
inline int Props::Get_Type()
{
	return 0;
}
inline void Props::Set_Type()
{
}

//Name//
inline string Props::Get_Name()
{
	return string();
}
inline void Props::Set_Name()
{
}

//Glyth//
inline char Props::Get_Glyth()
{
	return 0;
}
inline void Props::Set_Glyth()
{
}

//Equippable//
inline bool Props::Get_Equippable()
{
	return false;
}
inline void Props::Set_Equippable()
{
}
#pragma endregion

#pragma region Gets and Sets | Sets
//Color//
inline int Set::Get_Colour()
{
	return 0;
}
inline void Set::Set_Colour()
{
}

//Damage//
inline int Set::Get_Damage()
{
	return 0;
}
inline void Set::Set_Damage()
{
}

//Glyth//
inline char Set::Get_Glyth()
{
	return 0;
}
inline void Set::Set_Glyth()
{
}

//Attackable//
inline bool Set::Get_Attackable()
{
	return false;
}
inline void Set::Set_Attackable()
{
}

//Walkable//
inline bool Set::Get_Walkable()
{
	return false;
}
inline void Set::Set_Walkable()
{
}

//Visible//
inline bool Set::Get_Visible()
{
	return false;
}
inline void Set::Set_Visible()
{
}

//Damaging//
inline bool Set::Get_Damaging()
{
	return false;
}
inline void Set::Set_Damaging()
{
}
#pragma endregion


//----------------------------------//
//Bags//
//These are used to store the numerous Creatures, Objects and Destructable Enviroments in the game.
vector<Actors> ActorBag;
vector<Props> PropBag;
vector<Set> SetBag;