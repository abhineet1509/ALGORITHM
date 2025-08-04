#include <iostream>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Map to store number of children for each node
unordered_map<TreeNode*, int> childCount;

int countChildren(TreeNode* root) {
    if (!root) return 0;

    int left = countChildren(root->left);
    int right = countChildren(root->right);

    // Total children = left + right + (left + right subtree)
    int total = left + right;
    if (root->left) total++;
    if (root->right) total++;

    childCount[root] = total;
    return total;
}
int main() {
    /*
         1
        / \
       2   3
          /
         4
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);

    countChildren(root);

    for (auto it : childCount) {
        cout << "Node " << it.first->val << " has " << it.second << " children." << endl;
    }

    return 0;
}