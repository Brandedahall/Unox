#ifndef _LOGIC_H_    // To make sure you don't declare the function more than once by including the header multiple times.
#define _LOGIC_H_



//Logic//
inline void ActorLogic();
inline void PropLogic();
inline void SetLogic();

extern void GameStart();
inline void Keyboard();
inline void K_Look();
inline void Map();
void MapFill();



void UI();

void Init();

void Move_Camera(int x, int y);

bool DoFov(int x, int y);
void FOV();

void Log();

extern void DescriptionFactory(Actors Creature_Recieving, Actors Creature_Dealing);

std::string Weaponadverb[] = { "Awesomely", "Greatly", "Badly", "Super", "Ultra", "Mega", "Horrifyingly", "Accurately", "Very", "Really", "Disappointingly", "Seriously", "Willingly", "Sufficiently", "Largely", "Unbelievably", "Primarily", "Interestingly", "Brightly", "Secretly", "Downright", "Naturally", "Fairly", "Easily", "Intensely", "Blatantly", "Additionally", "Necessarily", "Truly", "Scarcely", "Hardly", "Significantly", "Curiously", "Happily", "Relatively", "Vastly", "Eminently", "Satisfactorily", "Ultimately", "Unbearably", "Awfully", "Intimately", "Desperately", "Conclusively", "Exhaustively", "Erratically", "Enigmatically", "Sarcastically" };

std::string WeaponAD[] = { "Powerful", "Horrible", "Bad", "Great", "Developed", "Killer", "Cool", "Stupid", "Battle",  "Awesome",  "Persistant",  "Accurate",  "Named",  "Useful",  "Frightning",  "Idiotic",  "Legendary",  "Dumb",  "Spiked",  "Enjoyable",  "Overlooked",  "Sickening",  "Unnecessary",  "Hardcore",  "Evil",  "Good",  "Maniacal",  "Devious",  "Overpowered",  "Underpowered",  "Mediocre",  "Mohawk",  "Invincible",  "Hipster",  "Gangsta",  "Sharp",  "Unsafe",  "Godlike", "Weird", "Hot", "Chaotic", "Smelly", "Bizarre", "Mighty", "Cardboard", "Deadly", "Soft",  "Potent",  "Suppressive",  "Death-dealing",  "Irritating",  "Explosive", };

std::string WeaponNouns[] = { "Smelling",  "Cooling",  "Flipping",  "Killing",  "Dehydrating",  "Doom",  "Destruction",  "Destroying",  "Poisoning",  "Electrocution",  "Freezing", "Execution",  "Decapitation",  "Eradication",  "Avenging",  "Torture",  "Horror",  "Pain",  "Demolition",  "Deprivation",  "Judgement",  "Disease" };

string Wtype[] = { "Sword", "Axe", "Daggers", "Spear", "Scythe" };

string WeaponEle[] = { "Normal", "Earth", "Fire", "Ice", "Air", "Electric", };


//Extern Variables
extern bool ActorWalk;
extern bool SetWalk;

extern int Turn_Timer;

extern int camera_x, camera_y;

#define Camera_Width 65
#define Camera_Height 30

#define Map_Width 425
#define Map_Height 200

#endif