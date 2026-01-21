#include <queue>
#include<iostream>
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

            // Check if children  x and y are siblings
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

        if (foundX && foundY) return true;   
        if (foundX || foundY) return false; 
    }

    return false;
}
class Solution {
    int px = -1, py = -1, dx = -1, dy = -1;

    void dfs(TreeNode* root, int parent, int depth, int x, int y) {
        if (!root) return;

        if (root->val == x) {
            px = parent;
            dx = depth;
        }
        if (root->val == y) {
            py = parent;
            dy = depth;
        }

        dfs(root->left, root->val, depth + 1, x, y);
        dfs(root->right, root->val, depth + 1, x, y);
    }

public:
    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root, -1, 0, x, y);
        return dx == dy && px != py;
    }
};

int main() {
    /*
        Tree:
                1
              /   \
             2     3
              \
               4

        x = 4, y = 3
        Output: false
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);

    int x = 4, y = 3;

    cout << (isCousins(root, x, y) ? "true" : "false") << endl;

    return 0;
}