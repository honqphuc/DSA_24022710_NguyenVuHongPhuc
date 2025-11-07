#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* right;
    Node* left;
    int height;
};

int getHeight(Node* root){
    if(root == 0){ return 0;}
    else return root->height;
}

int getBalance(Node *root) {
    if (root == nullptr)
        return 0;
    return getHeight(root->left) - getHeight(root->right);
}

Node* rightRotate(Node* root){
    Node* x = root->left;

    root->left = x->right;
    x->right = root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    x->height    = 1 + max(getHeight(x->left), getHeight(x->right));

    return x;
}

Node* leftRotate(Node* root) {
    Node* x = root->right;

    root->right = x->left;
    x->left = root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    x->height    = 1 + max(getHeight(x->left), getHeight(x->right));

    return x;
}

Node* Insert(Node* root, int value){
    if (root == NULL)
		return new Node{value, NULL, NULL, 1};

    if (value > root->data)
		root->right = Insert(root->right, value);
	else if (value < root->data)
		root->left = Insert(root->left, value);
	else
		return root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int BalenceFactor = getBalance(root);

    // Left left
	if (BalenceFactor > 1 && value < root->left->data)
		return rightRotate(root);

	// Right Right
	if (BalenceFactor < -1 && value > root->right->data)
		return leftRotate(root);

	// Left Right
	if (BalenceFactor > 1 && value > root->left->data) {
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	// Right Left
	if (BalenceFactor < -1 && value < root->right->data) {
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;
}

Node* maxValueNode(Node* root)
{
	Node* current = root;

	// Tìm kiếm Node có giá trị lớn nhất
	while (current->right != NULL)
		current = current->right;

	return current;
}

Node* deleteNode(Node* root, int key) {
	if (root == NULL)
		return root;

	if (key > root->data)
		root->right = deleteNode(root->right, key);
	else if (key < root->data)
		root->left = deleteNode(root->left, key);

	// Nếu key có giá trị bằng với root->data
	// Thì đây chính là Node cần xóa
	else {
		// Trường hợp 0 con hoặc 1 con
		if (root->left == NULL || root->right == NULL) {
			Node* temp = root->left;
			if (root->right != NULL)
				temp = root->right;

			// TH: 0 con
			if (temp == NULL) {
				temp = root;
				root = NULL;
				delete temp;
			}
			// TH: 1 con
			else {
				*root = *temp;
				delete temp;
			}
		}
		// Trường hợp 2 con
		else {
			// Tìm Node lớn nhất bên trái (nhỏ nhất bên phải)
			Node* temp = maxValueNode(root->left);

			// Đưa data của temp vào root
			root->data = temp->data;

			// Xóa temp như 2 TH trên
			root->right = deleteNode(root->right, temp->data);
		}
	}

	// Nếu không còn gì thì trả về luôn
	if (root == NULL)
		return root;

	root->height = 1 + max(getHeight (root->left), getHeight (root->right));

	int valBalance = getBalance(root);


	if (valBalance > 1 && getBalance(root->left) >= 0)
		return rightRotate(root);

	if (valBalance < -1 && getBalance(root->right) <= 0)
		return leftRotate(root);

	if (valBalance > 1 && getBalance(root->left) < 0){
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	if (valBalance < -1 && getBalance(root->right) > 0){
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;
}

void inOrder(Node* root) {
    if (root != nullptr) {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

int main() {
    Node* root = nullptr;

    root = Insert(root, 30);
    root = Insert(root, 20);
    root = Insert(root, 40);
    root = Insert(root, 10);
    root = Insert(root, 25);
    root = Insert(root, 50);

    cout << "Cay AVL : ";
    inOrder(root);
    cout << endl;

    cout << "Xoa node 40" << endl;
    root = deleteNode(root, 40);

    cout << "Cay AVL sau khi xoa : ";
    inOrder(root);
    cout << endl;

    return 0;
}
