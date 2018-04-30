#ifndef _ACTORS_H_    // To make sure you don't declare the function more than once by including the header multiple times.
#define _ACTORS_H_

#include <vector>

using namespace std;
//----------------------------------//
class Props
{
public:
	//Constructor and destructor.
	Props(int X, int Y, char Glyth, int ID, string Name);
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

class Actors
{
public:
	//Constructor and destructor.
	Actors(string Name, int X, int Y, char Glyth, bool Visible, bool Walkable, int ID, int Type);
	~Actors();

	//Gets and sets for the private variables.
	#pragma region Gets and Sets
	int Get_Location_X();
	void Set_Location_X(int x);

	int Get_Location_Y();
	void Set_Location_Y(int y);

	int Get_Health();
	void Set_Health(int health);

	int Get_Mana();
	void Set_Mana(int mana);

	int Get_Strength();
	void Get_Strength(int strength);

	int Get_Wisdom();
	void Set_Wisdom(int wisdom);

	int Get_Agility();
	void Set_Agility(int agility);

	int Get_Intelligence();
	void Set_Intelligence(int intelligence);

	int Get_Perception();
	void Set_Perception(int perception);

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

	int Get_Level();
	void Set_Level(int level);

	int Get_Experience();
	void Set_Experience(int experience);

	bool Get_Attackable();
	void Set_Attackable(bool attackable);

	bool Get_Walkable();
	void Set_Walkable(bool walkable);

	bool Get_Visible();
	void Set_Visible(bool visible);

	bool Get_Logic();
	void Set_Logic(bool logic);
	#pragma endregion

	void AI();
	void Movement();
	vector<Props> Get_Inventory();
	void Set_Inventory(Props Item);
protected:
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

	//Stats and RPG stuff//
	int Health;  //Health of the creature.
	int Level;
	int Experience;
	int Mana; //How much Magical points the creature has.
	//Attributes
	int Strength; //How much Strength the creature has.
	int Wisdom; //How much Wisdom the creature has.
	int Agility; //How much Agility the creature has.
	int Intelligence; //How much Intelligence the creature has.
	int Perception; //How much Perception the creature has.

	//Contents
	vector<Props> Inventory; //Holds all of the creature's inventory.
};

//----------------------------------//

class Sets
{
public:
	//Constructor and destructor.
	Sets();
	Sets(int X, int Y, char Glyth, bool Visible, int ID, bool Walkable, int Type);
	~Sets();

	#pragma region Gets and Sets
	//Gets and sets for the private variables.

	int Get_Location_X();
	int Get_Location_Y();

	int Get_Type();

	int Get_Damage();
	void Set_Damage(int Damage);

	char Get_Glyth();
	void Set_Glyth(char Glyth);

	bool Get_Attackable();
	void Set_Attackable(bool Attackable);

	bool Get_Walkable();
	void Set_Walkable(bool Walkable);

	bool Get_Visible();
	void Set_Visible(bool Visible);

	bool Get_Damaging();
	void Set_Damaging(bool Damaging);
	#pragma endregion

	//Methods//
	vector<Props> Get_Inventory();
	void Set_Inventory(Props Item);

private:
	//Int//
	int X;
	int Y;
	int Damage; //If a character walks across a floor which has 'Damaging' set to true.
	int ID; //The ID of the set object.
	int Type;

	//Char//
	char Glyth; //The visible character which is drawn to the screen.

	//Bool//
	bool Attackable;
	bool Visible; //Whether the Set object is visible to the character/screen.
	bool Movable; //Whether characters can move the prop.
	bool Walkable;//Whether characters can walk through the prop.
	bool Damaging; //Whether the prop damages an actor if the actor walks across it.
	vector<Props> Inventory; //Holds all of the creature's inventory.
};

//----------------------------------//
//Gets and sets//

#pragma region Gets and sets | Actors

#pragma region Normal G+S
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

inline int Actors::Get_Level()
{
	return Level;
}

inline void Actors::Set_Level(int level)
{
	Level += level;
}

inline int Actors::Get_Experience()
{
	return Experience;
}

inline void Actors::Set_Experience(int experience)
{
	Experience = experience;
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
	X += x;
}

inline int Actors::Get_Location_Y()
{
	return Y;
}

inline void Actors::Set_Location_Y(int y)
{
	Y += y;
}

#pragma endregion

//Stats//
inline int Actors::Get_Health()
{
	return Health;
}

inline void Actors::Set_Health(int health)
{
	Health = health;
}

inline int Actors::Get_Mana()
{
	return Mana;
}

inline void Actors::Set_Mana(int mana)
{
	Mana = mana;
}
//Attributes//
inline int Actors::Get_Strength()
{
	return Health;
}

inline void Actors::Get_Strength(int strength)
{
	Strength = strength;
}

inline int Actors::Get_Wisdom()
{
	return Wisdom;
}

inline void Actors::Set_Wisdom(int wisdom)
{
	Wisdom = wisdom;
}

inline int Actors::Get_Agility()
{
	return Agility;
}

inline void Actors::Set_Agility(int agility)
{
	Agility = agility;
}

inline int Actors::Get_Intelligence()
{
	return Intelligence;
}

inline void Actors::Set_Intelligence(int intelligence)
{
	Intelligence = intelligence;
}

inline int Actors::Get_Perception()
{
	return Perception;
}

inline void Actors::Set_Perception(int perception)
{
	Perception = perception;
}

inline vector<Props> Actors::Get_Inventory()
{
	return Inventory;
}

inline void Actors::Set_Inventory(Props Item)
{
	Inventory.push_back(Item);
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
//Type//
inline int Sets::Get_Type()
{
	return Type;
}
//Damage//
inline int Sets::Get_Damage()
{
	return Damage;
}
inline void Sets::Set_Damage(int damage)
{
	Damage = damage;
}
//Glyth//
inline char Sets::Get_Glyth()
{
	return Glyth;
}
inline void Sets::Set_Glyth(char glyth)
{
	Glyth = glyth;
}

//Attackable//
inline bool Sets::Get_Attackable()
{
	return Attackable;
}
inline void Sets::Set_Attackable(bool attackable)
{
	Attackable = attackable;
}

//Walkable//
inline bool Sets::Get_Walkable()
{
	return Walkable;
}
inline void Sets::Set_Walkable(bool walkable)
{
	Walkable = walkable;
}

//Visible//
inline bool Sets::Get_Visible()
{
	return Visible;
}
inline void Sets::Set_Visible(bool visible)
{
	Visible = visible;
}

//Damaging//
inline bool Sets::Get_Damaging()
{
	return Damaging;
}
inline void Sets::Set_Damaging(bool damaging)
{
	Damaging = damaging;
}

//Location
inline int Sets::Get_Location_X()
{
	return X;
}

inline int Sets::Get_Location_Y()
{
	return Y;
}


inline vector<Props> Sets::Get_Inventory()
{
	return Inventory;
}

inline void Sets::Set_Inventory(Props Item)
{
	Inventory.push_back(Item);
}

#pragma endregion

//----------------------------------//

#pragma region Methods definitions
//These methods create new Actors, Props, and Sets.
void New_Actor(string Name, int X, int Y, char Glyth, bool Visible, bool Walkable, int Type);
void New_Prop(int X, int Y, char Glyth, string Name);
void New_Set(int X, int Y, char Glyth, bool Visible, bool Walkable, int Type);

bool walk(int X, int Y);
#pragma endregion
//----------------------------------//
//Bags//
//These are used to store the numerous Creatures, Objects and Destructable Enviroments in the game.
extern vector<Actors> ActorBag;
extern vector<Props> PropBag;
extern vector<vector<Sets>> SetBag;
extern vector<vector<Sets>> Overworld;

//IDs for the objects within the bags. Just in case they need to be found using ID's. Possibly for time-sensitive spells, lasting damage etc.
extern int ActorID;
extern int ProbID;
extern int SetID;
#endif