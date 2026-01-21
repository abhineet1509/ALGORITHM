#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

class Solution {
    int maxZigZag;
    
    pair<int,int> dfs(TreeNode* node) {
        if (!node) return make_pair(-1, -1);
        pair<int,int> left = dfs(node->left);
        pair<int,int> right = dfs(node->right);
        int leftZig = 1 + left.second;
        int rightZig = 1 + right.first;
        if (leftZig > maxZigZag) maxZigZag = leftZig;
        if (rightZig > maxZigZag) maxZigZag = rightZig;
        return make_pair(leftZig, rightZig);
    }
    
public:
    int longestZigZag(TreeNode* root) {
        maxZigZag = 0;
        dfs(root);
        return maxZigZag;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(6);
    root->right->right = new TreeNode(5);
    root->right->right->right = new TreeNode(7);

    Solution sol;
    cout << "Longest ZigZag Path: " << sol.longestZigZag(root) << "\n";

    return 0;
}
