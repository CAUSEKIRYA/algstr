#include "iterator.h"
#include <iostream>


Iterator::Iterator(){
	heap = nullptr;
	type = 'd';
	pos = 0;
	size = 0;
}


Iterator::Iterator(int* _heap, int _size, char _type){
	heap = new int[_size];
	heap = _heap;
	size = _size;
	type = _type;
	pos = 0;
}


int Iterator::operator*() const {
	if (pos > -1)
		return heap[pos];
	return -1;
}

int* Iterator::operator->() const{
	if (pos > -1)
		return &heap[pos];
	return nullptr;
}


Iterator& Iterator::operator++(){
	if (pos != -1){
		if (type == 'b') {
			if (stack.isEmpty()) {
				if (pos * 2 + 1 < size)
					stack.push_back(pos * 2 + 1);
				if (pos * 2 + 2 < size)
					stack.push_back(pos * 2 + 2);
			}
			pos = stack.pop();
			if (pos != -1) {
				if (pos * 2 + 1)
					stack.push_back(pos * 2 + 1);
				if (pos * 2 + 2)
					stack.push_back(pos * 2 + 2);
			}
		}
		else if (type == 'd') {
			if (pos * 2 + 2 < size){
				stack.push(pos * 2 + 2);
			}
			if (pos * 2 + 1 < size){
				pos = pos * 2 + 1;
			}
			else{
				pos = stack.Top();
				stack.pop();
			}
		}
	}
	return *this;
}


Stack::Stack() {
	top = nullptr;
}


Stack::~Stack() {
	while (top) {
		linklst* r = top;
		top = top->next;
		delete r;
	}
	delete top;
}


void Stack::push(int pos) {
	linklst* r = new linklst();
	r->pos = pos;
	r->next = top;
	top = r;
}


void Stack::push_back(int pos) {
	linklst* r = new linklst();
	r->pos = pos;
	if (top == nullptr) {
		r->next = top;
		top = r;
		return;
	}
	linklst* n = top;
	while (n->next){
		n = n->next;
	}
	n->next = r;
}


int Stack::Top(){
	if (top)
		return top->pos;
	return -1;
}

int Stack::pop() {
	if (!isEmpty()) {
		linklst* r = top;
		top = top->next;
		int x = r->pos;
		delete r;
		return x;

	}
	return -1;
}


bool Stack::isEmpty() {
	if (top == nullptr)
		return true;
	return false;
}
