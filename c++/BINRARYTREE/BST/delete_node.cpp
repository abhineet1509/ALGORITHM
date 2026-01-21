#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int val) : data(val) {}
};

// Find minimum value in subtree
Node* minValueNode(Node* root) {
    while (root && root->left) root = root->left;
    return root;
}

// Delete a node
Node* deleteNode(Node* root, int key) {
    if (!root) return nullptr;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Node found

        // Case 1: No child
        if (!root->left && !root->right) {
            delete root;
            return nullptr;
        }

        // Case 2: One child
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: Two children
        Node* temp = minValueNode(root->right); // inorder successor
        root->data = temp->data;                // copy successor value
        root->right = deleteNode(root->right, temp->data); // delete successor
    }
    return root;
}

// Inorder traversal
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Driver
int main() {
    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);

    cout << "Original BST: ";
    inorder(root); cout << endl;

    root = deleteNode(root, 20); // delete leaf
    root = deleteNode(root, 30); // delete node with one child
    root = deleteNode(root, 50); // delete node with two children

    cout << "BST after deletions: ";
    inorder(root); cout << endl;
}
