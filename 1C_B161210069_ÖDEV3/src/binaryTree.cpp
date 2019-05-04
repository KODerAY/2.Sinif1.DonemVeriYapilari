/*
* @file  binaryTree.cpp
* @description binary tree
* @course 1/C
* @assignment 3
* @date 14.12.18
* @author Eray KAYA eray.kaya1@ogr.sakarya.edu.tr
*/
#include<iostream>
#include "binaryTree.hpp"
using namespace std;

//CONSTRUCTORS
binaryTree::binaryTree(){
	_top = NULL;
	_next = NULL;
}

// DESTRUCTOR
binaryTree::~binaryTree(){
	delete _top;
	delete _next;
}

//TOP
node*& binaryTree::Top(){ return _top; }
//NEXT
binaryTree*& binaryTree::Next(){ return _next;}

//FUNCTIONS
node* binaryTree::getNodeMax(){
	node* item = binaryTree::Top();
	if(item != NULL){
		while(item->Right() != NULL){
			item = item->Right();
		}
	}
	return item;
}
node* binaryTree::getNodeMin(){
	node* item = binaryTree::Top();
	if(item != NULL){
		while(item->Left() != NULL){
			item = item->Left();
		}
	}
	return item;
}
void binaryTree::deleteNodeMax(){
	node* nodeMax = binaryTree::getNodeMax();
	if(nodeMax != NULL){
		if(nodeMax->Root() != NULL){
			nodeMax->Root()->Right(NULL);
		}
		if(binaryTree::Top() == nodeMax){
			binaryTree::Top() = NULL;
		}
		delete nodeMax;
	}
}
void binaryTree::deleteNodeMin(){
	node* nodeMin = binaryTree::getNodeMin();
	if(nodeMin != NULL){
		if(nodeMin->Root() != NULL){
			nodeMin->Root()->Left(NULL);
		}
		if(binaryTree::Top() == nodeMin){
			binaryTree::Top() = NULL;
		}
		delete nodeMin;
	}
}
void binaryTree::printLevelOrder(node* branch, int leveled, int level){
	if(branch != NULL){
		if(leveled == level){
			cout << branch->Data() << " ";
		}else{
			binaryTree::printLevelOrder(branch->Left() , leveled, level + 1);
			binaryTree::printLevelOrder(branch->Right(), leveled, level + 1);
		}
	}
}
void binaryTree::printLevelOrder(int level){
	if(level > 0){
		binaryTree::printLevelOrder(binaryTree::Top()->Left() , level, 1);
		binaryTree::printLevelOrder(binaryTree::Top()->Right(), level, 1);
	}else if(level == 0){
		if(binaryTree::Top() != NULL){
			cout<<binaryTree::Top()->Data();
		}
	}
}
void binaryTree::printLevelOrder(){
	if(binaryTree::Top() != NULL){
		cout<<"0. level-> ";//marked
		cout<<binaryTree::Top()->Data() << " ";
		cout<<endl;//marked
		for(int i = 1; i <= binaryTree::getHeight(); i++){
			cout << i << ". level-> ";//marked
			binaryTree::printLevelOrder(i);
			cout<<endl;//marked
		}
	}
}
void binaryTree::addNode(node* item){
	if(_top == NULL){
		item->Root(NULL);
		_top = item;
	}else{
		node* temp = _top;
		while(true){
			if(item->Data() == temp->Data()){
				item->Data(item->Data() + 1);
				addNode(item);
				break;
			}else if(item->Data() > temp->Data()){
				if(temp->Right() == NULL){
					item->Root(temp);
					temp->Right(item);
					break;
				}else{
					temp = temp->Right();
				}
			}else if(item->Data() < temp->Data()){
				if(temp->Left() ==  NULL){
					item->Root(temp);
					temp->Left(item);
					break;
				}else{
					temp = temp->Left();
				}
			}
		}
	}
}
int binaryTree::getMaxLevel(node* root, int i){
	int _right = root->Right() != NULL ? getMaxLevel(root->Right(), i + 1) : i;
	int _left  = root->Left()  != NULL ? getMaxLevel(root->Left() , i + 1) : i;
	return _right > _left ? _right : _left;
}

int binaryTree::getHeight(){
	if(_top != NULL){
		return getMaxLevel(_top, 0);
	}
	return 0;
}