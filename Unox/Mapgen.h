#ifndef _MAPGEN_H_    // To make sure you don't declare the function more than once by including the header multiple times.
#define _MAPGEN_H_

#include <random>
#include <vector>
#include <iostream>
#include "Actors.h"
#include <cstddef>  // size_t

//Perlin Noise\\

class PerlinNoise {
// The permutation vector
std::vector<int> p;
public:
	// Initialize with the reference values for the permutation vector
	PerlinNoise();
	// Generate a new permutation vector based on the value of seed
	PerlinNoise(unsigned int seed);
	// Get a noise value, for 2D images z can have any value
	double noise(double x, double y, double z);
private:
	double fade(double t);
	double lerp(double t, double a, double b);
	double grad(int hash, double x, double y, double z);
};

void gen_Perlin(const unsigned int &seed);
void MapMaker(const unsigned int &seed);
void TileSelect(int i, int j, double n);
#endif