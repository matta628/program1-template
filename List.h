#ifndef HEADER_DLL
#define HEADER_DLL
class Node{
	Node();
	~Node();

};

class List{
private:
	int current_planets;
	Node * tail;
	Node * head;	
	~List();

public:
	List();
	void insert(int, Planet *);
	Planet* read(int);
	bool remove(int);
	unsigned size();
};
#endif
