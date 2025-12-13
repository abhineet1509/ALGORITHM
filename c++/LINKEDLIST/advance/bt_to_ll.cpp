#include <bits/stdc++.h>
using namespace std;

// ---------- Tree Node ----------
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// ---------- Flatten using Morris ----------
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* cur = root;

        while (cur) {
            if (cur->left) {
                TreeNode* pre = cur->left;
                while (pre->right)
                    pre = pre->right;

                pre->right = cur->right;
                cur->right = cur->left;
                cur->left = NULL;
            }
            cur = cur->right;
        }
    }
};

// ---------- Print Linked List ----------
void printList(TreeNode* root) {
    while (root) {
        cout << root->val << " ";
        root = root->right;
    }
}

// ---------- Main ----------
int main() {
    /*
            1
           / \
          2   5
         / \   \
        3   4   6
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    Solution ob;
    ob.flatten(root);

    printList(root);   // Output: 1 2 3 4 5 6

    return 0;
}
