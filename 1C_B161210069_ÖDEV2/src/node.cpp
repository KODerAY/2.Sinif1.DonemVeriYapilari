/*
* @file  node.cpp
* @description node codes
* @course 1/C
* @assignment 2
* @date 22.11.18
* @author Eray KAYA eray.kaya1@ogr.sakarya.edu.tr
*/
#include<iostream>
#include "node.hpp"
#include "eList.hpp"
using namespace std;
	//CONSTRUCTORS
	node::node(eList<string>* dataList, string* data, node* left, node* right){
		_dataList = dataList;
		_data = data;
		_left = left;
		_right = right;
	}
	node::node(eList<string>* dataList, string* data){
		_dataList = dataList;
		_data = data;
	}
	
	// DESTRUCTOR
	node::~node(){
		delete _dataList;
		delete _data;
	}
	
	//FUNCTIONS
	eList<string>*& node::DataList(){ return _dataList; }
	string*& node::Data(){ return _data; }
	
	node* node::Right(){ return _right; }
	void node::Right(node* right){ _right = right; }
	
	node* node::Left(){ return _left; }
	void node::Left(node* left){ _left = left; }