#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* build(vector<int>& nums, int l, int r) {
        if (l > r) return NULL;

        int mid = (l + r) / 2;
        TreeNode* root = new TreeNode(nums[mid]);

        root->left  = build(nums, l, mid - 1);
        root->right = build(nums, mid + 1, r);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums, 0, nums.size() - 1);
    }
};

// --------- Testing ----------
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    Solution ob;
    TreeNode* root = ob.sortedArrayToBST(nums);

    inorder(root);  // should print sorted order
    return 0;
}
