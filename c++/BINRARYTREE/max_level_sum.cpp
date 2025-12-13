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
    int maxLevelSum(TreeNode* root) {
        if (!root) return 0;

        queue<TreeNode*> q;
        q.push(root);
        int maxSum = INT_MIN, level = 0, ansLevel = 0;

        while (!q.empty()) {
            int sz = q.size();
            level++;
            int currSum = 0;

            for (int i = 0; i < sz; i++) {
                TreeNode* cur = q.front(); q.pop();
                currSum += cur->val;

                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }

            if (currSum > maxSum) {
                maxSum = currSum;
                ansLevel = level;
            }
        }
        return ansLevel;
    }
};

// ---------- MAIN ----------
int main() {
    /*
            1
           / \
          7   0
         / \
        7  -8
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(7);
    root->right = new TreeNode(0);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(-8);

    Solution ob;
    cout << "Level with Maximum Sum: " << ob.maxLevelSum(root) << endl;

    return 0;
}
