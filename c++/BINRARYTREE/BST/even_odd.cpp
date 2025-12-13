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
    bool isEvenOddTree(TreeNode* root) {
        if (!root) return true;

        queue<TreeNode*> q;
        q.push(root);
        int level = 0;

        while (!q.empty()) {
            int sz = q.size();
            int prevVal = (level % 2 == 0) ? INT_MIN : INT_MAX;

            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front(); q.pop();
                int val = node->val;

                // Check parity
                if (level % 2 == 0) {
                    // Even-indexed level -> odd values strictly increasing
                    if (val % 2 == 0 || val <= prevVal) return false;
                } else {
                    // Odd-indexed level -> even values strictly decreasing
                    if (val % 2 != 0 || val >= prevVal) return false;
                }
                prevVal = val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            level++;
        }

        return true;
    }
};

// ---------- MAIN ----------
int main() {
    /*
            1
           / \
          10  4
         /    \
        3      7
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(10);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(3);
    root->right->right = new TreeNode(7);

    Solution ob;
    if (ob.isEvenOddTree(root))
        cout << "The tree is an Even-Odd Tree" << endl;
    else
        cout << "The tree is NOT an Even-Odd Tree" << endl;

    return 0;
}
