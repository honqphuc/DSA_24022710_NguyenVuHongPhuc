#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

Node* insert(Node* root, int value) {
    if(root == NULL) {
        root = new Node(value);
        return root;
    }

    if(value > root->data) {
        root->right = insert(root->right, value);
    } else if(value < root->data) {
        root->left = insert(root->left, value);
    }
    return root;
}

void inOrder(Node* root){
    if(root == NULL) {
        return;
    } else {
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }
}

void preOrder(Node* root) {
    if(root == NULL) {
        return;
    } else {
        cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(Node* root) {
    if(root == NULL) {
        return;
    } else {
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->data<<" ";
    }
}

int main()
{
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    //20 30 40 50 60 70 80
    cout << "InOrder: ";
    inOrder(root);
    cout << endl;

    //50 30 20 40 70 60 80
    cout << "preOrder: ";
    preOrder(root);
    cout << endl;

    //20 40 30 60 80 70 50
    cout << "postOrder: ";
    postOrder(root);
    cout << endl;
}
