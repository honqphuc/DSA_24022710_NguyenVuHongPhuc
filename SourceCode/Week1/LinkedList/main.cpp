#include <iostream>
#include "Linkedlist.h"

using namespace std;

int main()
{
    LinkedList list;

    cout << "Test LinkedList" << endl;
    list.addFirst(10);
    list.addFirst(20);
    list.addLast(5);
    list.print(); // 20 10 5

    list.insertI(2, 15);
    list.print(); // 20 15 10 5

    list.accessList(3); // 10

    list.deleteFirst();
    list.print(); // 15 10 5

    list.deleteLast();
    list.print(); // 15 10

    list.deleteI(2);
    list.print(); // 15

    cout << "print reverse: ";
    list.reversePrint(list.head); // 15
    cout << endl;

    return 0;
}
