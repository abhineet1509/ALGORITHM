#include <bits/stdc++.h>
using namespace std;

// ---------- Tree Node ----------
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// ---------- SOLUTION ----------
class Solution {
public:
    // ===== PATH SUM I =====
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        if (!root->left && !root->right)
            return targetSum == root->val;

        return hasPathSum(root->left, targetSum - root->val) ||
               hasPathSum(root->right, targetSum - root->val);
    }

    // ===== PATH SUM II =====
    vector<vector<int>> res;
    vector<int> path;

    void dfsPath(TreeNode* root, int targetSum) {
        if (!root) return;

        path.push_back(root->val);

        if (!root->left && !root->right && targetSum == root->val)
            res.push_back(path);

        dfsPath(root->left, targetSum - root->val);
        dfsPath(root->right, targetSum - root->val);

        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        res.clear();
        path.clear();
        dfsPath(root, targetSum);
        return res;
    }

    // ===== PATH SUM III =====
    unordered_map<long long, int> mp;
    int countPaths = 0;

    void dfsPrefix(TreeNode* root, long long curr, int targetSum) {
        if (!root) return;

        curr += root->val;

        if (mp.count(curr - targetSum))
            countPaths += mp[curr - targetSum];

        mp[curr]++;
        dfsPrefix(root->left, curr, targetSum);
        dfsPrefix(root->right, curr, targetSum);
        mp[curr]--;
    }

    int pathSumIII(TreeNode* root, int targetSum) {
        mp.clear();
        countPaths = 0;
        mp[0] = 1;
        dfsPrefix(root, 0, targetSum);
        return countPaths;
    }
};

// ---------- MAIN ----------
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

    Solution ob;

    cout << "Path Sum I: " << ob.hasPathSum(root, 18) << endl;

    auto v = ob.pathSum(root, 18);
    cout << "Path Sum II paths:\n";
    for (auto &p : v) {
        for (int x : p) cout << x << " ";
        cout << endl;
    }

    cout << "Path Sum III count: " << ob.pathSumIII(root, 8);

    return 0;
}
