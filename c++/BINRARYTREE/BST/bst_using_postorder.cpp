#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

Node* constructBST(vector<int>& post, int& idx, int low, int high) {
    if (idx < 0) return NULL;

    int val = post[idx];
    if (val < low || val > high) return NULL;

    Node* root = new Node(val);
    idx--;

    // Build right subtree first (because of postorder)
    root->right = constructBST(post, idx, val, high);
    root->left  = constructBST(post, idx, low, val);

    return root;
}

Node* bstFromPostorder(vector<int>& post) {
    int idx = post.size() - 1;
    return constructBST(post, idx, INT_MIN, INT_MAX);
}

// Inorder print to verify BST correctness
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// ---------------- Driver Code ----------------
int main() {
    vector<int> post = {2, 4, 3, 8, 7, 5};

    Node* root = bstFromPostorder(post);

    cout << "Inorder of constructed BST: ";
    inorder(root);  // Should print sorted order

    return 0;
}
