#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // -------- LEVEL ORDER I --------
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int sz = q.size();
            vector<int> level;

            for (int i = 0; i < sz; i++) {
                TreeNode* cur = q.front(); q.pop();
                level.push_back(cur->val);

                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            res.push_back(level);
        }
        return res;
    }

    // -------- LEVEL ORDER II (BOTTOM UP) --------
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res = levelOrder(root);
        reverse(res.begin(), res.end());
        return res;
    }

    // -------- ZIGZAG LEVEL ORDER --------
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;

        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;

        while (!q.empty()) {
            int sz = q.size();
            vector<int> level(sz);

            for (int i = 0; i < sz; i++) {
                TreeNode* cur = q.front(); q.pop();

                int idx = leftToRight ? i : sz - 1 - i;
                level[idx] = cur->val;

                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            leftToRight = !leftToRight;
            res.push_back(level);
        }
        return res;
    }
};

// ---------------- MAIN ----------------
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

    auto a = ob.levelOrder(root);
    auto b = ob.levelOrderBottom(root);
    auto c = ob.zigzagLevelOrder(root);

    cout << "Level Order:\n";
    for (auto &v : a) for (int x : v) cout << x << " ";
    cout << "\n\nBottom Up:\n";
    for (auto &v : b) for (int x : v) cout << x << " ";
    cout << "\n\nZigzag:\n";
    for (auto &v : c) for (int x : v) cout << x << " ";

    return 0;
}
