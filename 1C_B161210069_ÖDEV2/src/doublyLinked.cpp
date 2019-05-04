/*
* @file  doublyLinked.cpp
* @description doubly linked list
* @course 1/C
* @assignment 2
* @date 22.11.18
* @author Eray KAYA eray.kaya1@ogr.sakarya.edu.tr
*/
#include<iostream>
#include "doublyLinked.hpp"
#include "eList.hpp"
using namespace std;

//CONSTRUCTORS
doublyLinked::doublyLinked(eList<string>* dataList, string* data){
	_top = new node(dataList, data);
	_top->Right(_top);
	_top->Left(_top);
	_count = 1;
}

// DESTRUCTOR
doublyLinked::~doublyLinked(){
	for(int i = 0; i < _count; i++){
		delete &_top[i];
	}
}

//TOP
node*& doublyLinked::Top(){ return _top; }
//COUNT
int doublyLinked::Count(){ return _count; }
void doublyLinked::Count(int count){ _count = count; }

//FUNCTIONS
node* doublyLinked::getItem(int index){
	node* item = doublyLinked::Top();
	int count = index;
	while(count > 0){
		item = item->Right();
		count--;
	}
	return item;
}
void doublyLinked::addItem(node* item, int pos){
	node* right = doublyLinked::getItem(pos);
	node* left = right->Left();
	if(pos == 0){doublyLinked::Top() = item;}
	left->Right(item);
	right->Left(item);
	item->Right(right);
	item->Left(left);
	_count++;
}
void doublyLinked::deleteItem(int pos){
	node* item = doublyLinked::getItem(pos);
	node* left = item->Left();
	node* right = item->Right();
	if(pos == 0){doublyLinked::Top() = right;}
	left->Right(right);
	right->Left(left);
	delete item;
	_count--;
}

//MOVE

void doublyLinked::moveLeft(){
	node* item = _top;
	string* temp = item->Data();
	for(int i = 0; i < _count - 1; i++){
		item->Data() = (item->Right())->Data();
		item = item->Right();
	}
	_top->Left()->Data() = temp;
	item = _top;
	for(int i = 0; i < _count; i++){
		string* data = new string(*(item->Data()));
		item->DataList()->addItem(*data);
		item = item->Right();
	}
}

void doublyLinked::moveRight(){
	node* item = _top->Left();
	string* temp = item->Data();
	for(int i = 0; i < _count - 1; i++){
		item->Data() = (item->Left())->Data();
		item = item->Left();
	}
	_top->Data() = temp;
	item = _top;
	for(int i = 0; i < _count; i++){
		string* data = new string(*(item->Data()));
		item->DataList()->addItem(*data);
		item = item->Right();
	}
}