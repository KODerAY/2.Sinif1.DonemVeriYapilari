/*
* @file  processor.cpp
* @description string processor codes
* @course 1/C
* @assignment 2
* @date 22.11.18
* @author Eray KAYA eray.kaya1@ogr.sakarya.edu.tr
*/

#include<iostream>
#include "processor.hpp"
#include "eList.hpp"
#include <cmath>

using namespace std;
const char* ws= " \t\n\r\f\v";

// trim from end of string (right)
string processor::rtrim(string ss, const char* tt){
	string rtrim = ss;
    rtrim.erase(ss.find_last_not_of(tt) + 1);
    return rtrim;
}

// trim from beginning of string (left)
string processor::ltrim(string ss, const char* tt){
	string ltrim = ss;
    ltrim.erase(0, ss.find_first_not_of(tt));
    return ltrim;
}

// trim from both ends of string (left & right)
string processor::trim(string ss, const char* tt){
    return processor::ltrim(processor::rtrim(ss, tt), tt);
}

eList<string> processor::split(string ss,char cc){
	eList<string> parsed;
	unsigned int count = 0;
	for(unsigned int i = 0; i < ss.length(); i++){
		if(ss[i] != cc){
			count += 1;
		}else{
			if(count > 0){
				parsed.addItem(ss.substr(i - count, count));
				count = 0;
			}
		}
	}
	if(count > 0){
		parsed.addItem(ss.substr(ss.length() - count, count));
		count = 0;
	}
	return parsed;
}

//CONVERSION

int processor::stoi(string s){
	int total = 0;
	for (unsigned int i = 0; i < s.length(); i++){
		total += pow(10, i) * (s[s.length() - i - 1] - '0');
	}
	return total;
}