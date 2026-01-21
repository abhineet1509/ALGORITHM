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
    // -------- ITERATIVE PREORDER --------
    vector<int> preorder(TreeNode* root) {
        vector<int> res;
        if (!root) return res;

        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            TreeNode* node = st.top(); st.pop();
            res.push_back(node->val);
                                   // Root → Left → Right
            if (node->right) st.push(node->right);
            if (node->left) st.push(node->left);
        }
        return res;
    }

    // -------- ITERATIVE INORDER --------
    vector<int> inorder(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* cur = root;

        while (cur || !st.empty()) {
            while (cur) {
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top(); st.pop();
            res.push_back(cur->val);
            cur = cur->right;
        }
        return res;
    }

    // -------- ITERATIVE POSTORDER --------
    vector<int> postorder(TreeNode* root) {
        vector<int> res;
        if (!root) return res;

        stack<TreeNode*> st1, st2;
        st1.push(root);

        while (!st1.empty()) {
            TreeNode* node = st1.top(); st1.pop();
            st2.push(node);
            // Root → Right → Left
            if (node->left) st1.push(node->left);
            if (node->right) st1.push(node->right);
        }

        while (!st2.empty()) {
            res.push_back(st2.top()->val);
            st2.pop();
        }
        return res;
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

    auto pre = ob.preorder(root);
    auto in = ob.inorder(root);
    auto post = ob.postorder(root);

    cout << "Preorder: "; for (int x : pre) cout << x << " ";
    cout << "\nInorder: "; for (int x : in) cout << x << " ";
    cout << "\nPostorder: "; for (int x : post) cout << x << " ";

    return 0;
}
