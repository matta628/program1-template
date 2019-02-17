#include "Planet.h"
#include <stdlib.h>
#include <cstdio>

Planet::Planet(int d){
	this->id = 0;
	this->distance = d;
	this->pos = rand() % 360;
	int randType = rand() % 3;
	if (randType == 0)
		this->type = 'h';
	else if (randType == 1)
		this->type = 'r';
	else
		this->type = 'g';
}

int Planet::orbit(){
    if (this->pos >=0 && this->pos <= 359){
	this->pos++;
    }
    if (this->pos == 360)
	this->pos = 0;
    return this->pos;
}

long Planet::getID(){
	this->id = &this;
	return this->id;
}
