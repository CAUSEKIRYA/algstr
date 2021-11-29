#pragma once

#include "iterator.h";

class Heap {
	static const int SIZE = 100;
	int* h;         
	int HeapSize; 
public:
	Heap(); 
	~Heap();
	void remove(int); 
	void insert(int);  
	bool contains(int); 
	Iterator create_dft_iterator(); 
	Iterator create_bft_iterator(); 


	void outHeap();
	void out(); 
	void heapify(int);  
};

