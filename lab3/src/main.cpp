#include <iostream>
#include "heap.h"

using namespace std;

int main() {
    Heap heap;
    heap.insert(1);
    heap.insert(2);
    heap.insert(3);
    heap.insert(4);
    heap.insert(5);
    heap.insert(6);
    heap.insert(7);
    heap.insert(8);
    heap.insert(9);
    heap.insert(10);
    heap.insert(11);
    heap.insert(12);
    heap.insert(13);
    heap.insert(14);
    heap.insert(15);
    heap.insert(16);

    heap.outHeap();

    cout << endl;

    heap.out();

    auto iter = heap.create_dft_iterator();
    cout << endl;

    for (int i = 0; i < 16; i++) {
        cout << *iter << endl;
        ++iter;
    }

    return 0;
}

