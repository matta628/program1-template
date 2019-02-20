#include "Vector.h"
#include "Planet.h"
#include <stdlib.h>
#include <cstdio>

Vector::Vector(){
	this->planets = NULL;
	this->current_planets = 0;
}


Vector::~Vector(){
	for (int i = 0; i < current_planets; i++){
		delete planets[i];
		planets[i] = NULL;
	}
	delete[] planets;
}

void Vector::insert(int index, Planet * p){
	if (index < current_planets){
		Planet ** updated = new Planet*[current_planets];
		for (int i = 0; i < current_planets; i++){
			if (i != index)
				updated[i] = planets[i];
			else
				updated[index] = p;
		}
		delete[] planets;
		this->planets = updated;
	}
	else if (index == current_planets){
		Planet ** updated = new Planet*[++current_planets];
		for (int i = 0; i < index; i++)
			updated[i] = planets[i];
		updated[index] = p;
		delete[] planets;
		this->planets = updated;
	}
}

Planet* Vector::read(int index){
	if (index < 0 ||  index >= current_planets){
		return NULL;
	}
	return planets[index];
}

bool Vector::remove(int index){
	if (index >= 0 && index < current_planets){
		Planet ** updated = new Planet*[--current_planets];
		int updatedIndex = 0;
		for (int i = 0; i < this->current_planets + 1; i++){
			if (i == index){
				delete planets[index];
				planets[index] = NULL;
			}else{
				updated[updatedIndex++] = planets[i];
			}
		}
		delete[] planets;
		this->planets = updated;
		return true;
	}
	return false;
}

unsigned int Vector::size(){
	return this->current_planets;
}

