#include <bits/stdc++.h>
using namespace std;

// ---------- Tree Node ----------
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// ---------- Solution ----------
class Solution {
public:
    // -------- MORRIS INORDER --------
    void morrisInorder(TreeNode* root) {
        TreeNode* curr = root;
        while (curr) {
            if (!curr->left) {
                cout << curr->val << " ";
                curr = curr->right;
            } else {
                TreeNode* pre = curr->left;
                while (pre->right && pre->right != curr)
                    pre = pre->right;

                if (!pre->right) {
                    pre->right = curr;
                    curr = curr->left;
                } else {
                    pre->right = NULL;
                    cout << curr->val << " ";
                    curr = curr->right;
                }
            }
        }
        cout << endl;
    }

    // -------- MORRIS PREORDER --------
    void morrisPreorder(TreeNode* root) {
        TreeNode* curr = root;
        while (curr) {
            if (!curr->left) {
                cout << curr->val << " ";
                curr = curr->right;
            } else {
                TreeNode* pre = curr->left;
                while (pre->right && pre->right != curr)
                    pre = pre->right;

                if (!pre->right) {
                    cout << curr->val << " ";
                    pre->right = curr;
                    curr = curr->left;
                } else {
                    pre->right = NULL;
                    curr = curr->right;
                }
            }
        }
        cout << endl;
    }

    // -------- FLATTEN TREE USING MORRIS --------
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while (curr) {
            if (curr->left) {
                TreeNode* pre = curr->left;
                while (pre->right)
                    pre = pre->right;

                pre->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }

    // Print flattened linked list
    void printList(TreeNode* root) {
        while (root) {
            cout << root->val << " ";
            root = root->right;
        }
        cout << endl;
    }
};

// ---------- MAIN ----------
int main() {
    /*
            1
           / \
          2   3
         / \   \
        4   5   6
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    Solution ob;

    cout << "Morris Inorder: ";
    ob.morrisInorder(root);

    cout << "Morris Preorder: ";
    ob.morrisPreorder(root);

    cout << "Flattening Tree using Morris..." << endl;
    ob.flatten(root);
    cout << "Flattened Linked List: ";
    ob.printList(root);

    return 0;
}
