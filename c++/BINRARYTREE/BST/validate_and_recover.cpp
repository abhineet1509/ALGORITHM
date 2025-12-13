#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // ---------- VALIDATE BST ----------
    void inorder(TreeNode* root, vector<int>& v) {
        if (!root) return;
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }

    bool isValidBST(TreeNode* root) {
        vector<int> v;
        inorder(root, v);
        for (int i = 1; i < v.size(); i++) {
            if (v[i] <= v[i - 1]) return false;
        }
        return true;
    }

    // ---------- RECOVER BST ---------- fic two node
    TreeNode *first = NULL, *second = NULL, *prev = NULL;

    void fix(TreeNode* root) {
        if (!root) return;

        fix(root->left);

        if (prev && root->val < prev->val) {
            if (!first) first = prev;
            second = root;
        }
        prev = root;

        fix(root->right);
    }

    void recoverTree(TreeNode* root) {
        fix(root);
        if (first && second)
            swap(first->val, second->val);
    }
};

// ------------------ MAIN ------------------
int main() {
    /*
        Example tree (invalid BST):
                3
               / \
              1   4
                 /
                2
    */

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(2);

    Solution ob;

    cout << "Valid before recover: "
         << ob.isValidBST(root) << endl;

    ob.recoverTree(root);

    cout << "Valid after recover: "
         << ob.isValidBST(root) << endl;

    return 0;
}
