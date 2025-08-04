#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// DFS for vertical (hd = horizontal distance)
void vertical(TreeNode* root, int hd, map<int, vector<int>>& vert) {
    if (!root) return;
    vert[hd].push_back(root->val);
    vertical(root->left, hd - 1, vert);
    vertical(root->right, hd + 1, vert);
}

// DFS for diagonal (d = diagonal number)
void diagonal(TreeNode* root, int d, map<int, vector<int>>& diag) {
    if (!root) return;
    diag[d].push_back(root->val);
    diagonal(root->left, d + 1, diag);
    diagonal(root->right, d, diag);
}

void show(map<int, vector<int>>& m, string label) {
    cout << label << ":\n";
    for (auto& [k, vals] : m) {
        for (int v : vals) cout << v << " ";
        cout << "\n";
    }
    cout << "\n";
}

int main() {
    // Build tree:       1
    //                 /   \
    //                2     3
    //               / \     \
    //              4   5     6
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    map<int, vector<int>> vert, diag;
    vertical(root, 0, vert);
    diagonal(root, 0, diag);

    show(vert, "Vertical DFS");
    show(diag, "Diagonal DFS");

    return 0;
}
