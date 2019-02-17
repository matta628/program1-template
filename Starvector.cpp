#include "Starvector.h"
#include "Star.h"
#include "Planet.h"
#include "Vector.h"

#include <stdlib.h>
#include <cstdio>

Starvector::Starvector(){
	this->star = new Vector();
}

Starvector::~Starvector(){
	delete star;
}

long Starvector::addPlanet(){
	Planet * p = new Planet(rand() % 3000 + 1);
	star.insert(star->size(), p);
	return p->getID();
}

bool Starvector::removePlanet(int id){
	for (int i = star->size() - 1; i >= 0; i--){
		if (star->read(i)->getID() == id){
			star->remove(i);
			return true;
		}
	}
	return false;
}

Planet * Starvector::getPlanet(int id){
	for (int i = star->size() -1; i >= 0; i++){
		if (star->read(i)->getID() == id)
			return star->read(i);
	}
	return NULL;
}

void Starvector::orbit(){
	for (int i = 0; i < star->size(); i++){
		star->read(i)->orbit();
	}
}

void Starvector::printStarInfo(){
	if (star->size() == 1){
		printf("The star has 1 planet.\n");
	}
	else{
		printf("The star has %d planets.\n", star->size());
	}
	printf("Planets:\n");
	for (int i = 0; i < star->size(); i++){
		printf("Planet %c%d is %d million miles away at position %d around the star.\n",
			   star->read(i)->getType(), i, star->read(i)->getDistance(), star->read(i)->getPos());
	}
}

unsigned int getCurrentNumPlanets(){
	return star->size();
}
