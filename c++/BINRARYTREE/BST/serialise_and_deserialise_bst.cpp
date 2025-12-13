#include <bits/stdc++.h>
using namespace std;

// ---------- Tree Node ----------
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// ---------- SOLUTION ----------
class Codec {
public:
    // ===== SERIALIZE (PREORDER) =====
    void preorder(TreeNode* root, string &s) {
        if (!root) return;
        s += to_string(root->val) + " ";
        preorder(root->left, s);
        preorder(root->right, s);
    }

    string serialize(TreeNode* root) {
        string s;
        preorder(root, s);
        return s;
    }

    // ===== DESERIALIZE (USING BST RANGE) =====
    TreeNode* build(vector<int>& pre, int &i, int low, int high) {
        if (i == pre.size()) return NULL;
        if (pre[i] < low || pre[i] > high) return NULL;

        TreeNode* root = new TreeNode(pre[i++]);
        root->left = build(pre, i, low, root->val);
        root->right = build(pre, i, root->val, high);

        return root;
    }

    TreeNode* deserialize(string data) {
        vector<int> pre;
        stringstream ss(data);
        int x;
        while (ss >> x) pre.push_back(x);

        int i = 0;
        return build(pre, i, INT_MIN, INT_MAX);
    }
};

// ---------- INORDER PRINT ----------
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// ---------- MAIN ----------
int main() {
    /*
            8
           / \
          5   10
         / \    \
        1   7    12
    */

    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(5);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(12);

    Codec codec;

    string data = codec.serialize(root);
    cout << "Serialized: " << data << endl;

    TreeNode* newRoot = codec.deserialize(data);
    cout << "Inorder after Deserialization: ";
    inorder(newRoot);

    return 0;
}
