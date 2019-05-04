/*
* @file  main.cpp
* @description main codes
* @course 1/C
* @assignment 3
* @date 14.12.18
* @author Eray KAYA eray.kaya1@ogr.sakarya.edu.tr
*/
#include<iostream>
#include "management.hpp"
#include "eList.hpp"
#include "menu.hpp"
using namespace std;

eList<string>* options;
void things(){
	menu::printOptions(options);
}

int main(){
	string input;
	cout<<"Enter the code of tree: ";
	getline(cin, input);
	management::createTrees(input);
	options = new eList<string>();
	options->addItem("Remove maximum value from trees");
	options->addItem("Remove minimum value from trees");
	options->addItem("Print all trees as level order");
	options->addItem("Exit");
	
	int consoleHeight = 30;
	int consoleWidth = 100;
	menu::setWindow(consoleWidth, consoleHeight, consoleWidth, consoleHeight * 5);
	things();
	while(menu::askQuestion()){things();}
	management::destroyTrees();
	delete options;
	cout<<endl<<endl<<string((consoleWidth - 4) / 2, '-') + "END-" + string((consoleWidth - 4) / 2, '-')<<endl;
	return 0;
}