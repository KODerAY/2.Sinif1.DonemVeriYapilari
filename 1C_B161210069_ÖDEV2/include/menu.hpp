#ifndef menu_hpp
#define menu_hpp
#include<iostream>
#include "eList.hpp"
using namespace std;

extern const int numberOfGroups;
class menu{
public:
	static bool askQuestion();
	static void printOptions(eList<string>*);
	static void setWindow(int, int, int, int);
};


#endif