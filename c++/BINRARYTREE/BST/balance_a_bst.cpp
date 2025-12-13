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
    vector<int> nodes;

    // Step 1: Inorder traversal to get sorted nodes
    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        nodes.push_back(root->val);
        inorder(root->right);
    }

    // Step 2: Build balanced BST from sorted array
    TreeNode* build(int l, int r) {
        if (l > r) return nullptr;
        int mid = l + (r - l) / 2;
        TreeNode* root = new TreeNode(nodes[mid]);
        root->left = build(l, mid - 1);
        root->right = build(mid + 1, r);
        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        nodes.clear();
        inorder(root);
        return build(0, nodes.size() - 1);
    }

    // Utility: Inorder print
    void printInorder(TreeNode* root) {
        if (!root) return;
        printInorder(root->left);
        cout << root->val << " ";
        printInorder(root->right);
    }
};

// ---------- MAIN ----------
int main() {
    /*
            1
             \
              2
               \
                3
                 \
                  4
    */

    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    root->right->right->right = new TreeNode(4);

    Solution ob;

    cout << "Inorder before balancing: ";
    ob.printInorder(root);
    cout << endl;

    root = ob.balanceBST(root);

    cout << "Inorder after balancing: ";
    ob.printInorder(root);
    cout << endl;

    return 0;
}
