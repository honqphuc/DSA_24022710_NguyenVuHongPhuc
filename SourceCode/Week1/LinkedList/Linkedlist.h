#ifndef LINKEDLIST_INCLUDED
#define LINKEDLIST_INCLUDED

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

    LinkedList() {
        head = NULL;
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
    }

    //O(n)
    void insertI(int index, int x) {
        int count = 0;
        Node* temp = head;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        if(index <= 0 || index > count + 1) {
            cout<<"Invalid index"<<endl;
            return;
        }
        if(index == 1) {
            addFirst(x);
            return;
        }
        else if(index == count + 1) {
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
    }

    //O(1)
    void deleteFirst() {
        if(head == NULL) {
            cout << "Cannot delete" << endl;
            return;
        }
        Node* a= head;
        head = head->next;
        delete a;
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

    void reversePrint(Node* head) {
        if (head == NULL){
            cout<<"Nothing"<<endl;
            return;
        }
        reversePrint(head -> next);
        cout<<head->data<<" ";

    }
};

#endif // LINKEDLIST_INCLUDED

