#include <iostream>
#include "List.cpp"
#include "LinkedList.cpp"

using namespace std;

struct stackList{
    List list;

    bool isEmpty(){
        if(list.size == 0){
            return true;
        }
        else return false;
    }

    void push(int item){
        list.addLast(item);
    }

    int pop(){
        if(isEmpty()){
            cout<<"cannot pop"<<endl;
            return -1;
        }
        return list.deleteLast();
    }

    int sizze(){
        return list.size;
    }

    int top(){
        if(isEmpty()){
            cout<<"cannot top"<<endl;
            return -1;
        }
        return list.a[list.size - 1];
    }
};


struct stackLinkedList{
    LinkedList llist;

    bool isEmpty(){
        if(llist.head == NULL){
            return true;
        }
        else return false;
    }

    void push(int item){
        llist.addFirst(item);
    }

    int pop(){
        if(isEmpty()){
            cout<<"cannot pop"<<endl;
            return -1;
        }
        return llist.deleteFirst();
    }

    int sizze(){
        return llist.size;
    }

    int top(){
        if(isEmpty()){
            cout<<"cannot top"<<endl;
            return -1;
        }
        return llist.head->data;
    }
};

int main() {
    //list
    stackList s1;

    s1.push(10);
    s1.push(20);
    s1.push(30);

    cout << s1.top() << endl; //30
    cout << s1.sizze() << endl; //3

    cout << s1.pop() << endl; //30
    cout << s1.pop() << endl; //20
    cout << s1.sizze() << endl; //1
    cout << s1.isEmpty() << endl; //false

    //linkedlist
    stackLinkedList s2;

    s2.push(100);
    s2.push(200);
    s2.push(300);

    cout << s2.top() << endl; //300
    cout << s2.sizze() << endl; //3

    cout << s2.pop() << endl; //300
    cout << s2.pop() << endl; //200
    cout << s2.sizze() << endl; //1
    cout << s2.isEmpty() << endl; //false

    return 0;
}

