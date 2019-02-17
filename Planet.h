#ifndef Planet_h
#define Planet_h

class Planet{
 private:
	long id;
	int pos;
	int distance;
	char type;
 public:
	Planet(int);
	int orbit();
	long getID();
	int getDistance(){return this->distance;}
	int getPos(){return this->pos;}
	char getType(){return this->type;}
};

#endif 
