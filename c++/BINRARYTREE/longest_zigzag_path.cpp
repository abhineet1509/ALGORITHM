#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int ans = 0;

    void dfs(TreeNode* node, bool goLeft, int length) {
        if (!node) return;

        ans = max(ans, length);

        if (goLeft) {
            dfs(node->left, false, length + 1);
            dfs(node->right, true, 1);
        } else {
            dfs(node->right, true, length + 1);
            dfs(node->left, false, 1);
        }
    }

    int longestZigZag(TreeNode* root) {
        if (!root) return 0;
        dfs(root->left, false, 1);
        dfs(root->right, true, 1);
        return ans;
    }
};


int main() {
    int n;
    cin >> n;

    if (n == 0) {
        cout << 0;
        return 0;
    }

    int rootVal;
    cin >> rootVal;

    // store created nodes
    unordered_map<int, TreeNode*> mp;
    TreeNode* root = new TreeNode(rootVal);
    mp[rootVal] = root;

    for (int i = 0; i < n - 1; i++) {
        int parent, child;
        char dir;
        cin >> parent >> child >> dir;

        if (!mp[parent]) mp[parent] = new TreeNode(parent);
        if (!mp[child])  mp[child]  = new TreeNode(child);

        if (dir == 'L') mp[parent]->left  = mp[child];
        else            mp[parent]->right = mp[child];
    }

    Solution s;
    cout << s.longestZigZag(root) << endl;

    return 0;
}
