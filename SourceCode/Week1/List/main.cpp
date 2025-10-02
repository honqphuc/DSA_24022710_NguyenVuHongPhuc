#include <iostream>
#include "List.h"
using namespace std;

int main()
{
    List list;

    list.addLast(10);
    list.addLast(20);
    list.addLast(30);
    list.print();          // 10 20 30

    list.addFirst(5);
    list.print();          // 5 10 20 30

    list.insertI(2, 15);
    list.print();          // 5 10 15 20 30

    cout << "Access index 3: ";
    list.accessList(3); // 20

    list.deleteFirst();
    list.print();          // 10 15 20 30

    list.deleteLast();
    list.print();          // 10 15 20

    list.deleteI(1);
    list.print();          // 10 20

    cout << "Print reverse: ";
    list.printReverse();   // 20 10

    return 0;
}
