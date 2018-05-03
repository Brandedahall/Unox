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
void FOV();

void UI();

void Init_Map();

void Move_Camera(int x, int y);

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