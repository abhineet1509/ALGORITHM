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
    int kthLargestLevelSum(TreeNode* root, int k) {
        if (!root) return -1;

        vector<long long> levelSums;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int sz = q.size();
            long long sum = 0;
            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front(); q.pop();
                sum += node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            levelSums.push_back(sum);
        }

        sort(levelSums.rbegin(), levelSums.rend()); // descending
        return (k <= levelSums.size()) ? levelSums[k-1] : -1;
    }
};

// ---------- MAIN ----------
int main() {
    /*
            5
           / \
          2   8
         / \   \
        1   3   10
    */

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(10);

    int k = 2;

    Solution ob;
    int ans = ob.kthLargestLevelSum(root, k);
    cout << k << "-th largest level sum: " << ans << endl;

    return 0;
}
