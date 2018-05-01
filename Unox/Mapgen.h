#ifndef _MAPGEN_H_    // To make sure you don't declare the function more than once by including the header multiple times.
#define _MAPGEN_H_

#include <random>
#include <vector>
#include <iostream>
#include "Actors.h"

extern void Map_Gen();

void Room(int X, int Y, int width, int height);

#endif