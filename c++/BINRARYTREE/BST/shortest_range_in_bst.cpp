#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

int prevNode = -1e9, minDiff = INT_MAX;

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    if (prevNode != -1e9) minDiff = min(minDiff, root->data - prevNode);
    prevNode = root->data;
    inorder(root->right);
}

int shortestRangeBST(Node* root) {
    prevNode = -1e9;
    minDiff = INT_MAX;
    inorder(root);
    return minDiff;
}

// Example usage
int main() {
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    cout << "Minimum difference: " << shortestRangeBST(root) << endl;
}
