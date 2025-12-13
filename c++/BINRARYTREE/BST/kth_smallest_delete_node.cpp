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
    // ===== KTH SMALLEST ELEMENT =====
    int cnt = 0, ans = -1;

    void inorder(TreeNode* root, int k) {
        if (!root || cnt >= k) return;

        inorder(root->left, k);

        cnt++;
        if (cnt == k) {
            ans = root->val;
            return;
        }

        inorder(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        cnt = 0;
        ans = -1;
        inorder(root, k);
        return ans;
    }

    // ===== DELETE NODE IN BST =====
    TreeNode* findMin(TreeNode* root) {
        while (root->left)
            root = root->left;
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return NULL;

        if (key < root->val)
            root->left = deleteNode(root->left, key);
        else if (key > root->val)
            root->right = deleteNode(root->right, key);
        else {
            if (!root->left) return root->right;
            if (!root->right) return root->left;

            TreeNode* succ = findMin(root->right);
            root->val = succ->val;
            root->right = deleteNode(root->right, succ->val);
        }
        return root;
    }
};

// ---------- INORDER PRINT ----------
void inorderPrint(TreeNode* root) {
    if (!root) return;
    inorderPrint(root->left);
    cout << root->val << " ";
    inorderPrint(root->right);
}

// ---------- MAIN ----------
int main() {
    /*
            5
           / \
          3   6
         / \
        2   4
    */

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    Solution ob;

    cout << "Kth Smallest (k=3): " << ob.kthSmallest(root, 3) << endl;

    root = ob.deleteNode(root, 3);
    cout << "Inorder after Deletion: ";
    inorderPrint(root);

    return 0;
}
