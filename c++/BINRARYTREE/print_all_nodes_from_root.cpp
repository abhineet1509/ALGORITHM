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

void printAllPaths(Node* root, vector<int>& path) {
    if (!root) return;

    path.push_back(root->data);

    if (!root->left && !root->right) {
        for (int x : path) cout << x << " ";
        cout << endl;
    } 
        printAllPaths(root->left, path);
        printAllPaths(root->right, path);

    path.pop_back();
}

int main() {
    /*
            1
           / \
          2   3
         / \   \
        4   5   6
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    cout << "All root-to-leaf paths:\n";
    vector<int> path;
    printAllPaths(root, path);
    return 0;
}
