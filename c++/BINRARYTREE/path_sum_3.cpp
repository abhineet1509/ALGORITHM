#include <iostream>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int totalBrute = 0;

    // -----------------------------------------
    // 🔸 Brute-force Recursive Approach
    // -----------------------------------------
    int pathSumBrute(TreeNode* root, int targetSum) {
        if (!root) return 0;

        findPathSum(root, targetSum, 0);
        pathSumBrute(root->left, targetSum);
        pathSumBrute(root->right, targetSum);

        return totalBrute;
    }

    void findPathSum(TreeNode* node, int targetSum, long long currentSum) {
        if (!node) return;

        currentSum += node->val;
        if (currentSum == targetSum)
            totalBrute++;

        findPathSum(node->left, targetSum, currentSum);
        findPathSum(node->right, targetSum, currentSum);
    }

    // -----------------------------------------
    // 🚀 Optimized Prefix Sum Approach (O(N))
    // -----------------------------------------
    int pathSumOptimized(TreeNode* root, int targetSum) {
        unordered_map<long long, int> prefixSum;
        prefixSum[0] = 1;
        return dfs(root, 0, targetSum, prefixSum);
    }

    int dfs(TreeNode* node, long long currSum, int targetSum, unordered_map<long long, int>& prefixSum) {
        if (!node) return 0;

        currSum += node->val;
        int count = prefixSum[currSum - targetSum];

        prefixSum[currSum]++;
        count += dfs(node->left, currSum, targetSum, prefixSum);
        count += dfs(node->right, currSum, targetSum, prefixSum);
        prefixSum[currSum]--; // backtrack

        return count;
    }
};
int main() {
    /*
             10
            /  \
           5   -3
          / \    \
         3   2    11
        / \   \
       3  -2   1
    */
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    root->right->right = new TreeNode(11);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);
    root->left->right->right = new TreeNode(1);

    int target = 8;
    Solution sol;

    cout << "Brute-force count: " << sol.pathSumBrute(root, target) << endl;
    cout << "Optimized count: " << sol.pathSumOptimized(root, target) << endl;

    return 0;
}
