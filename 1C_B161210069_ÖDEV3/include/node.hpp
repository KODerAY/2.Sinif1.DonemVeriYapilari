#ifndef node_hpp
#define node_hpp
#include<iostream>
#include "eList.hpp"
using namespace std;
class node{
	
private:
	node* _right;
	node* _left;
	node* _root;
	int _data;
	
public:
	//CONSTRUCTORS
	node(node*, node*);
	node();
	
	// DESTRUCTOR
	~node();

	//FUNCTIONS;
	node* Right();
	void Right(node*);
	
	node* Left();
	void Left(node*);
	
	node* Root();
	void Root(node*);
	
	int Data();
	void Data(int);
};


#endif