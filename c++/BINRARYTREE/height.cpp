#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Deepest Height: max depth from root to any leaf
int maxDepth(TreeNode* root) {
    if (!root) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

// Shortest Height: min depth from root to any leaf
int minDepth(TreeNode* root) {
    if (!root) return 0;
    // If one of the subtrees is NULL, we take the other path
    if (!root->left) return 1 + minDepth(root->right);
    if (!root->right) return 1 + minDepth(root->left);
    return 1 + min(minDepth(root->left), minDepth(root->right));
}

int main() {
    /*
        Example Tree:
             1
            / \
           2   3
              /
             4
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);

    cout << "Deepest Height (Max Depth): " << maxDepth(root) << endl;
    cout << "Shortest Height (Min Depth): " << minDepth(root) << endl;

    return 0;
}
