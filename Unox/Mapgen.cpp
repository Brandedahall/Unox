#include "Mapgen.h"
#include <vector>
#include "Actors.h"
#include <random>
#include <iostream>

using namespace std;

std::random_device rd;
std::mt19937 mt(rd());

int randomInt(int exclusiveMax)
{
	std::uniform_int_distribution<> dist(0, exclusiveMax - 1);
	return dist(mt);
}

int randomInt(int min, int max) // inclusive min/max
{
	std::uniform_int_distribution<> dist(0, max - min);
	return dist(mt) + min;
}

bool randomBool(double probability = 0.5)
{
	std::bernoulli_distribution dist(probability);
	return dist(mt);
}

struct Rect
{
	int x, y;
	int width, height;
};
