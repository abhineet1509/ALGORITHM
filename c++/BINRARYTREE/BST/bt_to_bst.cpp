#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Step 1: Store inorder
void storeInorder(Node* root, vector<int> &v) {
    if (!root) return;
    storeInorder(root->left, v);
    v.push_back(root->data);
    storeInorder(root->right, v);
}

// Step 3: Replace inorder from sorted array
void arrayToBST(Node* root, vector<int> &v, int &i) {
    if (!root) return;
    arrayToBST(root->left, v, i);
    root->data = v[i++];       // replace value
    arrayToBST(root->right, v, i);
}

// Convert Binary Tree to BST
Node* binaryTreeToBST(Node* root) {
    if (!root) return root;

    vector<int> v;
    storeInorder(root, v);     // Step 1

    sort(v.begin(), v.end());  // Step 2

    int i = 0;
    arrayToBST(root, v, i);    // Step 3

    return root;
}

// Inorder print (to verify)
void printInorder(Node* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

// ---------------- Driver Code ----------------
int main() {
    /* Binary Tree:
              10
             /  \
            30   15
           /      \
          20       5
    Output BST inorder will be sorted: 5 10 15 20 30
    */

    Node* root = new Node(10);
    root->left = new Node(30);
    root->right = new Node(15);
    root->left->left = new Node(20);
    root->right->right = new Node(5);

    root = binaryTreeToBST(root);

    cout << "Inorder of BST: ";
    printInorder(root);

    return 0;
}
