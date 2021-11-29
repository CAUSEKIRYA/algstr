#include "pch.h"
#include "heap.h"
#include "iterator.h"
#include <iostream>

using namespace std;

void createHeap(Heap *heap, int n)
{
	for (int i = 0; i < n; i++)
	{
		heap->insert(i + 1);
	}
}

TEST(Stack, Push)
{
	Stack stack;

	stack.push(1);
	ASSERT_EQ(1, stack.Top());
	stack.push(2);
	ASSERT_EQ(2, stack.Top());
	stack.push_back(3);
	ASSERT_EQ(2, stack.Top());
}

TEST(Stack, Top)
{
	Stack stack;

	stack.push(1);
	ASSERT_EQ(1, stack.Top());
	stack.push(2);
	ASSERT_EQ(2, stack.Top());
	stack.push_back(3);
	ASSERT_EQ(2, stack.Top());

	stack.pop();
	ASSERT_EQ(1, stack.Top());
	stack.pop();
	ASSERT_EQ(3, stack.Top());
	stack.pop();
	ASSERT_EQ(-1, stack.Top());
}

TEST(Stack, Pop)
{
	Stack stack;

	stack.push(1);
	stack.push(2);
	stack.push_back(3);

	ASSERT_EQ(2, stack.pop());
	ASSERT_EQ(1, stack.pop());
	ASSERT_EQ(3, stack.pop());
	ASSERT_EQ(-1, stack.pop());
}

TEST(Stack, IsEmpty)
{
	Stack stack;
	ASSERT_TRUE(stack.isEmpty());
	stack.push(1);
	ASSERT_FALSE(stack.isEmpty());
	stack.pop();
	ASSERT_TRUE(stack.isEmpty());
}

TEST(Iterator, OperatorMulti)
{
	Heap *heap = new Heap();
	createHeap(heap, 16);
	Iterator iter = heap->create_bft_iterator();

	for (int i = 0; i < 16; i++)
	{
		ASSERT_TRUE(heap->contains(*iter));
		++iter;
	}
}

TEST(Iterator, OperatorPlusPlus)
{
	Heap *heap = new Heap();
	createHeap(heap, 16);
	Iterator iter = heap->create_bft_iterator();

	for (int i = 0; i < 16; i++)
	{
		ASSERT_TRUE(heap->contains(*iter));
		++iter;
	}
}

TEST(Heap, Insert)
{
	Heap *heap = new Heap();
	heap->insert(1);
	ASSERT_TRUE(heap->contains(1));
	heap->insert(2);
	ASSERT_TRUE(heap->contains(2));
	heap->insert(3);
	ASSERT_TRUE(heap->contains(3));
}

TEST(Heap, Contains)
{
	Heap *heap = new Heap();
	heap->insert(1);
	ASSERT_TRUE(heap->contains(1));
	heap->insert(2);
	ASSERT_TRUE(heap->contains(2));
	heap->insert(3);
	ASSERT_TRUE(heap->contains(3));
	ASSERT_FALSE(heap->contains(0));
	heap->insert(0);
	ASSERT_TRUE(heap->contains(0));
}

TEST(Heap, Remove)
{
	Heap *heap = new Heap();
	createHeap(heap, 16);
	heap->remove(1);
	ASSERT_FALSE(heap->contains(1));
	heap->remove(16);
	ASSERT_FALSE(heap->contains(16));
	heap->remove(6);
	ASSERT_FALSE(heap->contains(6));
}

TEST(Heap, DFTIter)
{
	Heap *heap = new Heap();
	createHeap(heap, 16);
	auto iter = heap->create_dft_iterator();
	for (int i = 0; i < 16; i++)
	{
		ASSERT_TRUE(heap->contains(*iter));
		++iter;
	}
}

TEST(Heap, BFTIter)
{
	Heap *heap = new Heap();
	createHeap(heap, 16);
	auto iter = heap->create_bft_iterator();
	for (int i = 0; i < 16; i++)
	{
		ASSERT_TRUE(heap->contains(*iter));
		++iter;
	}
}

TEST(Heap, OutHeap)
{
	Heap *heap = new Heap();
	createHeap(heap, 16);
	cout << endl;
	heap->outHeap();
	cout << endl;
	EXPECT_TRUE(true);
}

TEST(Heap, GetSize)
{
	Heap *heap = new Heap();
	createHeap(heap, 16);
	ASSERT_EQ(16, heap->getSize());
	heap->insert(17);
	ASSERT_EQ(17, heap->getSize());
}

TEST(Heap, Copy)
{
	Heap *heap = new Heap();
	createHeap(heap, 16);
	int *h = heap->copy();

	for (int i = 0; i < 16; i++)
	{
		ASSERT_TRUE(heap->contains(h[i]));
	}
}

TEST(Heap, Out)
{
	Heap *heap = new Heap();
	createHeap(heap, 16);
	cout << endl;
	heap->outHeap();
	cout << endl;
	EXPECT_TRUE(true);
}

TEST(Heap, Heapify)
{
	Heap *heap = new Heap();
	createHeap(heap, 16);

	int *h1 = heap->copy();
	heap->heapify(0);
	int *h2 = heap->copy();

	for (int i = 0; i < 16; i++)
	{
		ASSERT_TRUE(h1[i] == h2[i]);
	}
}