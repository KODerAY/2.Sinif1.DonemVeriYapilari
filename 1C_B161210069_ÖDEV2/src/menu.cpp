/*
* @file  menu.cpp
* @description menu codes
* @course 1/C
* @assignment 2
* @date 21.11.18
* @author Eray KAYA eray.kaya1@ogr.sakarya.edu.tr
*/

#include<iostream>
#include<windows.h>
#include "menu.hpp"
#include "eList.hpp"
#include "management.hpp"
#include "processor.hpp"
using namespace std;

bool menu::askQuestion(){
	bool run = true;
	doublyLinked* RR = management::roundRing;
	string input, input1;
	
	cout<<"=>";
	getline(cin, input);
	if(input=="1"){
		RR->moveLeft();
	}else if (input=="2"){
		RR->moveRight();
	}else if (input=="3"){
		cout<<"n= ";
		getline(cin, input1);
		cout<<endl;
		int index = processor::stoi(input1);
		if((index >= 0)&(index < RR->Count())){
			node* item = RR->getItem(index);
			cout<<*(item->Data())<<"	|	";
			for(int i = item->DataList()->Length() - 1; i >= 0; i--){
				cout<<(*(item->DataList()))[i]<<"	";
			}
			cout<<endl;
		}else{
			cout<<"Invalid index"<<endl;
		}
	}else if (input=="4"){
		cout<<endl<<"DATA	|	DATALIST"<<endl;
		for(int i = 0; i < RR->Count(); i++){
			node* item = RR->getItem(i);
			cout<<*(item->Data())<<"	|	";
			for(int j = item->DataList()->Length() - 1; j >= 0; j--){
				cout<<(*(item->DataList()))[j]<<"	";
				if(item->DataList()->Length() - 1 - j % 10 == 9){cout<<endl<<"	|	";}
			}
			cout<<endl<<endl;
		}
	}else if (input=="5"){
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