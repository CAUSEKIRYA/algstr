#include "List.h"
#include <iostream>

using namespace std;

int main()
{
    List *test = new List();
    List *testIn = new List();

    cout << "list test: " << test << endl;

    cout << endl;

    cout << "list test push back [1,2,3]" << endl;

    test->push_back(1);
    test->push_back(2);
    test->push_back(3);

    cout << "list test after push back: " << test << endl;

    cout << endl;

    cout << "list test push front [1,2,3]" << endl;

    test->push_front(1);
    test->push_front(2);
    test->push_front(3);

    cout << "list test after push front: " << test << endl;

    cout << endl;

    cout << "list test pop back" << endl;

    test->pop_back();

    cout << "list test after pop back: " << test << endl;

    cout << endl;

    cout << "list test pop front" << endl;

    test->pop_front();

    cout << "list test after pop front: " << test << endl;

    cout << endl;

    cout << "list test insert pos = 2, value = 3" << endl;

    test->insert(3, 2);

    cout << "list test after insert: " << test << endl;

    cout << endl;

    cout << "list test at pos = 2: " << test->at(2) << endl;

    cout << "list test set pos = 2, value = 4" << endl;

    test->set(2, 4);

    cout << "list test after set: " << test << endl;

    cout << endl;

    cout << "list test remove pos = 2 " << endl;

    test->remove(2);

    cout << "list test after remove: " << test << endl;

    cout << endl;

    cout << "list test size: " << test->get_size() << endl;

    cout << endl;

    cout << "list test insert list (variant 4 function 14) pos = 2" << endl;

    testIn->push_back(9);
    testIn->push_back(5);
    testIn->push_back(9);

    cout << "list testIn: " << testIn << endl;

    test->insert(testIn, 2);

    cout << "list test after insert: " << test << endl;

    cout << endl;

    cout << "list test is empty: " << test->isEmpty() << endl;

    test->clear();

    cout << "list test is empty after clear: " << test->isEmpty() << endl;

    delete (test);
    delete (testIn);

    return 0;
}
