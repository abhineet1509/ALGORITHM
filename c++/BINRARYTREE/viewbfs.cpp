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
    // -------- LEFT VIEW --------
    vector<int> leftView(TreeNode* root) {
        vector<int> res;
        if (!root) return res;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                TreeNode* cur = q.front(); q.pop();
                if (i == 0) res.push_back(cur->val);
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
        }
        return res;
    }

    // -------- RIGHT VIEW --------
    vector<int> rightView(TreeNode* root) {
        vector<int> res;
        if (!root) return res;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                TreeNode* cur = q.front(); q.pop();
                if (i == sz - 1) res.push_back(cur->val);
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
        }
        return res;
    }

    // -------- TOP VIEW --------
    vector<int> topView(TreeNode* root) {
        vector<int> res;
        if (!root) return res;

        map<int, int> mp;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            auto [node, hd] = q.front(); q.pop();

            if (!mp.count(hd))
                mp[hd] = node->val;

            if (node->left) q.push({node->left, hd - 1});
            if (node->right) q.push({node->right, hd + 1});
        }

        for (auto &x : mp) res.push_back(x.second);
        return res;
    }

    // -------- BOTTOM VIEW --------
    vector<int> bottomView(TreeNode* root) {
        vector<int> res;
        if (!root) return res;

        map<int, int> mp;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            auto [node, hd] = q.front(); q.pop();
            mp[hd] = node->val;

            if (node->left) q.push({node->left, hd - 1});
            if (node->right) q.push({node->right, hd + 1});
        }

        for (auto &x : mp) res.push_back(x.second);
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
             \
              7
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->left->right->right = new TreeNode(7);

    Solution ob;

    auto lv = ob.leftView(root);
    auto rv = ob.rightView(root);
    auto tv = ob.topView(root);
    auto bv = ob.bottomView(root);

    cout << "Left View: ";
    for (int x : lv) cout << x << " ";

    cout << "\nRight View: ";
    for (int x : rv) cout << x << " ";

    cout << "\nTop View: ";
    for (int x : tv) cout << x << " ";

    cout << "\nBottom View: ";
    for (int x : bv) cout << x << " ";

    return 0;
}
