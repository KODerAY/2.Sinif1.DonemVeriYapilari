/*
* @file  node.cpp
* @description node codes
* @course 1/C
* @assignment 3
* @date 14.12.18
* @author Eray KAYA eray.kaya1@ogr.sakarya.edu.tr
*/
#include<iostream>
#include "node.hpp"
using namespace std;
	//CONSTRUCTORS
	node::node(node* left, node* right){
		_right = right;
		_left = left;
		_root = NULL;//NC
	}
	node::node(){
		_right = NULL;
		_left = NULL;
		_root = NULL;//WTF
	}
	
	// DESTRUCTOR
	node::~node(){
		delete _right;
		delete _left;
	}
	
	//FUNCTIONS
	node* node::Right(){ return _right; }
	void node::Right(node* right){ _right = right; }
	
	node* node::Left(){ return _left; }
	void node::Left(node* left){ _left = left; }
	
	node* node::Root(){ return _root; }
	void node::Root(node* root){ _root = root; }
	
	int node::Data(){ return _data; }
	void node::Data(int data){ _data = data; }