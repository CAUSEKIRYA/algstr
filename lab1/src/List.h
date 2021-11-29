#pragma once
#include <iostream>

using namespace std;

class Node
{
public:
	int value;
	Node *next = nullptr;
	Node *prev = nullptr;
	~Node()
	{
		next = nullptr;
		prev = nullptr;
		delete (next);
		delete (prev);
	};
	Node()
	{
		value = NULL;
		next = nullptr;
		prev = nullptr;
	};
};

class List
{
private:
	Node *head = nullptr;
	size_t size = 0;

public:
	List();
	List(int);
	~List();
	void push_back(int);
	void push_front(int);
	void pop_back();
	void pop_front();
	void insert(int, size_t);
	int at(size_t);
	void remove(size_t);
	size_t get_size();
	void clear();
	void set(size_t, int);
	bool isEmpty();

	void insert(List *, size_t);

	friend ostream &operator<<(ostream &out, const List *list);
};
