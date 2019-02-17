#include "Starvector.h"
#include "Star.h"
#include "Planet.h"
#include "Vector.h"

Starvector::Starvector(){
	//Initialize memory
	Vector star = new Vector();
}

Starvector::~Starvector(){
	//Deallocate all memory when the star is deleted.
	delete star;
}

long Starvector::addPlanet(){
	//Return the ID of the newly created Planet
	return star.addPlanet();
}

bool Starvector::removePlanet(int id){
	//Takes a Planet's ID as a parameter, and rmeoves the Planet from the Star.
	//You must return ture upon successful deletion and false on failure if the ID isn't found
}

Planet * Starvector::getPlanet(int id){
	//Takes a Planet's ID and returns a pointer to the Planet. If the Planet is not found, it returns NULL
}

void Starvector::orbit(){
	//Iterate through your planets and alter their orbit position by +1
}

void Starvector::printStarInfo(){
	//Prints the Star information
}

unsigned int getCurrentNumPlanets(){
	//Returns the current number of planets stored (the size of the vector)
}
