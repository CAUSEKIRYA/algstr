#include "pch.h"
#include "List.h"
#include <iostream>
#include <windows.h>

using namespace std;

void listOut(List *test, HANDLE hStdOut)
{
	SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "[      List] ";
	SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);

	cout << test << endl;
}

List *createList(int value)
{
	List *test = new List();

	for (int i = 0; i < value; i++)
	{
		test->push_back(i + 1);
	}
	return test;
}

TEST(InputTest, Push)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	List *test = new List();
	test = createList(3);

	ASSERT_EQ(1, test->at(0));
	ASSERT_EQ(2, test->at(1));
	ASSERT_EQ(3, test->at(2));

	listOut(test, hStdOut);
}

TEST(OutputTest, At)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);

	List *test = new List();
	test = createList(6);
	;

	for (int i = 0; i < 10; i++)
	{
		if (i < test->get_size())
			ASSERT_EQ(i + 1, test->at(i));
		else
			ASSERT_EQ(NULL, test->at(i));
	}

	listOut(test, hStdOut);
}

TEST(DeleteTest, Remove)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);

	List *test = new List();
	test = createList(6);

	listOut(test, hStdOut);

	test->remove(5);
	ASSERT_EQ(NULL, test->at(5));
	test->remove(2);
	ASSERT_EQ(4, test->at(2));
	test->remove(0);
	ASSERT_EQ(2, test->at(0));

	listOut(test, hStdOut);
}

TEST(DeleteTest, Pop)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	List *test = new List();
	test->pop_back();
	test->pop_front();
	ASSERT_EQ(NULL, test->at(0));

	test = createList(6);

	listOut(test, hStdOut);

	test->pop_back();
	ASSERT_EQ(NULL, test->at(5));
	ASSERT_EQ(5, test->at(4));

	test->pop_front();
	ASSERT_EQ(2, test->at(0));

	listOut(test, hStdOut);
}

TEST(InputTest, Insert)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	List *test = new List();
	test = createList(6);

	test->insert(7, 0);
	ASSERT_EQ(7, test->at(0));
	ASSERT_EQ(1, test->at(1));
	test->pop_front();
	test->insert(7, 3);
	ASSERT_EQ(7, test->at(3));
	ASSERT_EQ(4, test->at(4));
	ASSERT_EQ(3, test->at(2));
	test->remove(3);

	test->insert(7, 6);
	ASSERT_EQ(7, test->at(6));
	ASSERT_EQ(6, test->at(5));
}

TEST(InputTest, InsertList)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	List *test = new List();
	test = createList(6);
	List *testIn = new List();
	testIn = createList(6);
	listOut(test, hStdOut);

	int k = 3;

	test->insert(testIn, k);
	for (int i = 0; i < 12; i++)
	{
		if (i >= k && i < (k + 6))
		{
			ASSERT_EQ(i + 1 - k, test->at(i));
		}
		else if (i >= (k + 6))
		{
			ASSERT_EQ(i - 5, test->at(i));
		}
		else
		{
			ASSERT_EQ(i + 1, test->at(i));
		}
	}
	listOut(test, hStdOut);
	delete (test);
	delete (testIn);

	test = createList(6);
	testIn = createList(6);

	k = 0;

	test->insert(testIn, k);
	for (int i = 0; i < 12; i++)
	{
		if (i >= k && i < (k + 6))
		{
			ASSERT_EQ(i + 1 - k, test->at(i));
		}
		else if (i >= (k + 6))
		{
			ASSERT_EQ(i - 5, test->at(i));
		}
		else
		{
			ASSERT_EQ(i + 1, test->at(i));
		}
	}
	listOut(test, hStdOut);
	delete (test);
	delete (testIn);

	test = createList(6);
	testIn = createList(6);

	k = 5;

	test->insert(testIn, k);
	for (int i = 0; i < 12; i++)
	{
		if (i >= k && i < (k + 6))
		{
			ASSERT_EQ(i + 1 - k, test->at(i));
		}
		else if (i >= (k + 6))
		{
			ASSERT_EQ(i - 5, test->at(i));
		}
		else
		{
			ASSERT_EQ(i + 1, test->at(i));
		}
	}
	listOut(test, hStdOut);
	delete (test);
	delete (testIn);

	test = createList(6);
	testIn = createList(6);

	k = 6;

	test->insert(testIn, k);
	for (int i = 0; i < 12; i++)
	{
		if (i >= k && i < (k + 6))
		{
			ASSERT_EQ(i + 1 - k, test->at(i));
		}
		else if (i >= (k + 6))
		{
			ASSERT_EQ(i - 5, test->at(i));
		}
		else
		{
			ASSERT_EQ(i + 1, test->at(i));
		}
	}
	listOut(test, hStdOut);
}

TEST(InputTest, Set)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	List *test = new List();
	test = createList(6);

	listOut(test, hStdOut);

	for (int i = 0; i < 7; i++)
	{
		test->set(i, i + 2);
	}

	for (int i = 0; i < 6; i++)
	{
		ASSERT_EQ(i + 2, test->at(i));
	}
	ASSERT_EQ(NULL, test->at(6));

	listOut(test, hStdOut);
}

TEST(OutputTest, GetSize)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	List *test = new List();
	test = createList(6);

	listOut(test, hStdOut);

	ASSERT_EQ(6, test->get_size());

	test->push_back(1);

	ASSERT_EQ(7, test->get_size());

	listOut(test, hStdOut);
}

TEST(OutputTest, IsEmpty)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	List *test = new List();

	ASSERT_EQ(true, test->isEmpty());
	test = createList(6);
	ASSERT_EQ(false, test->isEmpty());
	test->clear();
	ASSERT_EQ(true, test->isEmpty());
}

TEST(DeleteTest, Clear)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	List *test = new List();
	test = createList(6);

	ASSERT_EQ(false, test->isEmpty());
	test->clear();
	ASSERT_EQ(true, test->isEmpty());
	test->push_back(1);
	ASSERT_EQ(false, test->isEmpty());
}