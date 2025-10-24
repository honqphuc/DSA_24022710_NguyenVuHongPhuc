#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

struct BST{
    Node *root;

    BST(){
        root = nullptr;
    }

    bool isBST(Node *r){
        if(r == nullptr){
            return true;
        }
        if(r->left && r->left->data >= r->data){
            return false;
        } else if(r->right && r->right->data <= r->data){
            return false;
        } else {
            return isBST(r->left) && isBST(r->right);
        }
    }

    bool isBinarySearchTree(){
        return isBST(root);
    }

    void putt(Node *&r, int value){
        if(r == nullptr){
            r = new Node{value, nullptr, nullptr};
            return;
        }
        if(value < r->data){
            putt(r->left, value);
        } else if (value > r->data){
            putt(r->right, value);
        } else {
            return;
        }
    }

    void put(int value){
        putt(root, value);
    }

    Node* gett(Node *r, int value){
        if(r == nullptr){
            return nullptr;
        } else if(value == r->data){
            return r;
        } else if(value < r->data){
            return gett(r->left, value);
        } else {
            return gett(r->right, value);
        }
    }

    int get(int value){
        Node *r = gett(root, value);
        if(r == nullptr){
            return -1;
        } else {
            return r -> data;
        }
    }

    void deleteNode(Node *&r, int x){
        if(r == nullptr){
            return;
        }
        if(x < r->data){
            deleteNode(r->left, x);
        } else if(x > r->data){
            deleteNode(r->right, x);
        } else {
            if(r->left == nullptr && r->right == nullptr){
                delete r;
                r = nullptr;
            } else if(r->left == nullptr){
                Node *temp = r;
                r = r->right;
                delete temp;
            } else if(r->right == nullptr){
                Node *temp = r;
                r = r->left;
                delete temp;
            } else {
                Node *p = r->right;
                while(p->left != nullptr){
                    p = p->left;
                }
                r->data = p->data;
                deleteNode(r->right, p->data);
            }
        }
    }
    void deleteValue(int x){
        deleteNode(root, x);
    }


    void preorderr(Node *r){
        if(r == nullptr){
            return;
        }
        cout << r->data << " ";
        preorderr(r->left);
        preorderr(r->right);
    }
    void preorder(){
        if(root == nullptr){
            return;
        } else {
            preorderr(root);
        }
    }

    void postorderr(Node *r){
        if(r == nullptr){
            return;
        }
        postorderr(r->left);
        postorderr(r->right);
        cout << r->data << " ";
    }
    void postorder(){
        if(root == nullptr){
            return;
        } else {
            postorderr(root);
        }
    }

    void inorderr(Node *r){
        if(r == nullptr){
            return;
        }
        inorderr(r->left);
        cout << r->data << " ";
        inorderr(r->right);
    }
    void inorder(){
        if(root == nullptr){
            return;
        } else {
            inorderr(root);
        }
    }
};

int main() {
    BST tree;

    tree.put(50);
    tree.put(30);
    tree.put(70);
    tree.put(20);
    tree.put(40);
    tree.put(60);
    tree.put(80);

    cout << "Cay hien tai co phai la BST hop le khong? ";
    cout << (tree.isBinarySearchTree() ? "Co" : "Khong") << endl;

    int x = 40;
    cout << "\nTim gia tri " << x << " trong cay: ";
    int result = tree.get(x);
    if (result != -1)
        cout << "Tim thay " << result << endl;
    else
        cout << "Khong tim thay!" << endl;

    tree.deleteValue(70);

    tree.inorder();
    cout << endl;

    tree.put(75);

    tree.inorder();
    cout << endl;

    return 0;
}
