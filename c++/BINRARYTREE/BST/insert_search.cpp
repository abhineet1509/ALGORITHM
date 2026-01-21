#include <iostream>
using namespace std;
 // O(n^2) , O(n)
// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Insert node into BST
Node* insert(Node* root, int key) {
    if (root == nullptr)
        return new Node(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);

    return root;
}

// Search for a key in BST
bool search(Node* root, int key) {
    if (root == nullptr)
        return false;

    if (key == root->data)
        return true;
    else if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

// Main
int main() {
    Node* root = nullptr;

    // Insert some values
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    int key;
    cout << "Enter key to search: ";
    cin >> key;

    if (search(root, key))
        cout << "Key found in BST.\n";
    else
        cout << "Key not found in BST.\n";

    return 0;
}
