#define MAX 100
#include<iostream>

using namespace std;

struct List {
    int a[MAX];
    int size;

    List() {
        size = 0;
    }
    //O(1)
    int accessList(int index) {
        if(index < 0 || index >= size) {
            cout << "Invalid index" << endl;
            return -1;
        }
        return a[index];
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
    int deleteLast() {
        if (size == 0) {
            cout<<"Empty list\n";
            return -1;
        }
        int value = a[size - 1];
        size--;
        return value;
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

