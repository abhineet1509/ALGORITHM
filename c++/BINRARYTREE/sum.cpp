#include <bits/stdc++.h>
using namespace std;

// Binary Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Sum of all nodes in binary tree
int sumOfTree(Node* root) {
    if (root == NULL) return 0;
    return root->data + sumOfTree(root->left) + sumOfTree(root->right);
}

// Sum of leaf nodes in binary tree
int sumOfLeaves(Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL)
        return root->data;
    return sumOfLeaves(root->left) + sumOfLeaves(root->right);
}

int main() {
    /*
            10
           /  \
          5    15
         / \     \
        3   7     18
    */

    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->right = new Node(18);

    cout << "Sum of Binary Tree: " << sumOfTree(root) << endl;
    cout << "Sum of Leaf Nodes: " << sumOfLeaves(root) << endl;

    return 0;
}
