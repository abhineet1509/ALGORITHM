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
    // ===== MODE IN BST (INORDER) =====
    int prevVal;
    int currCnt;
    int maxCnt;
    vector<int> bstModes;

    void inorderBST(TreeNode* root) {
        if (!root) return;

        inorderBST(root->left);

        if (root->val == prevVal)
            currCnt++;
        else {
            currCnt = 1;
            prevVal = root->val;
        }

        if (currCnt > maxCnt) {
            maxCnt = currCnt;
            bstModes.clear();
            bstModes.push_back(root->val);
        } else if (currCnt == maxCnt) {
            bstModes.push_back(root->val);
        }

        inorderBST(root->right);
    }

    vector<int> findModeBST(TreeNode* root) {
        prevVal = INT_MIN;
        currCnt = maxCnt = 0;
        bstModes.clear();
        inorderBST(root);
        return bstModes;
    }

    // ===== MODE IN BINARY TREE (MAP) =====
    unordered_map<int,int> freq;

    void dfsBT(TreeNode* root) {
        if (!root) return;
        freq[root->val]++;
        dfsBT(root->left);
        dfsBT(root->right);
    }

    vector<int> findModeBT(TreeNode* root) {
        freq.clear();
        dfsBT(root);

        int mx = 0;
        for (auto &p : freq)
            mx = max(mx, p.second);

        vector<int> ans;
        for (auto &p : freq)
            if (p.second == mx)
                ans.push_back(p.first);

        return ans;
    }
};

// ---------- PRINT ----------
void print(vector<int>& v) {
    for (int x : v) cout << x << " ";
    cout << endl;
}

// ---------- MAIN ----------
int main() {
    /*
            2
           / \
          1   2
    */

    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);

    Solution ob;

    cout << "Mode(s) in BST: ";
    auto bst = ob.findModeBST(root);
    print(bst);

    cout << "Mode(s) in Binary Tree: ";
    auto bt = ob.findModeBT(root);
    print(bt);

    return 0;
}
