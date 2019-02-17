#ifndef Starvector_H
#define Starvector_H

#include "Planet.h"
#include "Star.h"
#include "Vector.h"

class Starvector{
 private:
	int current_planets;
 public:
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
