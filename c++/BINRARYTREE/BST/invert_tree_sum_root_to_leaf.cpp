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
    // -------- INVERT BINARY TREE (DFS) --------
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return NULL;

        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
     TreeNode* invertTree(TreeNode* root) {
        if (!root) return NULL;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            swap(node->left, node->right);

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        return root;
    }
    // -------- SUM ROOT TO LEAF (DFS) --------
    int dfsSum(TreeNode* root, int curr) {
        if (!root) return 0;

        curr = curr * 10 + root->val;

        if (!root->left && !root->right)
            return curr;

        return dfsSum(root->left, curr) + dfsSum(root->right, curr);
    }

    int sumNumbers(TreeNode* root) {
        return dfsSum(root, 0);
    }
};

// ---------- INORDER PRINT ----------
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// ---------- MAIN ----------
int main() {
    /*
            1
           / \
          2   3
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    Solution ob;

    cout << "Sum Root to Leaf: " << ob.sumNumbers(root) << endl;

    ob.invertTree(root);
    cout << "Inorder after Invert: ";
    inorder(root);

    return 0;
}
