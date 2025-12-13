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
    // ===== 1. DIAMETER OF BINARY TREE =====
    int dia = 0;

    int height(TreeNode* root) {
        if (!root) return 0;
        int l = height(root->left);
        int r = height(root->right);
        dia = max(dia, l + r);
        return 1 + max(l, r);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        dia = 0;
        height(root);
        return dia;
    }

    // ===== 2. LARGEST VALUE IN EACH ROW =====
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int sz = q.size();
            int mx = INT_MIN;

            while (sz--) {
                TreeNode* cur = q.front(); q.pop();
                mx = max(mx, cur->val);

                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            ans.push_back(mx);
        }
        return ans;
    }

    // ===== 3A. MIN ABS DIFF IN BST =====
    int prevVal = -1, minDiff = INT_MAX;

    void inorderBST(TreeNode* root) {
        if (!root) return;
        inorderBST(root->left);

        if (prevVal != -1)
            minDiff = min(minDiff, root->val - prevVal);
        prevVal = root->val;

        inorderBST(root->right);
    }

    int minDiffInBST(TreeNode* root) {
        prevVal = -1;
        minDiff = INT_MAX;
        inorderBST(root);
        return minDiff;
    }

    // ===== 3B. MIN ABS DIFF IN BINARY TREE =====
    void dfsBT(TreeNode* root, vector<int>& v) {
        if (!root) return;
        v.push_back(root->val);
        dfsBT(root->left, v);
        dfsBT(root->right, v);
    }

    int minDiffInBT(TreeNode* root) {
        vector<int> v;
        dfsBT(root, v);
        sort(v.begin(), v.end());

        int ans = INT_MAX;
        for (int i = 1; i < v.size(); i++)
            ans = min(ans, v[i] - v[i - 1]);

        return ans;
    }
};

// ---------- MAIN ----------
int main() {
    /*
            4
           / \
          2   6
         / \
        1   3
    */

    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution ob;

    cout << "Diameter: " << ob.diameterOfBinaryTree(root) << endl;

    cout << "Largest value in each row: ";
    auto rows = ob.largestValues(root);
    for (int x : rows) cout << x << " ";
    cout << endl;

    cout << "Min absolute diff in BST: " << ob.minDiffInBST(root) << endl;
    cout << "Min absolute diff in BT: " << ob.minDiffInBT(root) << endl;

    return 0;
}
