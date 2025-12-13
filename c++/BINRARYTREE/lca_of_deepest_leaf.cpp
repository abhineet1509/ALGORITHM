#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Solution class
class Solution {
public:
    void findDeepest(TreeNode* node, int depth, int& maxDepth, vector<TreeNode*>& deepest) {
        if (!node) return;
        if (depth > maxDepth) {
            maxDepth = depth;
            deepest.clear();
        }
        if (depth == maxDepth) {
            deepest.push_back(node);
        }
        findDeepest(node->left, depth + 1, maxDepth, deepest);
        findDeepest(node->right, depth + 1, maxDepth, deepest);
    }

    TreeNode* findLCA(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q)
            return root;
        TreeNode* left = findLCA(root->left, p, q);
        TreeNode* right = findLCA(root->right, p, q);
        if (left && right) return root;
        return left ? left : right;
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int maxDepth = -1;
        vector<TreeNode*> deepest;
        findDeepest(root, 0, maxDepth, deepest);
        TreeNode* lcaNode = deepest[0];
        for (int i = 1; i < deepest.size(); ++i) {
            lcaNode = findLCA(root, lcaNode, deepest[i]);
        }
        return lcaNode;
    }
};


int main() {
    // Building a sample tree:
    //       1
    //      / \
    //     2   3
    //    /
    //   4
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->right = new TreeNode(3);

    Solution sol;
    TreeNode* lca = sol.lcaDeepestLeaves(root);
    cout << "LCA of deepest leaves: " << (lca ? lca->val : -1) << endl;

    return 0;
}
