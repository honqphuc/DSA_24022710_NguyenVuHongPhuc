#include <iostream>

using namespace std;


struct Node {
    int data;
    Node* next;
    Node(int d, Node* n = NULL){
        data = d;
        next = n;
    }
};

struct LinkedList {
    Node* head;
    int size;

    LinkedList() {
        head = NULL;
        size = 0;
    }

    //O(n)
    void accessList(int index) {
        Node* a = head;
        if(head == NULL) {
            cout<<"Cannot access";
        }
        else {
            for(int i = 1; i < index && a != NULL; i++){
                a = a->next;
                return;
            }
        }
        if (a == NULL) {
            cout << "Cannot access";
        }
        else {
            cout << a->data;
        }
    }

    //O(1)
    void addFirst(int x) {
        Node* newNode = new Node(x);
        newNode->next = head;
        head = newNode;
        size++;
    }

    //O(n)
    void addLast(int x) {
        Node* newNode = new Node(x);
        Node* a = head;
        if(head == NULL) {
            head = newNode;
        }
        else{
            while(a->next != NULL) {
                a = a->next;
            }
            a->next = newNode;
        }
        size++;
    }

    //O(n)
    void insertI(int index, int x) {
        if(index <= 0 || index > size + 1) {
            cout<<"Invalid index"<<endl;
            return;
        }
        if(index == 1) {
            addFirst(x);
            return;
        }
        else if(index == size + 1) {
            addLast(x);
            return;
        }
        Node* newNode = new Node(x);
        Node* a = head;
        for(int i = 1; i < index - 1; i++) {
            a = a->next;
        }
        newNode->next = a->next;
        a->next = newNode;
        size++;
    }

    //O(1)
    int deleteFirst() {
        if(head == NULL) {
            cout << "Cannot delete" << endl;
            return -1;
        }
        Node* a= head;
        head = head->next;

        int value = a->data;
        delete a;
        size--;
        return value;
    }

    //O(n)
    void deleteLast() {
        if(head == NULL) {
            cout << "Cannot delete" << endl;
            return;
        }
        Node* truoc = NULL;
        Node* sau = head;
        while(sau->next != NULL) {
            truoc = sau;
            sau = sau->next;
        }
        if(truoc == NULL) { //ds co 1 phan tu
            head = NULL;
        }
        else {
            truoc->next = NULL;
        }
        delete sau;
        size--;
    }

    //0(n)
    void deleteI(int index) {
        if(head == NULL) {
            cout<<"Cannot delete" << endl;
            return;
        }
        if(index == 1) {
            deleteFirst();
            return;
        }
        Node* truoc = NULL;
        Node* sau = head;
        for(int i = 1; i < index; i++) {
            truoc = sau;
            sau = sau->next;
            if (sau == NULL) { // index vuot do dai
                cout << "Invalid index" << endl;
                return;
            }
        }
        if(sau->next == NULL) {
            deleteLast();
        }
        else {
            truoc->next = sau->next;
            delete sau;
        }
        size--;
    }

    //O(n)
    void print() {
        Node* a = head;
        if (head == NULL){
            cout<<"Nothing"<<endl;
            return;
        }
        while(a != NULL) {
            cout << a->data<<" ";
            a = a->next;
        }

    }
    //O(n)
    void reversePrint(Node* head) {
        if (head == NULL){
            cout<<"Nothing"<<endl;
            return;
        }
        reversePrint(head -> next);
        cout<<head->data<<" ";

    }


    // O(n) — Xóa node có giá trị = key (dùng cho bảng băm)
bool deleteValue(int key) {
    if (head == NULL) return false;

    Node* cur = head;
    Node* prev = NULL;

    while (cur != NULL) {
        if (cur->data == key) {
            if (prev == NULL) {
                head = cur->next;
            } else {
                prev->next = cur->next;
            }
            delete cur;
            size--;
            return true;
        }
        prev = cur;
        cur = cur->next;
    }
    return false;
}

bool find(int key) {
    Node* cur = head;
    while (cur != NULL) {
        if (cur->data == key)
            return true;
        cur = cur->next;
    }
    return false;
}

};
