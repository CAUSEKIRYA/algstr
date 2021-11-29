#include "List.h"

using namespace std;

List::List(int value)
{

	head = new Node();
	size = 0;
	this->push_back(value);
}

List::List()
{
	head = nullptr;
	size = 0;
}

List::~List()
{
	if (this->head == nullptr)
	{
		delete (this->head);
		return;
	}
	while (this->head->next)
	{
		this->head = this->head->next;
		delete (this->head->prev);
		this->head->prev = nullptr;
	}
	delete (this->head);
}

void List::push_back(int value)
{
	size++;
	if (this->head == nullptr)
	{
		this->head = new Node();
		this->head->value = value;
		this->head->next = nullptr;
		this->head->prev = nullptr;
		return;
	}
	Node *add = new Node();
	add->value = value;

	Node *iter = this->head;
	while (iter->next)
	{
		iter = iter->next;
	}

	iter->next = add;
	add->prev = iter;
}

void List::push_front(int value)
{
	size++;
	if (this->head == nullptr)
	{
		this->head = new Node();
		this->head->value = value;
		this->head->next = nullptr;
		this->head->prev = nullptr;
		return;
	}
	Node *add = new Node();
	add->value = value;
	add->next = this->head;
	this->head->prev = add;

	this->head = add;
}

void List::pop_back()
{
	if (this->head == nullptr)
	{
		return;
	}

	this->size--;

	if (this->head->next == nullptr)
	{
		delete (this->head);
		this->head = nullptr;
		return;
	}

	Node *iter = this->head;

	while (iter->next->next != nullptr)
	{
		iter = iter->next;
	}

	delete (iter->next);
	iter->next = nullptr;
}

void List::pop_front()
{
	if (this->head == nullptr)
	{
		return;
	}

	this->size--;

	if (this->head->next == nullptr)
	{
		delete (this->head);
		this->head = nullptr;
		return;
	}

	Node *del = this->head;

	this->head = this->head->next;
	this->head->prev = nullptr;

	delete (del);
}

void List::insert(int value, size_t pos)
{
	if (size == 0)
		return;
	if (pos > this->size)
	{
		return;
	}
	if (pos == this->size)
	{
		this->push_back(value);
		return;
	}
	size++;

	Node *iter = this->head;

	while (pos > 0)
	{
		iter = iter->next;
		pos--;
	}

	Node *add = new Node();
	add->value = value;
	add->prev = iter->prev;
	add->next = iter;
	iter->prev = add;
	if (add->prev)
	{
		add->prev->next = add;
	}
	else
	{
		this->head = add;
	}
}

int List::at(size_t pos)
{
	if (pos < 0)
		return NULL;
	if (pos >= this->size)
	{
		return NULL;
	}

	Node *iter = this->head;

	while (pos != 0)
	{
		iter = iter->next;
		pos--;
	}

	return iter->value;
}

void List::remove(size_t pos)
{
	if (pos >= this->size)
	{
		return;
	}

	this->size--;

	Node *iter = this->head;

	while (pos != 0)
	{
		iter = iter->next;
		pos--;
	}

	if (iter->prev)
	{
		iter->prev->next = iter->next;
	}
	else if (iter->next)
	{
		this->head = iter->next;
		this->head->prev = nullptr;
		delete (iter);
		return;
	}
	else
	{
		delete (this->head);
		this->head = nullptr;
		return;
	}
	if (iter->next)
		iter->next->prev = iter->prev;

	delete (iter);
}

size_t List::get_size()
{
	return this->size;
}

void List::clear()
{
	while (this->head->next)
	{
		this->head = this->head->next;
		delete (this->head->prev);
		this->head->prev = nullptr;
	}
	delete (this->head);
	this->head = nullptr;
}

void List::set(size_t pos, int value)
{
	if (pos >= this->size)
	{
		return;
	}

	Node *iter = this->head;

	while (pos != 0)
	{
		iter = iter->next;
		pos--;
	}

	iter->value = value;
}

bool List::isEmpty()
{
	if (this->head == nullptr)
	{
		return true;
	}
	return false;
}

void List::insert(List *in, size_t pos)
{
	Node *iter = in->head;
	while (iter)
	{
		this->insert(iter->value, pos);
		pos++;
		iter = iter->next;
	}
}

ostream &operator<<(ostream &out, const List *list)
{

	Node *iter = list->head;
	if (iter == nullptr)
	{
		out << "Empty list";
		return out;
	}

	out << "[";
	while (iter)
	{
		if (iter->next == nullptr)
		{
			out << iter->value;
			break;
		}
		out << iter->value << ", ";
		iter = iter->next;
	}
	out << "]";

	return out;
}