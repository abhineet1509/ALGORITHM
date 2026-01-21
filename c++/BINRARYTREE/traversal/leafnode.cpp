#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left, *right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

void countNodes(TreeNode* root, int &leaf, int &nonLeaf) {
    if (!root) return;

    if (!root->left && !root->right)
        leaf++;
    else
        nonLeaf++;

    countNodes(root->left, leaf, nonLeaf);
    countNodes(root->right, leaf, nonLeaf);
}

int main() {
    /*
            1
           / \
          2   3
         / \
        4   5
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    int leaf = 0, nonLeaf = 0;
    countNodes(root, leaf, nonLeaf);

    cout << "Leaf nodes: " << leaf << "\n";
    cout << "Non-leaf nodes: " << nonLeaf << "\n";

    return 0;
}
