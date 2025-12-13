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
    int maxSum = 0;

    // Returns {isBST, minVal, maxVal, sum}
    tuple<bool, int, int, int> dfs(TreeNode* root) {
        if (!root) return {true, INT_MAX, INT_MIN, 0};

        auto [isLeftBST, leftMin, leftMax, leftSum] = dfs(root->left);
        auto [isRightBST, rightMin, rightMax, rightSum] = dfs(root->right);

        bool isBST = isLeftBST && isRightBST && (root->val > leftMax) && (root->val < rightMin);
        int currSum = leftSum + rightSum + root->val;

        if (isBST) maxSum = max(maxSum, currSum);

        int currMin = min(root->val, leftMin);
        int currMax = max(root->val, rightMax);

        return {isBST, currMin, currMax, currSum};
    }

    int maxSumBST(TreeNode* root) {
        maxSum = 0;
        dfs(root);
        return maxSum;
    }
};

// ---------- MAIN ----------
int main() {
    /*
            1
           / \
          4   3
         / \   \
        2   4   5
               / \
              4   6
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(4);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(5);
    root->right->right->left = new TreeNode(4);
    root->right->right->right = new TreeNode(6);

    Solution ob;
    cout << "Maximum Sum BST in Binary Tree: " << ob.maxSumBST(root) << endl;

    return 0;
}
