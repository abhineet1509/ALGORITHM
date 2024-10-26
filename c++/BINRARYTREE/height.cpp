#include<iostream>
#include <algorithm>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

int height(Node *root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}

Node* BinaryTree() {
    int x;
    cin >> x;
    if (x == -1) return NULL;
    Node* temp = new Node(x);
    cout << "Enter the left child of " << x << endl;
    temp->left = BinaryTree();
    cout << "Enter the right child of " << x << endl;
    temp->right = BinaryTree();
    return temp;
}

int main() {
    cout << "Enter the root node: ";
    Node *root = BinaryTree();
    int treeHeight = height(root);
    cout << "Height of the binary tree: " << treeHeight << endl;
    return 0;
}
