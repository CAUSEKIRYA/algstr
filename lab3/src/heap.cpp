#include "heap.h"
#include <iostream>

using namespace std;

Heap::Heap() {
	h = new int[SIZE];
	HeapSize = 0;
}

Heap::~Heap() {
	delete(h);
}

void Heap::insert(int n) {
	int i, parent;
	i = HeapSize;
	h[i] = n;
	parent = (i - 1) / 2;
	while (parent >= 0 && i > 0) {
		if (h[i] > h[parent]) {
			int temp = h[i];
			h[i] = h[parent];
			h[parent] = temp;
		}
		i = parent;
		parent = (i - 1) / 2;
	}
	HeapSize++;
}

bool Heap::contains(int value) {
	for (int i = 0; i < HeapSize; i++) {
		if (h[i] == value)
			return true;
	}
	return false;
}

Iterator Heap::create_dft_iterator()
{
	return Iterator(h, HeapSize, 'd');
}

Iterator Heap::create_bft_iterator()
{
	return Iterator(h, HeapSize, 'b');
}

void Heap::outHeap(void) {
	int i = 0;
	int k = 1;
	while (i < HeapSize) {
		while ((i < k) && (i < HeapSize)) {
			cout << h[i] << " ";
			i++;
		}
		cout << endl;
		k = k * 2 + 1;
	}
}

void Heap::out(void) {
	for (int i = 0; i < HeapSize; i++) {
		cout << h[i] << " ";
	}
	cout << endl;
}

void Heap::remove(int value) {
	for (int i = 0; i < HeapSize; i++) {
		if (h[i] == value) {
			if (i == 0) {
				h[0] = h[HeapSize - 1];
				HeapSize--;
				heapify(0);
			}
			else {
				HeapSize--;
				for (int j = i; j < HeapSize; j++) {
					h[j] = h[j + 1];
					heapify(j);
				}
			}
		}
	}
}

void Heap::heapify(int i) {
	int left, right;
	int temp;
	left = 2 * i + 1;
	right = 2 * i + 2;
	if (left < HeapSize) {
		if (h[i] < h[left]) {
			temp = h[i];
			h[i] = h[left];
			h[left] = temp;
			heapify(left);
		}
	}
	if (right < HeapSize) {
		if (h[i] < h[right]) {
			temp = h[i];
			h[i] = h[right];
			h[right] = temp;
			heapify(right);
		}
	}
}