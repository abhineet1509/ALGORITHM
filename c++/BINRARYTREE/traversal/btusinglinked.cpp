#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class BinaryTreeLinked {
    Node* root;

public:
    BinaryTreeLinked() {
        root = nullptr;
    }

    Node* getRoot() {
        return root;
    }

    void insertRoot(int val) {
        if (!root) root = new Node(val);
    }

    void preorder(Node* node) {
        if (!node) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }
};

int main() {
    BinaryTreeLinked bt;

    bt.insertRoot(1);
    bt.getRoot()->left = new Node(2);
    bt.getRoot()->right = new Node(3);
    bt.getRoot()->left->left = new Node(4);
    bt.getRoot()->left->right = new Node(5);

    cout << "Preorder traversal: ";
    bt.preorder(bt.getRoot());
    cout << endl;

    return 0;
}
