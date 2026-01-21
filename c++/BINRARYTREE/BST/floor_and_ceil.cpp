#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

// Insert into BST
Node* insert(Node* root, int key) {
    if (!root) return new Node(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);

    return root;
}

// Find Floor (largest value <= x)
int findFloor(Node* root, int x) {
    int floor = -1;

    while (root) {
        if (root->data == x)
            return x;

        if (root->data > x) {
            root = root->left;
        } else {
            floor = root->data;
            root = root->right;
        }
    }
    return floor;
}

// Find Ceil (smallest value >= x)
int findCeil(Node* root, int x) {
    int ceil = -1;

    while (root) {
        if (root->data == x)
            return x;

        if (root->data < x) {
            root = root->right;
        } else {
            ceil = root->data;
            root = root->left;
        }
    }
    return ceil;
}

int main() {
    Node* root = NULL;

    // Create BST
    vector<int> values = {15, 10, 20, 8, 12, 16, 25};
    for (int x : values)
        root = insert(root, x);

    int key = 13;

    cout << "Key = " << key << endl;
    cout << "Floor = " << findFloor(root, key) << endl;
    cout << "Ceil  = " << findCeil(root, key) << endl;

    return 0;
}
