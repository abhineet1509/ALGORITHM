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

Node* insert(Node* root, int key) {
    if (!root) return new Node(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);

    return root;
}

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) {
    pre = suc = NULL;

    while (root) {
        if (root->data == key) {

            if (root->left) {
                Node* temp = root->left;
                while (temp->right)
                    temp = temp->right;
                pre = temp;
            }

            if (root->right) {
                Node* temp = root->right;
                while (temp->left)
                    temp = temp->left;
                suc = temp;
            }
            return;
        }
        else if (key < root->data) {
            suc = root;
            root = root->left;
        }
        else {
            pre = root;
            root = root->right;
        }
    }
}

int main() {
    Node* root = NULL;

    int arr[] = {20, 8, 22, 4, 12, 10, 14};
    for (int x : arr)
        root = insert(root, x);

    int key = 10;

    Node *pre = NULL, *suc = NULL;
    findPreSuc(root, pre, suc, key);

    cout << "Key = " << key << endl;

    if (pre)
        cout << "Predecessor = " << pre->data << endl;
    else
        cout << "Predecessor = NULL" << endl;

    if (suc)
        cout << "Successor = " << suc->data << endl;
    else
        cout << "Successor = NULL" << endl;

    return 0;
}
