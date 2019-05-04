#ifndef eList_hpp
#define eList_hpp
#include<iostream>
using namespace std;
template <typename T>
class eList{
	
private:
	T* _top;
	int _capacity;
	int _length;
	
public:
	// CONSTRUCTORS
	eList(T, int);
	eList(T);
	eList(int);
	eList();
	
	// DESTRUCTOR
	~eList();
	
	// TOP
	T* Top()const;
	T*& Top();
	// LENGTH
	int Length();
	// CAPACİTY
	int Capacity();
	
	//OPERATORS
	T operator [](int)const;
	T& operator [](int);
	//FUNCTİONS
	void resize(int);
	void addItem(T);
	void deleteItem(int);
	
	void dataCout();
};


#endif