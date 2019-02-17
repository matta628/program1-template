#ifndef Star_h
#define Star_h

#include "Planet.h"

class Star{
 private:
	int current_planets;
 public:
	Planet ** planets;
	Star();
	~Star();
	int addPlanet();
	bool removePlanet(int);
	Planet * getPlanet(int);
	void orbit();
	void printStarInfo();
	int getCurrentNumPlanets(){ return this->current_planets;}
};

#endif
 
