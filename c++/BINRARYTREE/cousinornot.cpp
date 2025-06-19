#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

bool isCousins(TreeNode* root, int x, int y) {
    if (!root) return false;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        bool foundX = false, foundY = false;

        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front(); q.pop();

            // Check if children are x and y siblings
            if (node->left && node->right) {
                if ((node->left->val == x && node->right->val == y) ||
                    (node->left->val == y && node->right->val == x)) {
                    return false; // siblings, not cousins
                }
            }

            if (node->val == x) foundX = true;
            if (node->val == y) foundY = true;

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        if (foundX && foundY) return true;   // found both at same level, not siblings
        if (foundX || foundY) return false;  // found only one node at this level
    }

    return false;
}
