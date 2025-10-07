#include <iostream>
#include "MaxHeap.cpp"

using namespace std;

class priorityQueue{
private:
    MaxHeap heap;
public:
    void insert(int value){
        heap.insert(value);
    }

    int delMax(){
        return heap.delMax();
    }

    bool isEmpty(){
        return heap.isEmpty();
    }

    int getMax(){
        return heap.getMax();
    }

    int getSize(){
        return heap.getSize();
    }

    void print(){
        heap.print();
    }
};

int main()
{
    priorityQueue pQueue;

    pQueue.insert(10);
    pQueue.insert(5);
    pQueue.insert(30);
    pQueue.insert(20);

    pQueue.print(); // Heap: 30 20 10 5

    cout << "Max = " << pQueue.getMax() << endl; // 30
    cout << "Size: " << pQueue.getSize() << endl; // 4

    pQueue.delMax();
    pQueue.print(); // Heap: 20 5 10

    return 0;
}
