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
    // ===== DFS APPROACH =====
    int maxDepth = 0, sum = 0;

    void dfs(TreeNode* root, int depth) {
        if (!root) return;

        if (!root->left && !root->right) {
            if (depth > maxDepth) {
                maxDepth = depth;
                sum = root->val;
            } else if (depth == maxDepth) {
                sum += root->val;
            }
        }

        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);
    }

    int deepestLeavesSumDFS(TreeNode* root) {
        maxDepth = 0;
        sum = 0;
        dfs(root, 0);
        return sum;
    }

    // ===== BFS APPROACH =====
    int deepestLeavesSumBFS(TreeNode* root) {
        if (!root) return 0;

        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;

        while (!q.empty()) {
            int sz = q.size();
            ans = 0;

            while (sz--) {
                TreeNode* cur = q.front(); q.pop();
                ans += cur->val;

                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
        }
        return ans;
    }
};

// ---------- MAIN ----------
int main() {
    /*
            1
           / \
          2   3
         / \   \
        4   5   6
       /
      7
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->left->left->left = new TreeNode(7);

    Solution ob;

    cout << "Deepest Leaves Sum (DFS): " 
         << ob.deepestLeavesSumDFS(root) << endl;

    cout << "Deepest Leaves Sum (BFS): " 
         << ob.deepestLeavesSumBFS(root) << endl;

    return 0;
}
