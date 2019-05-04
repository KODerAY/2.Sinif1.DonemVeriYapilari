/*
* @file  management.cpp
* @description management codes
* @course 1/C
* @assignment 2
* @date 21.11.18
* @author Eray KAYA eray.kaya1@ogr.sakarya.edu.tr
*/

#include<iostream>
#include "management.hpp"
#include "processor.hpp"
#include "doublyLinked.hpp"
#include "eList.hpp"

using namespace std;

doublyLinked* management::roundRing;

void management::createObjects(eList<string> text){
	for(int i = 0; i < text.Length(); i++){
		eList<string> splitted = processor::split(processor::trim(text[i]), ' ');
		for(int j = 0; j < splitted.Length(); j++){
			eList<string>* dataList = new eList<string>(splitted[j]);
			string* data = new string(splitted[j]);
			node* stack = new node(dataList, data);
			if((i == 0)&(j == 0)){
				management::roundRing = new doublyLinked(dataList, data);
			}else{
				management::roundRing->addItem(stack, management::roundRing->Count());
			}
		}
	}
}

void management::destroyObjects(){
	delete roundRing;
}