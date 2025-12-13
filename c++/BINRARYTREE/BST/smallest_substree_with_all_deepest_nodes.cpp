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
    // Returns pair {depth, subtree}
    pair<int, TreeNode*> dfs(TreeNode* root) {
        if (!root) return {0, nullptr};

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        if (left.first == right.first)
            return {left.first + 1, root};
        else if (left.first > right.first)
            return {left.first + 1, left.second};
        else
            return {right.first + 1, right.second};
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).second;
    }
};

// ---------- MAIN ----------
int main() {
    /*
            3
           / \
          5   1
         / \
        6   2
           / \
          7   4
    */

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    Solution ob;
    TreeNode* res = ob.subtreeWithAllDeepest(root);

    if (res)
        cout << "Root of smallest subtree with all deepest nodes: " << res->val << endl;
    else
        cout << "Tree is empty" << endl;

    return 0;
}
