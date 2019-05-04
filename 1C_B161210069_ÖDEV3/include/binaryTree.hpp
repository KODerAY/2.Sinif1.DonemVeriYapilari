#ifndef binaryTree_hpp
#define binaryTree_hpp
#include<iostream>
#include "eList.hpp"
#include "node.hpp"
using namespace std;
class binaryTree{
	
private:
	node* _top;
	binaryTree* _next;
	
public:
	//CONSTRUCTORS
	binaryTree();
	// DESTRUCTOR
	~binaryTree();
	//TOP
	node*& Top();
	//NEXT
	binaryTree*& Next();

	//FUNCTIONS
	node* getNodeMax();
	node* getNodeMin();
	void deleteNodeMax();
	void deleteNodeMin();
	void printLevelOrder(node*, int, int);
	void printLevelOrder(int);
	void printLevelOrder();
	
	void addNode(node*);
	int getMaxLevel(node*, int);
	int getHeight();
};


#endif