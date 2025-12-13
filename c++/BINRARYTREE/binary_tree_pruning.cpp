#include <bits/stdc++.h>
using namespace std;

// ---------- TREE NODE ----------
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// ---------- SOLUTION ----------
class Solution {
public:
    // ===== DFS Pruning =====
    TreeNode* pruneTree(TreeNode* root) {
        if (!root) return nullptr;

        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);

        // if current node is 0 and both children are null, remove it
        if (root->val == 0 && !root->left && !root->right)
            return nullptr;

        return root;
    }

    // Utility: Inorder Print
    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
};

// ---------- MAIN ----------
int main() {
    /*
            1
           / \
          0   1
         / \
        0   0
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(0);

    Solution ob;
    cout << "Inorder before pruning: ";
    ob.inorder(root);
    cout << endl;

    root = ob.pruneTree(root);

    cout << "Inorder after pruning: ";
    ob.inorder(root);
    cout << endl;

    return 0;
}
