#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    unordered_map<TreeNode*, TreeNode*> parent;

    void buildParent(TreeNode* root) {
        if (!root) return;
        if (root->left)  parent[root->left] = root, buildParent(root->left);
        if (root->right) parent[root->right] = root, buildParent(root->right);
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        buildParent(root);

        unordered_set<TreeNode*> vis;
        queue<TreeNode*> q;
        q.push(target);
        vis.insert(target);

        int dist = 0;
        while (!q.empty() && dist++ < k) {
            int sz = q.size();
            while (sz--) {
                TreeNode* cur = q.front(); q.pop();
                for (TreeNode* next : {cur->left, cur->right, parent[cur]})
                    if (next && !vis.count(next)) vis.insert(next), q.push(next);
            }
        }

        vector<int> ans;
        while (!q.empty()) ans.push_back(q.front()->val), q.pop();
        return ans;
    }
};

// Helper to find target node by value
TreeNode* findTarget(TreeNode* root, int val) {
    if (!root) return nullptr;
    if (root->val == val) return root;
    TreeNode* left = findTarget(root->left, val);
    if (left) return left;
    return findTarget(root->right, val);
}

int main() {
    // Build sample tree
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    int targetVal = 5;
    int k = 2;

    TreeNode* target = findTarget(root, targetVal);

    Solution sol;
    vector<int> result = sol.distanceK(root, target, k);

    cout << "Nodes at distance " << k << " from " << targetVal << ": ";
    for (int x : result) cout << x << " ";
    cout << endl;

    return 0;
}
