#include "List.h"
// Node
Node::Node(){
	this->head;
	this->current;
	this->prev;
	this->next;
}
// List
List::List(){
	this->head = NULL; // Node * head; in List.h
	this->tail = NULL;
	this->current_planets = 0;
}

List::~List(){
	for(int i = 0; i < this->current_planets; i++){
		
	}
	delete this->head;
}

void List::insert(int index, Planet * p){
	Node n = new Node();
	n->current = &p;
/*	if(index == 0){
		n->next = this->head;
		this->head->prev = n;
		this->head = n;
	}*/
	else if(index == this->current_planets){
		n->prev = this->tail;
		tail->next = n;
		this->tail = n;
	}	
	else if(index <= this->current_planets){
		Node tempNode = this->head;
		for(int i = 0; i < index; i++){
			tempNode = tempNode->next;
		}//tempNode should now rep the Node at the index
		n->next = tempNode->next;
		tempNode->next = n;
		n->prev = tempNode;
		n->next->prev = n;
	}
}

Planet* read(int index){
	if(index > this->current_planets) return false;
	Node tempNode = this->head;
	for(int i = 0; i < index - 1; i++){
		tempNode = tempNode->next;
	}
	return tempNode; // tempNode->next;
}

bool List::remove(int index){
	if(index > this->current_planets) return false;
	Node tempNode = this->head;
	for(int i = 0; i < index - 1; i++){
		tempNode = tempNode->next;
	}
	delete tempNode;//tempNode->next;
	this->current_planets -= 1;
	return true;
}

unsigned List::size(){ // returns current size of list
	return this->current_planets;
}
