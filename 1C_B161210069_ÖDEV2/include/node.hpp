#ifndef node_hpp
#define node_hpp
#include<iostream>
#include "eList.hpp"
using namespace std;
class node{
	
private:
	eList<string>* _dataList;
	string* _data;
	node* _right;
	node* _left;
	
public:
	//CONSTRUCTORS
	node(eList<string>*, string*, node*, node*);
	node(eList<string>*, string*);
	
	// DESTRUCTOR
	~node();

	//FUNCTIONS
	eList<string>*& DataList();
	string*& Data();
	node* Right();
	void Right(node*);
	
	node* Left();
	void Left(node*);
};


#endif