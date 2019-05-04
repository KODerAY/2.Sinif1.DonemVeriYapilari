/*
* @file  menu.cpp
* @description menu codes
* @course 1/C
* @assignment 3
* @date 14.12.18
* @author Eray KAYA eray.kaya1@ogr.sakarya.edu.tr
*/

#include<iostream>
#include<windows.h>
#include "menu.hpp"
#include "binaryTree.hpp"
#include "eList.hpp"
#include "management.hpp"
using namespace std;

bool menu::askQuestion(){
	bool run = true;
	binaryTree* TI = management::tree;
	string input;
	
	cout<<"=>";
	getline(cin, input);
	if(input=="1"){
		binaryTree* _current = TI;
		while(_current != NULL){
			_current->deleteNodeMax();
			_current = _current->Next();
		}
	}else if (input=="2"){
		binaryTree* _current = TI;
		while(_current != NULL){
			_current->deleteNodeMin();
			_current = _current->Next();
		}
	}else if (input=="3"){
		binaryTree* _current = TI;
		int count = 1;
		while(_current != NULL){
			cout<<count<<". tree"<<endl;//marked
			_current->printLevelOrder();
			cout<<endl;
			_current = _current->Next();
			count++;
		}
	}else if (input=="4"){
		run = false;
	}else{
		cout<<"Invalid"<<endl;
	}
	return run;
}

void menu::printOptions(eList<string>* options){
	cout<<endl;
	for(int i = 0; i < options->Length(); i++){
		cout << i + 1 << "- " << (*options)[i] << endl;
	}
}


void menu::setWindow(int width, int height, int bwidth, int bheight) 
{ 
    COORD coord; 
    coord.X = bwidth; 
    coord.Y = bheight; 

    SMALL_RECT Rect; 
    Rect.Top = 0; 
    Rect.Left = 0; 
    Rect.Bottom = height - 1; 
    Rect.Right = width - 1; 
	
	SMALL_RECT const minimal_window = { 0, 0, 1, 1 };
	
    HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);      // Get Handle 
	SetConsoleWindowInfo(Handle, TRUE, &minimal_window);  // Set Minimal Window 
	SetConsoleScreenBufferSize(Handle, coord);            // Set Buffer Size 
	SetConsoleWindowInfo(Handle, TRUE, &Rect);            // Set Window 

}