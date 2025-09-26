#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include<iostream>
using namespace std;

struct List {
    int a[100];
    int size;

    List() {
        size = 0;
    }
    //O(1)
    void accessList(int index) {
        if(index < 0 || index >= size) {
            cout << "Invalid index" << endl;
        } else {
            cout << a[index] << endl;
            return;
        }
    }

    //O(n)
    void addFirst(int x) {
        if(size >= 100) {
            cout<<"List full\n";
            return;
        }
        for(int i = size; i>0; i--) {
            a[i] = a[i-1];
        }
        a[0] = x;
        size++;
    }

    //0(1)
    void addLast(int x) {
        if (size >= 100) {
            cout << "List full\n";
            return;
        }
        a[size++] = x;
    }

    //O(n)
    void insertI (int index, int x) {
        if (index < 0 || index > size || size >= 100) {
            cout << "Invalid index\n";
            return;
        }
        for (int i = size; i > index; i--) {
            a[i] = a[i - 1];
        }
        a[index] = x;
        size++;
    }

    //O(n)
    void deleteFirst() {
        if (size == 0) {
            cout<<"Empty list\n";
            return;
        }
        for (int i = 0; i < size - 1; i++) {
            a[i] = a[i + 1];
        }
        size--;
    }

    //O(1)
    void deleteLast() {
        if (size == 0) {
            cout<<"Empty list\n";
            return;
        }
        size--;
    }

    //O(n)
    void deleteI (int index) {
        if (index < 0 || index >= size) {
            cout << "Invalid index\n";
            return;
        }
        for (int i = index; i < size - 1; i++) {
            a[i] = a[i + 1];
        }
        size--;
    }

    //O(n)
     void print() {
        for (int i = 0; i < size; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    //O(n)
    void printReverse() {
        for (int i = size - 1; i >= 0; i--) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};

#endif // LIST_H_INCLUDED
