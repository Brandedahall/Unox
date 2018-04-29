#ifndef _MAPGEN_H_    // To make sure you don't declare the function more than once by including the header multiple times.
#define _MAPGEN_H_

#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

extern void Num_Gen();
extern void Corridor();
extern void Room(int x, int y, int xmax, int ymax);
extern int getRand(int min, int max);

#endif