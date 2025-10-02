#include <iostream>
#include "Linkedlist.h"

using namespace std;

int main()
{
    LinkedList llist;

    cout << "Test LinkedList" << endl;
    llist.addFirst(10);
    llist.addFirst(20);
    llist.addLast(5);
    llist.print(); // 20 10 5

    llist.insertI(2, 15);
    llist.print(); // 20 15 10 5

    llist.accessList(3); // 10

    llist.deleteFirst();
    llist.print(); // 15 10 5

    llist.deleteLast();
    llist.print(); // 15 10

    llist.deleteI(2);
    llist.print(); // 15

    cout << "print reverse: ";
    llist.reversePrint(llist.head); // 15
    cout << endl;

    return 0;
}
