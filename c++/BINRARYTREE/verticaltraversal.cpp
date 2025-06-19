#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> verticalTraversal(TreeNode* root) {
    map<int, vector<int>> m;  
    queue<pair<TreeNode*, int>> q;

    q.push({root, 0});

    while (!q.empty()) {
        auto front = q.front(); q.pop();
        TreeNode* node = front.first;
        int level = front.second;

        m[level].push_back(node->val);

        if (node->left)
            q.push({node->left, level - 1});
        if (node->right)
            q.push({node->right, level + 1});
    }

    vector<vector<int>> ans;
    for (auto it : m)
        ans.push_back(it.second);

    return ans;
}
vector<vector<int>> diagonalTraversal(TreeNode* root) {
    map<int, vector<int>> m;  // diagonal level → list of nodes
    queue<pair<TreeNode*, int>> q;

    q.push({root, 0});

    while (!q.empty()) {
        auto front = q.front(); q.pop();
        TreeNode* node = front.first;
        int level = front.second;

        m[level].push_back(node->val);

        if (node->left)
            q.push({node->left, level + 1});
        if (node->right)
            q.push({node->right, level});
    }

    vector<vector<int>> ans;
    for (auto it : m)
        ans.push_back(it.second);

    return ans;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<vector<int>> vertical = verticalTraversal(root);
    vector<vector<int>> diagonal = diagonalTraversal(root);

    cout << "Vertical Traversal:\n";
    for (auto level : vertical) {
        for (int val : level) cout << val << " ";
        cout << "\n";
    }

    cout << "\nDiagonal Traversal:\n";
    for (auto diag : diagonal) {
        for (int val : diag) cout << val << " ";
        cout << "\n";
    }
}
