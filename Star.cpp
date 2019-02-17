#include "Star.h"
#include "Planet.h"
#include <stdlib.h>
#include <cstdio>

Star::Star(){
	this->current_planets = 0;
	this->planets = NULL; //initialize planets array pointer to NULL
}

Star::~Star(){
	for (int i = 0; i < current_planets; i++){
		delete planets[i]; //deallocate each planet
		planets[i] = NULL; //set each planet to NULL
	}
	delete[] planets; //deallocate planets array pointer
}

int Star::addPlanet(){
	Planet ** updated = new Planet*[current_planets + 1]; //allocate new array pointer
	Planet *p = new Planet(rand() % 3000 + 1); //create new planet object
	for (int i = 0; i < current_planets; i++){ 
		updated[i] = planets[i]; //copy all pointers to the new array
	}
	updated[current_planets++] = p; //put new planet in new array and update num planets
	delete[] planets; //deallocate old planets array pointer
	this->planets = updated; //point planets to new array
	return p->getID();
}

bool Star::removePlanet(int id){
	int targetIndex = -1;
	for (int i = 0; i < current_planets; i++){ 
		if (planets[i]->getID() == id){ 
			targetIndex = i;
		}
	}
	if (targetIndex < 0 || current_planets == 0){ 
		return false;
	}
	Planet ** updated = new Planet*[current_planets - 1]; //allocate new array pointer 
	int planetIndex = 0;
	for (int j = 0; j < current_planets; j++){ 
		if (j == targetIndex){ 
			delete planets[j]; //deallocate target planet
			planets[j] = NULL; //set target planet to null
			continue;
		}
		updated[planetIndex++] = planets[j]; //copy pointers to new array
	}
	this->current_planets--; //update num planets
	delete[] planets; //deallocate old array
	this->planets = updated; //point planets to the new array
	return true;
}

Planet* Star::getPlanet(int id){
	for (int i = 0; i < current_planets; i++){
		if (planets[i]->getID() == id){
			return planets[i];
		}
	}
	return NULL;
}

void Star::orbit(){
	for (int i = 0; i < current_planets; i++){
		this->planets[i]->orbit();
	}
}

void Star::printStarInfo(){
	if (current_planets == 1){
		printf("The star has 1 planet.\n");
	}
	else{
		printf("The star has %d planets.\n", current_planets);
	}
	printf("Planets:\n");
	for (int i = 0; i < current_planets; i++){
		printf("Planet %c%d is %d million miles away at position %d around the star.\n",
			   planets[i]->getType(), i, planets[i]->getDistance(), planets[i]->getPos());
	}
}



