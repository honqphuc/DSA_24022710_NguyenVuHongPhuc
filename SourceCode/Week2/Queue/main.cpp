#include <iostream>
#include "List.cpp"
#include "LinkedList.cpp"

using namespace std;

struct queueList{
    List list;

    bool isEmpty(){
        if(list.size == 0){
            return true;
        }
        else return false;
    }


    void enqueue(int item){
        list.addFirst(item);
    }

    int dequeue(){
        return list.deleteLast();
    }

    int peek(){
        if (list.size == 0){
            cout<<"cannot peek"<<endl;
            return -1;
        }
        return list.a[list.size - 1];
    }

    int sizze(){
        return list.size;
    }
};


struct queueLinkedList{
    LinkedList llist;

    bool isEmpty(){
        if(llist.head == NULL){
            return true;
        }
        else return false;
    }

    void enqueue(int item){
        llist.addLast(item);
    }

    int dequeue(){
        return llist.deleteFirst();
    }

    int peek(){
        if(isEmpty()){
            cout<<"cannot peek"<<endl;
            return -1;
        }
        return llist.head->data;
    }

    int sizze(){
        return llist.size;
    }
};


int main() {
    queueList q1;

    cout<<"queueList test"<<endl;
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);

    cout << "Size: " << q1.sizze() << endl; //3
    cout << "Peek: " << q1.peek() << endl; //10

    cout << "Dequeue: " << q1.dequeue() << endl; //10
    cout << "Dequeue: " << q1.dequeue() << endl; //20
    cout << "Size: " << q1.sizze() << endl; //1

    queueLinkedList q2;

    cout<<"queueLinkedList test"<<endl;
    q2.enqueue(100);
    q2.enqueue(200);
    q2.enqueue(300);

    cout << "Size: " << q2.sizze() << endl; //3
    cout << "Peek: " << q2.peek() << endl; //100

    cout << "Dequeue: " << q2.dequeue() << endl; //100
    cout << "Dequeue: " << q2.dequeue() << endl; //200
    cout << "Size: " << q2.sizze() << endl; //1

    return 0;
}
