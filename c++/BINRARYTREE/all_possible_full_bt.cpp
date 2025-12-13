#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    unordered_map<int, vector<TreeNode*>> dp;

    vector<TreeNode*> allPossibleFBT(int n) {
        if (n % 2 == 0) return {};     // No full binary tree possible
        if (n == 1) return { new TreeNode(0) };
        if (dp.count(n)) return dp[n];

        vector<TreeNode*> ans;

        for (int left = 1; left < n; left += 2) {
            int right = n - 1 - left;

            auto L = allPossibleFBT(left);
            auto R = allPossibleFBT(right);

            for (auto a : L) {
                for (auto b : R) {
                    TreeNode* root = new TreeNode(0);
                    root->left = a;
                    root->right = b;
                    ans.push_back(root);
                }
            }
        }
        return dp[n] = ans;
    }
};

// ----------- Printing Helper -----------------
void printTree(TreeNode* root) {
    if (!root) {
        cout << "null ";
        return;
    }
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

// ---------------- Main ------------------------
int main() {
    int n;
    cin >> n;

    Solution ob;
    vector<TreeNode*> trees = ob.allPossibleFBT(n);

    cout << "Total Trees: " << trees.size() << "\n";

    int id = 1;
    for (auto t : trees) {
        cout << "Tree " << id++ << ": ";
        printTree(t);
        cout << "\n";
    }

    return 0;
}
