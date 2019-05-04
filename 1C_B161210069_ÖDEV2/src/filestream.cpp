 /*
* @file  fileStream.cpp
* @description file stream codes
* @course 1/C
* @assignment 2
* @date 20.11.18
* @author Eray KAYA eray.kaya1@ogr.sakarya.edu.tr
*/

#include<iostream>
#include<fstream>
#include "fileStream.hpp"
#include "eList.hpp"
using namespace std;

eList<string> filestream::fileRead(string fileName){
	eList<string> lines;
	string line;
	ifstream file(fileName);
	if (file.is_open()){
	while(getline(file, line)){
		if(line!=""){
			lines.addItem(line);
		}
	}
	file.close();
	return lines;
	}else{
		cout<<"File not found.";
		return lines;
	}
}
void filestream::fileWrite(string fileName, eList<string> text){
ofstream file(fileName);
if (file.is_open()){
for(int i = 0; i < text.Length(); i++){
	file << text[i];
}
file.close();
}else{
	cout<<"File not found.";
}
}