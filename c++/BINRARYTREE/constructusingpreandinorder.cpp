#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to find index of value in inorder array
int findIndex(vector<int>& inorder, int val) {
    for (int i = 0; i < inorder.size(); i++) {
        if (inorder[i] == val)
            return i;
    }
    return -1;
}

TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& preIndex, int inStart, int inEnd) {
    if (inStart > inEnd) return NULL;

    int rootVal = preorder[preIndex++]; // pick root from preorder
    TreeNode* root = new TreeNode(rootVal);

    int mid = findIndex(inorder, rootVal); // find root in inorder

    // Build left and right subtrees
    root->left = build(preorder, inorder, preIndex, inStart, mid - 1);
    root->right = build(preorder, inorder, preIndex, mid + 1, inEnd);

    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int preIndex = 0;
    return build(preorder, inorder, preIndex, 0, inorder.size() - 1);
}
