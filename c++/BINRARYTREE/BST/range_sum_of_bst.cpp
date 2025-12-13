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
    // ===== DFS (Recursive) =====
    int rangeSumBST_DFS(TreeNode* root, int low, int high) {
        if (!root) return 0;
        int sum = 0;
        if (root->val >= low && root->val <= high)
            sum += root->val;

        if (root->val > low)
            sum += rangeSumBST_DFS(root->left, low, high);
        if (root->val < high)
            sum += rangeSumBST_DFS(root->right, low, high);

        return sum;
    }

    // ===== BFS (Iterative) =====
    int rangeSumBST_BFS(TreeNode* root, int low, int high) {
        if (!root) return 0;

        int sum = 0;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();

            if (node->val >= low && node->val <= high)
                sum += node->val;

            if (node->left && node->val > low)
                q.push(node->left);
            if (node->right && node->val < high)
                q.push(node->right);
        }

        return sum;
    }
};

// ---------- MAIN ----------
int main() {
    /*
            10
           /  \
          5    15
         / \     \
        3   7     18
    */

    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(18);

    int low = 7, high = 15;

    Solution ob;
    cout << "Range Sum (DFS): " << ob.rangeSumBST_DFS(root, low, high) << endl;
    cout << "Range Sum (BFS): " << ob.rangeSumBST_BFS(root, low, high) << endl;

    return 0;
}
