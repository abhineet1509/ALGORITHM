#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->data) root->left = insert(root->left, key);
    else if (key > root->data) root->right = insert(root->right, key);
    return root;
}

int findMin(Node* root) {
    while (root && root->left) root = root->left;
    return root ? root->data : -1;
}

int findMax(Node* root) {
    while (root && root->right) root = root->right;
    return root ? root->data : -1;
}

int main() {
    Node* root = nullptr;
    int n, val;
    cin >> n;
    while (n--) {
        cin >> val;
        root = insert(root, val);
    }
    cout << findMin(root) << endl;
    cout << findMax(root) << endl;
    return 0;
}
