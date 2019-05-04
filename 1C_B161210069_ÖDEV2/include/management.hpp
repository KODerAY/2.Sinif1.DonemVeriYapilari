#ifndef management_hpp
#define management_hpp
#include<iostream>
#include "doublyLinked.hpp"
#include "eList.hpp"

using namespace std;

class management{
public:
	static doublyLinked* roundRing;
	static void createObjects(eList<string>);
	static void destroyObjects();
};


#endif