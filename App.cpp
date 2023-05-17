#include "ShortTest.h"
#include "ExtendedTest.h"

#include "SortedSet.h"
#include "SortedSetIterator.h"

#include <iostream>
#include <cassert>

using namespace std;

bool rel(TComp e1, TComp e2) {
    if (e1 <= e2) {
        return true;
    } else {
        return false;
    }
}

void test_checkEqual(){
    SortedSet set1(rel);
    SortedSet set2(rel);
    SortedSet set3(rel);
    SortedSet set4(rel);
    SortedSet set5(rel);
    SortedSet set6(rel);
    SortedSet set7(rel);
    SortedSet set8(rel);

    set1.add(5);
    set1.add(7);
    set1.add(3);

    set2.add(3);
    set2.add(7);
    set2.add(5);

    assert(set1.checkEqual(set2));

    for (int i = 0; i <= 5; i++) {
        set3.add(i);
    }
    for (int i = 0; i <= 5; i++) {
        set4.add(i+2);
    }
    assert(set3.checkEqual(set4) == false);

    set5.add(3);
    set5.add(2);

    assert(set5.checkEqual(set6) == false);
    assert(set7.checkEqual(set8));
    cout<<"Test checkEqual"<<endl;
}

int main() {
    testAll();
    testAllExtended();

    test_checkEqual();

    cout << "Test end" << endl;
    system("pause");
}