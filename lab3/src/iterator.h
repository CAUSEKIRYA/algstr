#ifndef ITERATOR_H
#define ITERATOR_H

class Stack {
private:
	struct linklst {
		int pos = -1;
		linklst* next = nullptr;
	};

	linklst* top;

public:
	Stack();
	~Stack();

	void push(int);
	void push_back(int);
	int Top();
	int pop();
	bool isEmpty();

};


class Iterator
{
private:
	Stack stack;
	int* heap;
	int size;
	int pos;
	char type;

public:
	Iterator(int*, int, char _type);
	Iterator();

	int operator*() const;
	int* operator->() const;
	Iterator& operator++();
};

#endif