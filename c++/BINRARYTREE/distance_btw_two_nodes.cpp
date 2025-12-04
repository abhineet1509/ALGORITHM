#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

Node* LCA(Node* root, int a, int b) {
    if (!root) return NULL;
    if (root->val == a || root->val == b) return root;

    Node* left = LCA(root->left, a, b);
    Node* right = LCA(root->right, a, b);

    if (left && right) return root;
    return left ? left : right;
}

int findDistance(Node* root, int target) {
    if (!root) return -1;
    if (root->val == target) return 0;

    int left = findDistance(root->left, target);
    int right = findDistance(root->right, target);

    if (left == -1 && right == -1) return -1;
    return (left != -1 ? left : right) + 1;
}

int minDistance(Node* root, int a, int b) {
    Node* lca = LCA(root, a, b);

    int d1 = findDistance(lca, a);
    int d2 = findDistance(lca, b);

    return d1 + d2;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << minDistance(root, 4, 5) << endl;  // Output: 2
    cout << minDistance(root, 4, 6) << endl;  // Output: 4

    return 0;
}
