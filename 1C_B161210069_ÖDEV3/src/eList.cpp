/*
* @file eList.cpp
* @description elastic list
* @course 1/C
* @assignment 3
* @date 14.12.18
* @author Eray KAYA eray.kaya1@ogr.sakarya.edu.tr
*/
#include<iostream>
#include "eList.hpp"
using namespace std;

//CONSTRUCTORS
template <typename T>
eList<T>::eList(T data, int length){
	eList<T>::Top() = new T[length];
	_capacity = length;
	_length = length;
	for(int i = 0;i < length;i++){
		eList<T>::Top()[i] = data;
	}
}

template <typename T>
eList<T>::eList(T data){
	eList<T>::Top() = new T[1];
	_capacity = 1;
	_length = 1;
	eList<T>::Top()[0] = data;
}

template <typename T>
eList<T>::eList(int length){
	eList<T>::Top() = new T[length];
	_capacity = length;
	_length = length;
}

template <typename T>
eList<T>::eList(){
	eList<T>::Top() = new T[1];
	_capacity = 1;
	_length = 0;
}
//DESTRUCTOR
template <typename T>
eList<T>::~eList(){
	delete[] eList<T>::Top();
}

//TOP
template <typename T>
T* eList<T>::Top()const{return _top;}
template <typename T>
T*& eList<T>::Top(){return _top;}
// LENGTH
template <typename T>
int eList<T>::Length(){return _length;}
// CAPACITY
template <typename T>
int eList<T>::Capacity(){return _capacity;}

//OPERATORS
template <typename T>
T eList<T>::operator[](int i)const{ return eList<T>::Top()[i]; }
template <typename T>
T& eList<T>::operator [](int i){ return eList<T>::Top()[i]; }
//FUNCTIONS
template <typename T>
void eList<T>::resize(int newSize){
	if(newSize > eList<T>::Capacity()){
		_capacity *= 2;
		T* tempArray = new T[_capacity];
		for(int i = 0; i < eList<T>::Length(); i++){
			tempArray[i] = eList<T>::Top()[i];
		}
		delete[] eList<T>::Top();
		eList<T>::Top() = tempArray;
	}
}
template <typename T>
void eList<T>::addItem(T item){
	eList<T>::resize(eList<T>::Length() + 1);
	eList<T>::Top()[eList<T>::Length()] = item;
	_length++;
}
template <typename T>
void eList<T>::deleteItem(int pos){
	if((pos >= 0)&(pos < eList<T>::Length())){
		for(int i = 0; i < eList<T>::Length() - pos - 1; i++){
			eList<T>::Top()[pos + i] = eList<T>::Top()[pos + i + 1];
		}
		_length--;
	}
}
template <typename T>
void eList<T>::dataCout(){
	for(int i = 0; i < eList<T>::Length(); i++){
		cout << i << eList<T>::Top()[i] << endl;
	}
}
// template class eList<float>;
template class eList<std :: string>;