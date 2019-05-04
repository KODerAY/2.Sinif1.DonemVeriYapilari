#ifndef doublyLinked_hpp
#define doublyLinked_hpp
#include<iostream>
#include "eList.hpp"
#include "node.hpp"
using namespace std;
class doublyLinked{
	
private:
	node* _top;
	int _count;
	
public:
	//CONSTRUCTORS
	doublyLinked(eList<string>*, string*);
	// DESTRUCTOR
	~doublyLinked();
	//TOP
	node*& Top();
	//COUNT
	int Count();
	void Count(int);

	//FUNCTIONS
	node* getItem(int);
	void addItem(node*, int);
	void deleteItem(int);
	
	//MOVE
	void moveRight();
	void moveLeft();	
};


#endif