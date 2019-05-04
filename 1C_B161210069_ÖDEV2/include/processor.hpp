#ifndef processor_hpp
#define processor_hpp
#include<iostream>
#include "eList.hpp"

using namespace std;

extern const char* ws;
class processor{
public:
	static string rtrim(string,const char* t = ::ws);
	static string ltrim(string,const char* t = ::ws);
	static string trim(string,const char* t = ::ws);
	static eList<string> split(string, char);
	//CONVERSION
	static int stoi(string s);
	
};

#endif