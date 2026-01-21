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

int countNodes(Node* root) {
    if (!root) return 0;

    int lh = 0, rh = 0;
    Node* temp = root;

    // Calculate left height
    while (temp) {
        lh++;
        temp = temp->left;
    }

    // Calculate right height
    temp = root;
    while (temp) {
        rh++;
        temp = temp->right;
    }

    // If perfect binary tree
    if (lh == rh) {
        int nodes = 1;
        for (int i = 0; i < lh; i++)
            nodes *= 2;
        return nodes - 1;
    }

    // Otherwise recurse
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
    /*
            1
           / \
          2   3
         / \  /
        4   5 6
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);

    cout << "Total number of nodes: " << countNodes(root) << endl;

    return 0;
}
