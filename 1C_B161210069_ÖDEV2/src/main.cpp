/*
* @file  main.cpp
* @description main codes
* @course 1/C
* @assignment 2
* @date 21.11.18
* @author Eray KAYA eray.kaya1@ogr.sakarya.edu.tr
*/
#include<iostream>
#include "management.hpp"
#include "filestream.hpp"
#include "eList.hpp"
#include "menu.hpp"
using namespace std;

eList<string>* options;
void things(){
	menu::printOptions(options);
}

int main(){
	management::createObjects(filestream::fileRead("Sayi.txt"));
	options = new eList<string>();
	options->addItem("Go to left");
	options->addItem("Go to right");
	options->addItem("Print n. node");
	options->addItem("Print all");
	options->addItem("Exit");
	
	int consoleHeight = 30;
	int consoleWidth = 100;
	menu::setWindow(consoleWidth, consoleHeight, consoleWidth, consoleHeight * 5);
	things();
	while(menu::askQuestion()){things();}
	//management::destroyObjects();
	delete options;
	cout<<endl<<endl<<string((consoleWidth - 4) / 2, '-') + "END-" + string((consoleWidth - 4) / 2, '-')<<endl;
	return 0;
}