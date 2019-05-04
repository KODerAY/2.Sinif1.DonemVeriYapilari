#ifndef management_hpp
#define management_hpp
#include<iostream>
#include "binaryTree.hpp"

using namespace std;

class management{
public:
	static binaryTree* tree;
	static void createTrees(string);
	static void destroyTrees();
};


#endif