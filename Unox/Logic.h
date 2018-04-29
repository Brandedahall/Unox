#ifndef _LOGIC_H_    // To make sure you don't declare the function more than once by including the header multiple times.
#define _LOGIC_H_


//Logic//
inline void ActorLogic();
inline void PropLogic();
inline void SetLogic();

extern void GameStart();
inline void Keyboard();
inline void Map();
void MapFill();

void UI();

void Init_Map();


//Extern Variables
extern bool ActorWalk;
extern bool SetWalk;
#endif