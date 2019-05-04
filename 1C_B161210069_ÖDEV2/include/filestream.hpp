#ifndef filestream_hpp
#define filestream_hpp
#include<iostream>
#include "eList.hpp"
using namespace std;
class filestream{
public:
	static eList<string> fileRead(string);
	static void fileWrite(string, eList<string>);
};


#endif