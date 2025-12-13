#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

// LCA in BST
Node* LCA_BST(Node* root, int a, int b) {
    while (root) {
        if (a < root->val && b < root->val) root = root->left;
        else if (a > root->val && b > root->val) root = root->right;
        else return root;
    }
    return NULL;
}

// LCA in Binary Tree
Node* LCA_BT(Node* root, int a, int b) {
    if (!root) return NULL;
    if (root->val == a || root->val == b) return root;

    Node* left = LCA_BT(root->left, a, b);
    Node* right = LCA_BT(root->right, a, b);

    if (left && right) return root;
    return left ? left : right;
}

int main() {
    // BST
    Node* bst = new Node(20);
    bst->left = new Node(10);
    bst->right = new Node(30);
    bst->left->left = new Node(5);
    bst->left->right = new Node(15);

    cout << "LCA in BST (5,15): " << LCA_BST(bst, 5, 15)->val << endl;

    // Binary Tree
    Node* bt = new Node(1);
    bt->left = new Node(2);
    bt->right = new Node(3);
    bt->left->left = new Node(4);
    bt->left->right = new Node(5);

    cout << "LCA in BT (4,5): " << LCA_BT(bt, 4, 5)->val << endl;

    return 0;
}
