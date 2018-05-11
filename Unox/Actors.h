#ifndef _ACTORS_H_    // To make sure you don't declare the function more than once by including the header multiple times.
#define _ACTORS_H_

#include <vector>

//---------Base classes-------------//
class Props
{
public:
	//Constructor and destructor.
	Props();
	Props(int X, int Y, char Glyth, int ID, std::string Name);
	~Props();

#pragma region Gets and Sets
	//Gets and sets for the private variables.

	int Get_Location_X();
	void Set_Location_X(int X);

	int Get_Location_Y();
	void Set_Location_Y(int Y);

	bool Get_Exists();
	void Set_Exists(bool Exists);

	int Get_ID();
	void Set_ID(int ID);

	int Get_Type();
	void Set_Type(int Type);

	std::string Get_Name();
	void Set_Name(std::string Name);

	std::string Get_Description();
	void Set_Get_Description(std::string Description);

	char Get_Glyth();
	void Set_Glyth(char Glyth);

	bool Get_Equippable();
	void Set_Equippable(bool Equippable);
#pragma endregion

	void Draw();

protected:
	//Int//
	int X;
	int Y;
	int ID; //The ID of the Prop object.
	int Type; //Uses a lookup table to determine the type of object.

			  //String//
	std::string Name; //Name of the Prop.
	std::string Description; //Description of the Prop.

				 //Char//
	char Glyth; //The visible character which is drawn to the screen.

				//Bool//
	bool Equippable; //Checks whether the item can be equipped or not.

	bool Exists;
};

class Actors
{
public:
	//Constructor and destructor.
	Actors(std::string Name, int X, int Y, char Glyth, bool Visible, bool Walkable, int ID, int Type, char* color);
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
	void Set_Strength(int strength);

	int Get_Willpower();
	void Set_Willpower(int willpower);

	int Get_Agility();
	void Set_Agility(int agility);

	int Get_Intelligence();
	void Set_Intelligence(int intelligence);

	int Get_Perception();
	void Set_Perception(int perception);

	std::string Get_Name();
	void Set_Name(std::string name);

	unsigned char Get_Glyth();
	void Set_Glyth(unsigned char glyth);

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

	const char* Get_Color();
	void Set_Color(char* color);

	#pragma endregion

	void Draw();
	void Camera_Coords(int x, int y);
	void AI();
	void Movement();
	std::vector<Props> Get_Inventory();
	void Set_Inventory(Props Item);
	int Get_FOV();
	void Set_FOV(int View_Radius);
protected:
	//Int//
	int X; //X and Y coordinates for each Actor.
	int Y;

	int ID; //The Id of the Actor.
	int Reach; //How far the Actor can attack from.
	int Type; //Uses a lookup table to determine the type of Actor.

	const char* Color;

	//String//
	std::string Name; //Name of the actor.

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
	int Willpower; //How much Wisdom the creature has.
	int Agility; //How much Agility the creature has.
	int Intelligence; //How much Intelligence the creature has.
	int Perception; //How much Perception the creature has.

	int View_Radius;

	//Contents
	std::vector<Props> Inventory; //Holds all of the creature's inventory.
};

class Sets
{
public:
	//Constructor and destructor.
	Sets();
	Sets(int X, int Y, char Glyth, bool Visible, int ID, bool Walkable, int Type, bool Wall);
	~Sets();

	#pragma region Gets and Sets
	//Gets and sets for the private variables.
	int Get_Type();

	int Get_Location_X();
	int Get_Location_Y();

	int Get_Damage();
	void Set_Damage(int Damage);

	char Get_Glyth();
	void Set_Glyth(char Glyth);

	bool Get_Walkable();
	void Set_Walkable(bool Walkable);

	bool Get_Visible();
	void Set_Visible(bool Visible);

	bool Get_Damaging();
	void Set_Damaging(bool Damaging);

	bool Get_Fog();
	void Set_Fog(bool Fog);

	bool Get_Placement();

	bool Get_Wall();

	#pragma endregion

	//Methods//
	std::vector<Props> Get_Inventory();
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
	bool Placement; //Is it placed down//
	bool Wall; //Is it a wall?
	bool Visible; //Whether the Set object is visible to the character/screen.
	bool Movable; //Whether characters can move the prop.
	bool Walkable; //Whether characters can walk through the prop.
	bool Damaging; //Whether the prop damages an actor if the actor walks across it.
	bool Fog;
	std::vector<Props> Inventory; //Holds all of the creature's inventory.
};

//----------Derived Classes---------//
#pragma region Derived Classes
class Weapon : Props
{
public:
	int GetDamage();
	void SetDamage(int Damage);

	int GetPrice();
	void SetPrice(int Price);

	std::string GetDescription();
	void SetDescription(std::string Description);


private:
	int Damage;
	int Price;
	std::string Description;
};

class Armor : Props
{
public:
	int GetArmourValue();
	void SetArmourValue(int ArmourValue);

	int GetPrice();
	void SetPrice(int Price);

	std::string GetDescription();
	void SetDescription(std::string Description);
private:
	int ArmourValue;
	int Price;
	std::string Description;
};

class Item : Props
{

};
#pragma endregion

//----------------------------------//
//Gets and sets - Base Classes//

#pragma region Gets and sets | Actors

inline int Actors::Get_FOV()
{
	return View_Radius;
}

inline void Actors::Set_FOV(int view_radius)
{
	View_Radius = view_radius;
}

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
inline std::string Actors::Get_Name()
{
	return Name;
}
inline void Actors::Set_Name(std::string name)
{
	Name = name;
}

//Glyth
inline unsigned char Actors::Get_Glyth()
{
	return Glyth;
}
inline void Actors::Set_Glyth(unsigned char glyth)
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

//Location//
inline int Actors::Get_Location_Y()
{
	return Y;
}

inline void Actors::Set_Location_Y(int y)
{
	Y += y;
}

//Color//
inline const char* Actors::Get_Color()
{
	return Color;
}

inline void Actors::Set_Color(char* color)
{
	Color = color;
}


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
	return Strength;
}

inline void Actors::Set_Strength(int strength)
{
	Strength = strength;
}

inline int Actors::Get_Willpower()
{
	return Willpower;
}

inline void Actors::Set_Willpower(int willpower)
{
	Willpower = willpower;
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

inline std::vector<Props> Actors::Get_Inventory()
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
inline void Props::Set_ID(int id)
{
	ID = id;
}

//Exists//
inline bool Props::Get_Exists()
{
	return Exists;
}

inline void Props::Set_Exists(bool exists)
{
	Exists = exists;
}

//Description//
inline std::string Props::Get_Description()
{
	return Description;
}
inline void Props::Set_Get_Description(std::string description)
{
	Description = description;
}

//Type//
inline int Props::Get_Type()
{
	return Type;
}
inline void Props::Set_Type(int type)
{
	Type = type;
}

//Name//
inline std::string Props::Get_Name()
{
	return Name;
}
inline void Props::Set_Name(std::string name)
{
	Name = name;
}

//Glyth//
inline char Props::Get_Glyth()
{
	return Glyth;
}
inline void Props::Set_Glyth(char glyth)
{
	Glyth = glyth;
}

//Equippable//
inline bool Props::Get_Equippable()
{
	return Equippable;
}
inline void Props::Set_Equippable(bool equippable)
{
	Equippable = equippable;
}

//Location
inline int Props::Get_Location_X()
{
	return X;
}

inline void Props::Set_Location_X(int x)
{
	X = x;
}

inline int Props::Get_Location_Y()
{
	return Y;
}

inline void Props::Set_Location_Y(int y)
{
	Y = y;
}
#pragma endregion

#pragma region Gets and Sets | Sets
//Wall//
inline bool Sets::Get_Wall()
{
	return Wall;
}

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

inline bool Sets::Get_Placement()
{
	return Placement;
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


inline std::vector<Props> Sets::Get_Inventory()
{
	return Inventory;
}

inline void Sets::Set_Inventory(Props Item)
{
	Inventory.push_back(Item);
}

inline bool Sets::Get_Fog()
{
	return Fog;
}

inline void Sets::Set_Fog(bool fog)
{
	Fog = fog;
}

#pragma endregion

//----------------------------------//
//Gets and sets - Derived Classes//
#pragma region Gets and sets | Weapons
inline int Weapon::GetDamage()
{
	return Damage;
}

inline void Weapon::SetDamage(int damage)
{
	Damage = damage;
}

inline int Weapon::GetPrice()
{
	return Price;
}
inline void Weapon::SetPrice(int price)
{
	Price = price;
}

inline std::string Weapon::GetDescription()
{
	char const *pchar = Description.c_str();
	return pchar;
}
inline void Weapon::SetDescription(std::string description)
{
	Description = description;
}

#pragma endregion

#pragma region Gets and sets | Armour

inline int Armor::GetArmourValue()
{
	return ArmourValue;
}

inline void Armor::SetArmourValue(int armourValue)
{
	ArmourValue = armourValue;
}

inline int Armor::GetPrice()
{
	return Price;
}
inline void Armor::SetPrice(int price)
{
	Price = price;
}

inline std::string Armor::GetDescription()
{
	char const *pchar = Description.c_str();
	return pchar;
}
inline void Armor::SetDescription(std::string description)
{
	Description = description;
}

#pragma endregion

#pragma region Gets and sets | Items

#pragma endregion

//----------------------------------//
//These methods create new Actors, Props, and Sets.
#pragma region Methods definitions
void New_Actor(std::string Name, int X, int Y, char Glyth, bool Visible, bool Walkable, int Type, char* Color);
void New_Prop(int X, int Y, char Glyth, std::string Name);
void New_Set(int X, int Y, char Glyth, bool Visible, bool Walkable, int Type, bool Wall, bool Placement);
void Change_Set(int X, int Y, char Glyth, bool Visible, bool Walkable, int Type, bool Wall, bool Placement);

bool walk(int X, int Y);
#pragma endregion

#pragma region Constructors
//Base Constructors//
inline Actors::Actors(std::string name, int x, int y, char glyth, bool visible, bool walkable, int id, int type, char* color)
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
	Color = color;
}

inline Actors::~Actors()
{
}

inline Props::Props()
{
	Exists = false;
}

inline Props::Props(int x, int y, char glyth, int id, std::string name)
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

inline Sets::Sets()
{
	Placement = false;
	Glyth = 0x00;
	Wall = false;
}

inline Sets::Sets(int x, int y, char glyth, bool visible, int id, bool walkable, int type, bool wall)
{
	X = x;
	Y = y;
	Glyth = glyth;
	Visible = visible;
	ID = id;
	Walkable = walkable;
	Type = type;
	Wall = wall;
	Placement = true;
}

inline Sets::~Sets()
{

}

#pragma endregion

//----------------------------------//
#pragma region Bags
//These are used to store the numerous Creatures, Objects and Destructable Enviroments in the game.
extern std::vector<Actors> ActorBag;
extern std::vector<Props> PropBag;
extern std::vector<std::vector<Sets>> SetBag;
extern std::vector<std::vector<Sets>> Overworld;

//IDs for the objects within the bags. Just in case they need to be found using ID's. Possibly for time-sensitive spells, lasting damage etc.
extern int ActorID;
extern int ProbID;
extern int SetID;
#pragma endregion

#endif