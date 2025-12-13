#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int v) : val(v), left(NULL), right(NULL) {}
};

int numTrees(int n) {
    vector<long long> dp(n + 1);
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++)
        for (int r = 1; r <= i; r++)
            dp[i] += dp[r - 1] * dp[i - r];  // left and right subtree
    return dp[n];
}

vector<TreeNode*> build(int l, int r) {
    if (l > r) return {NULL};
    vector<TreeNode*> ans;
    for (int i = l; i <= r; i++) {
        auto L = build(l, i - 1);
        auto R = build(i + 1, r);
        for (auto a : L)
            for (auto b : R) {
                TreeNode* root = new TreeNode(i);
                root->left = a;
                root->right = b;
                ans.push_back(root);
            }
    }
    return ans;
}

void preorder(TreeNode* root) {
    if (!root) { cout << "null "; return; }
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;
    cin >> n;

    cout << numTrees(n) << endl;

    auto trees = build(1, n);
    cout << trees.size() << endl;

    for (auto t : trees) {
        preorder(t);
        cout << endl;
    }
}
