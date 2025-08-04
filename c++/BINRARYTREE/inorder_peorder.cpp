#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// ---------- Tree Node ----------
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// ---------- Version 1: Using Map ----------
TreeNode* buildFromPreIn_Map(vector<int>& preorder, vector<int>& inorder, int& preIndex, int inStart, int inEnd, unordered_map<int, int>& inMap) {
    if (inStart > inEnd) return nullptr;

    int rootVal = preorder[preIndex++];
    TreeNode* root = new TreeNode(rootVal);

    int inIndex = inMap[rootVal];

    root->left  = buildFromPreIn_Map(preorder, inorder, preIndex, inStart, inIndex - 1, inMap);
    root->right = buildFromPreIn_Map(preorder, inorder, preIndex, inIndex + 1, inEnd, inMap);

    return root;
}

TreeNode* buildTreeUsingMap(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> inMap;
    for (int i = 0; i < inorder.size(); i++)
        inMap[inorder[i]] = i;

    int preIndex = 0;
    return buildFromPreIn_Map(preorder, inorder, preIndex, 0, inorder.size() - 1, inMap);
}

// ---------- Version 2: Using Loop (No Map) ----------
int findIndex(vector<int>& inorder, int val, int inStart, int inEnd) {
    for (int i = inStart; i <= inEnd; i++)
        if (inorder[i] == val) return i;
    return -1;
}

TreeNode* buildFromPreIn_Loop(vector<int>& preorder, vector<int>& inorder, int& preIndex, int inStart, int inEnd) {
    if (inStart > inEnd) return nullptr;

    int rootVal = preorder[preIndex++];
    TreeNode* root = new TreeNode(rootVal);

    int inIndex = findIndex(inorder, rootVal, inStart, inEnd);

    root->left  = buildFromPreIn_Loop(preorder, inorder, preIndex, inStart, inIndex - 1);
    root->right = buildFromPreIn_Loop(preorder, inorder, preIndex, inIndex + 1, inEnd);

    return root;
}

TreeNode* buildTreeUsingLoop(vector<int>& preorder, vector<int>& inorder) {
    int preIndex = 0;
    return buildFromPreIn_Loop(preorder, inorder, preIndex, 0, inorder.size() - 1);
}

// ---------- Utility: Inorder Print ----------
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

// ---------- Main ----------
int main() {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder  = {9, 3, 15, 20, 7};

    cout << "Tree built using Map:\nInorder: ";
    TreeNode* rootMap = buildTreeUsingMap(preorder, inorder);
    printInorder(rootMap);
    cout << endl;

    cout << "Tree built using Loop:\nInorder: ";
    TreeNode* rootLoop = buildTreeUsingLoop(preorder, inorder);
    printInorder(rootLoop);
    cout << endl;

    return 0;
}
