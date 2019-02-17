#ifndef Starvector_H
#define Starvector_H

#include "Planet.h"
#include "Vector.h"

class Starvector{
 public:
	Vector * star;
	Starvector();
	~Starvector();
	long addPlanet();
	bool removePlanet(int);
	Planet * getPlanet(int);
	void orbit();
	void printStarInfo();
	unsigned int getCurrentNumPlanets();
};

#endif
