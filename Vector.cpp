#include "Vector.h"

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
	if (index <= current_planets){
		Planet ** updated = new Planet*[current_planets + 1];
		for (int i = 0; i < index; i++){
			updated[i] = planets[i];
		}
		updated[index] = p;
		for (int i = index+1; i < current_planets + 1; i++){
			updated[i] = planets[i];
		}
	}
	else if (index == current_planets)
}

Planet* Vector::read(int index){
	
}

bool Vector::remove(int index){
	
}

unsigned Vector::size(){
	return 
}

