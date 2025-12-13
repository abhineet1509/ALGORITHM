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
    // ===== 1. DFS / Inorder (optimized) =====
    int prevVal = -1, minDiff = INT_MAX;

    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);

        if (prevVal != -1)
            minDiff = min(minDiff, root->val - prevVal);
        prevVal = root->val;

        inorder(root->right);
    }

    int minDiffInBST(TreeNode* root) {
        prevVal = -1;
        minDiff = INT_MAX;
        inorder(root);
        return minDiff;
    }

    // ===== 2. BFS / Collect + Sort (general BT too) =====
    int minDiffInBST_BFS(TreeNode* root) {
        if (!root) return 0;

        vector<int> vals;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* cur = q.front(); q.pop();
            vals.push_back(cur->val);
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }

        sort(vals.begin(), vals.end());
        int res = INT_MAX;
        for (int i = 1; i < vals.size(); i++)
            res = min(res, vals[i] - vals[i-1]);

        return res;
    }
};

// ---------- MAIN ----------
int main() {
    /*
            4
           / \
          2   6
         / \
        1   3
    */

    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution ob;

    cout << "Min Diff in BST (DFS Inorder): " << ob.minDiffInBST(root) << endl;
    cout << "Min Diff in BST (BFS + Sort): " << ob.minDiffInBST_BFS(root) << endl;

    return 0;
}
