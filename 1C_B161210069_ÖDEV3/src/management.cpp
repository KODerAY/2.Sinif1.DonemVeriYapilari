/*
* @file  management.cpp
* @description management codes
* @course 1/C
* @assignment 3
* @date 14.12.18
* @author Eray KAYA eray.kaya1@ogr.sakarya.edu.tr
*/

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include "management.hpp"
#include "processor.hpp"
#include "binaryTree.hpp"

using namespace std;

binaryTree* management::tree;

void management::createTrees(string text){
	binaryTree* temp = NULL;
	srand(time(NULL));
	for(unsigned int i = 0; i < text.length(); i++){		
		management::tree = new binaryTree();
		int height = processor::ctoi(text[text.length() - 1 - i]);
		height *= height > 0 ? 1 : -1;
		while(management::tree->getHeight() < height){
		node* top = new node();
		top->Data((rand() % (int)pow(2, height)) * ((rand() % 2 == 1) ? 1 : -1));
		management::tree->addNode(top);
		}
		if(temp != NULL){
			management::tree->Next() = temp;
		}
		temp = management::tree;	
	}
}

void management::destroyTrees(){
	delete tree;
}