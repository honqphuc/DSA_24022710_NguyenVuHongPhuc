#include <iostream>
#include "List.h"
using namespace std;

int main()
{
    List llist;

    llist.addLast(10);
    llist.addLast(20);
    llist.addLast(30);
    llist.print();          // 10 20 30

    llist.addFirst(5);
    llist.print();          // 5 10 20 30

    llist.insertI(2, 15);
    llist.print();          // 5 10 15 20 30

    cout << "Access index 3: ";
    llist.accessList(3); // 20

    llist.deleteFirst();
    llist.print();          // 10 15 20 30

    llist.deleteLast();
    llist.print();          // 10 15 20

    llist.deleteI(1);
    llist.print();          // 10 20

    cout << "Print reverse: ";
    llist.printReverse();   // 20 10

    return 0;
}
