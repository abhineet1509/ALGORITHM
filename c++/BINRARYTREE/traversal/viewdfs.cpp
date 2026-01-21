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
    // -------- LEFT VIEW (DFS) --------
    void leftDFS(TreeNode* root, int level, vector<int>& res) {
        if (!root) return;
        if (level == res.size()) res.push_back(root->val);
        leftDFS(root->left, level + 1, res);
        leftDFS(root->right, level + 1, res);
    }

    vector<int> leftView(TreeNode* root) {
        vector<int> res;
        leftDFS(root, 0, res);
        return res;
    }

    // -------- RIGHT VIEW (DFS) --------
    void rightDFS(TreeNode* root, int level, vector<int>& res) {
        if (!root) return;
        if (level == res.size()) res.push_back(root->val);
        rightDFS(root->right, level + 1, res);
        rightDFS(root->left, level + 1, res);
    }

    vector<int> rightView(TreeNode* root) {
        vector<int> res;
        rightDFS(root, 0, res);
        return res;
    }

    // -------- TOP VIEW (DFS) --------
    void topDFS(TreeNode* root, int hd, int level, map<int, pair<int,int>>& mp) {
        if (!root) return;
        if (!mp.count(hd) || level < mp[hd].second)
            mp[hd] = {root->val, level};

        topDFS(root->left, hd - 1, level + 1, mp);
        topDFS(root->right, hd + 1, level + 1, mp);
    }

    vector<int> topView(TreeNode* root) {
        map<int, pair<int,int>> mp;
        topDFS(root, 0, 0, mp);

        vector<int> res;
        for (auto &x : mp) res.push_back(x.second.first);
        return res;
    }

    // -------- BOTTOM VIEW (DFS) --------
    void bottomDFS(TreeNode* root, int hd, int level, map<int, pair<int,int>>& mp) {
        if (!root) return;
        if (!mp.count(hd) || level >= mp[hd].second)
            mp[hd] = {root->val, level};

        bottomDFS(root->left, hd - 1, level + 1, mp);
        bottomDFS(root->right, hd + 1, level + 1, mp);
    }

    vector<int> bottomView(TreeNode* root) {
        map<int, pair<int,int>> mp;
        bottomDFS(root, 0, 0, mp);

        vector<int> res;
        for (auto &x : mp) res.push_back(x.second.first);
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
