#include "Sort.h"

using namespace std;

int binarySearch(int* arr, int left, int right, int num) {    
    if (left < 0)
        left = 0;
    int midd = 0;
    while (true)
    {
        midd = (left + right) / 2;

        if (num < arr[midd])
            right = midd - 1;
        else if (num > arr[midd])
            left = midd + 1;
        else
            return midd;

        if (left > right)
            return -1;
    }
    return -1;
}


void bubbleSort(int* arr, int left, int right) {
    if (left < 0)
        left = 0;
    for (int i = 0; i < right; i++) {
        for (int j = left; j < right - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


void quickSort(int* arr, int left, int right){
    if (left < 0)
        left = 0;
    int pivot;
    int l_hold = left;
    int r_hold = right;
    pivot = arr[left];
    while (left < right)
    {
        while ((arr[right] >= pivot) && (left < right))
            right--;
        if (left != right)
        {
            arr[left] = arr[right];
            left++;
        }
        while ((arr[left] <= pivot) && (left < right))
            left++;
        if (left != right)
        {
            arr[right] = arr[left];
            right--;
        }
    }
    arr[left] = pivot;
    pivot = left;
    left = l_hold;
    right = r_hold;
    if (left < pivot)
        quickSort(arr, left, pivot - 1);
    if (right > pivot)
        quickSort(arr, pivot + 1, right);
}


void bogoSort(int* arr, int left, int right) {
    if (left < 0)
        left = 0;
    bool sorted = 0;

    while (!sorted)
    {
        sorted = 1;
        for (int i = left; i < right + 1; i++) {
            int pos = left + (rand() % (right - left + 1));

            int temp = arr[pos];
            arr[pos] = arr[i];
            arr[i] = temp;
        }

        for (int i = left; i < right; i++) {
            if (arr[i] > arr[i + 1]) {
                sorted = 0;
                break;
            }
        }

    }
}


void countingSort(char* arr, int left, int right) {
    if (left < 0)
        left = 0;
    int k = (int)arr[left];
    for (int i = left; i < right + 1; i++)
        if (k < (int)arr[i])
            k = (int)arr[i];

    int* c = new int[k];
    memset(c, 0, sizeof(int) * (k + 1));

    for (int i = left; i < right + 1; ++i) {
        ++c[(int)arr[i]];
        //cout << (int)arr[i] << " " << (char)(int)arr[i] << " " << c[(int)arr[i]] << endl;
    }

    int b = left;
    for (int i = 0; i < k + 1; ++i) {
        for (int j = 0; j < c[i]; ++j) {
            arr[b++] = (char)i;
        }
    }
}