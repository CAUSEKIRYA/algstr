#include <iostream>
#include <time.h> 
#include "Sort.h"

using namespace std;

double sumDiv(double arr[10]) {
    double sum = 0;
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
        sum += arr[i];
    }
    cout << endl;
    return sum / 10;
}


void generateArr(int* arr,int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 101;
    }
}
//bs qs
int main()
{
    int arr1[10];
    int arr2[100];
    int arr3[1000];
    int arr4[10000];
    int arr5[100000];

    double qtime1[10];
    double qtime2[10];
    double qtime3[10];
    double qtime4[10];
    double qtime5[10];
    double btime1[10];
    double btime2[10];
    double btime3[10];
    double btime4[10];
    double btime5[10];

    clock_t start;
    clock_t end;
    for (int i = 0; i < 10; i++) {
        generateArr(arr1, 10);
        generateArr(arr2, 100);
        generateArr(arr3, 1000);
        generateArr(arr4, 10000);
        generateArr(arr5, 100000);

        start = clock();
        quickSort(arr1,0,9);
        end = clock();
        qtime1[i] = (double)(end - start) / CLOCKS_PER_SEC;

        start = clock();
        quickSort(arr2, 0, 99);
        end = clock();
        qtime2[i] = (double)(end - start) / CLOCKS_PER_SEC;

        start = clock();
        quickSort(arr3, 0, 999);
        end = clock();
        qtime3[i] = (double)(end - start) / CLOCKS_PER_SEC;

        start = clock();
        quickSort(arr4, 0, 9999);
        end = clock();
        qtime4[i] = (double)(end - start) / CLOCKS_PER_SEC;

        start = clock();
        quickSort(arr5, 0, 99999);
        end = clock();
        qtime5[i] = (double)(end - start) / CLOCKS_PER_SEC;


        generateArr(arr1, 10);
        generateArr(arr2, 100);
        generateArr(arr3, 1000);
        generateArr(arr4, 10000);
        generateArr(arr5, 100000);

        start = clock();
        bubbleSort(arr1, 0, 9);
        end = clock();
        btime1[i] = (double)(end - start) / CLOCKS_PER_SEC;

        start = clock();
        bubbleSort(arr2, 0, 99);
        end = clock();
        btime2[i] = (double)(end - start) / CLOCKS_PER_SEC;

        start = clock();
        bubbleSort(arr3, 0, 999);
        end = clock();
        btime3[i] = (double)(end - start) / CLOCKS_PER_SEC;

        start = clock();
        bubbleSort(arr4, 0, 9999);
        end = clock();
        btime4[i] = (double)(end - start) / CLOCKS_PER_SEC;

        start = clock();
        bubbleSort(arr5, 0, 99999);
        end = clock();
        btime5[i] = (double)(end - start) / CLOCKS_PER_SEC;
    }

    cout << "quickSort 10: " << sumDiv(qtime1) << " seconds" << endl;
    cout << "quickSort 100: " << sumDiv(qtime2) << " seconds" << endl;
    cout << "quickSort 1000: " << sumDiv(qtime3) << " seconds" << endl;
    cout << "quickSort 10000: " << sumDiv(qtime4) << " seconds" << endl;
    cout << "quickSort 100000: " << sumDiv(qtime5) << " seconds" << endl;

    cout << "bubleSort 10: " << sumDiv(btime1) << " seconds" << endl;
    cout << "bubleSort 100: " << sumDiv(btime2) << " seconds" << endl;
    cout << "bubleSort 1000: " << sumDiv(btime3) << " seconds" << endl;
    cout << "bubleSort 10000: " << sumDiv(btime4) << " seconds" << endl;
    cout << "bubleSort 100000: " << sumDiv(btime5) << " seconds" << endl;
    
}

