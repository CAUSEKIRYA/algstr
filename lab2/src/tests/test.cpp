#include "pch.h"
#include "Sort.h"
#include <iostream>


bool sortedChar(char* arr, int size) {
	for (int i = 0; i < size - 1; i++) {
		if (int(arr[i]) > int(arr[i + 1]))
			return false;
	}
	return true;
}

bool sortedPosChar(char* arr, int left, int right, int size) {
	if (right > size) {
		right = size;
	}
	for (int i = left; i < right - 1; i++) {
		if (int(arr[i]) > int(arr[i + 1]))
			return false;
	}
	return true;
}

bool sorted(int* arr, int size) {
	for (int i = 0; i < size - 1; i++) {
		if (arr[i] > arr[i + 1])
			return false;
	}
	return true;
}

bool sortedPos(int* arr, int left, int right, int size) {
	if(right > size){
		right = size;
	}
	for (int i = left; i < right - 1; i++) {
		if (arr[i] > arr[i + 1])
			return false;
	}
	return true;
}
TEST(Sort, Bubble){
	int arr[100];
	for (int i = 0; i < 100; i++) {
		arr[i] = rand() % 101;
	}

	bubbleSort(arr, 0, 99);
	EXPECT_TRUE(sorted(arr, 100));

	for (int i = 0; i < 100; i++) {
		arr[i] = rand() % 101;
	}
	bubbleSort(arr, 25, 75);
	EXPECT_TRUE(sortedPos(arr, 25, 75, 100));
}

TEST(Sort, Quick) {
	int arr[100];
	for (int i = 0; i < 100; i++) {
		arr[i] = rand() % 101;
	}

	quickSort(arr, 0, 99);
	EXPECT_TRUE(sorted(arr, 100));

	for (int i = 0; i < 100; i++) {
		arr[i] = rand() % 101;
	}
	quickSort(arr, 25, 75);
	EXPECT_TRUE(sortedPos(arr, 25, 75, 100));
}

TEST(Sort, Bogo) {
	int arr[10];
	for (int i = 0; i < 10; i++) {
		arr[i] = rand() % 101;
	}

	bogoSort(arr, 0, 9);
	EXPECT_TRUE(sorted(arr, 10));

	for (int i = 0; i < 10; i++) {
		arr[i] = rand() % 101;
	}
	bogoSort(arr, 3, 7);
	EXPECT_TRUE(sortedPos(arr, 3, 7, 10));
}

TEST(Sort, Counting) {
	char arr[100];
	for (int i = 0; i < 100; i++) {
		arr[i] = char(rand() % 101);
	}

	countingSort(arr, 0, 99);
	EXPECT_TRUE(sortedChar(arr, 100));

	for (int i = 0; i < 100; i++) {
		arr[i] = char(rand() % 101);
	}
	countingSort(arr, 25, 75);
	EXPECT_TRUE(sortedPosChar(arr, 25, 75, 100));
}

TEST(Search, Binary) {
	int arr[100];
	for (int i = 0; i < 100; i++) {
		arr[i] = i+1;
	}

	EXPECT_EQ(21, binarySearch(arr, 0, 99, 22));
	EXPECT_EQ(57, binarySearch(arr, 0, 99, 58));
}