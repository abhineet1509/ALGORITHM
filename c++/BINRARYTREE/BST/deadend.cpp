#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Insert node into BST
Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->data) root->left = insert(root->left, key);
    else if (key > root->data) root->right = insert(root->right, key);
    return root;
}

// Approach 1: Leaf-based dead end check (from your first code)
bool deadLeaf(Node* root, int lower, int upper) {
    if (!root) return false;

    // Only check leaves
    if (!root->left && !root->right) {
        return (root->data - lower == 1) && (upper - root->data == 1);
    }

    return deadLeaf(root->left, lower, root->data) ||
           deadLeaf(root->right, root->data, upper);
}

bool isDeadEndLeaf(Node* root) {
    return deadLeaf(root, 0, INT_MAX);
}

// Approach 2: Range-based dead end check (from second code)
bool deadRange(Node* root, int lower, int upper) {
    if (!root) return false;

    if (lower == upper) return true;

    return deadRange(root->left, lower, root->data - 1) ||
           deadRange(root->right, root->data + 1, upper);
}

bool isDeadEndRange(Node* root) {
    return deadRange(root, 1, INT_MAX); // start from 1
}

int main() {
    Node* root = nullptr;
    vector<int> keys = {8, 5, 9, 2, 7, 1};

    for (int key : keys)
        root = insert(root, key);

    cout << "Leaf-based dead end check: "
         << (isDeadEndLeaf(root) ? "true" : "false") << endl;

    cout << "Range-based dead end check: "
         << (isDeadEndRange(root) ? "true" : "false") << endl;

    return 0;
}
