#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return buildTrees(1, n);
    }

private:
    vector<TreeNode*> buildTrees(int start, int end) {
        vector<TreeNode*> allTrees;

        if (start > end) {
            allTrees.push_back(nullptr);
            return allTrees;
        }

        for (int i = start; i <= end; ++i) {
            // All combinations of left subtrees
            vector<TreeNode*> leftTrees = buildTrees(start, i - 1);
            // All combinations of right subtrees
            vector<TreeNode*> rightTrees = buildTrees(i + 1, end);

            // Combine them with root i
            for (TreeNode* left : leftTrees) {
                for (TreeNode* right : rightTrees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    allTrees.push_back(root);
                }
            }
        }

        return allTrees;
    }
};

// Optional: Function to print the BSTs in pre-order format
void printTree(TreeNode* root) {
    if (!root) {
        cout << "null ";
        return;
    }
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

int main() {
    Solution solution;
    int n = 3;

    vector<TreeNode*> allUniqueBSTs = solution.generateTrees(n);

    cout << "Total unique BSTs: " << allUniqueBSTs.size() << endl;

    for (int i = 0; i < allUniqueBSTs.size(); ++i) {
        cout << "Tree " << i + 1 << ": ";
        printTree(allUniqueBSTs[i]);
        cout << endl;
    }

    return 0;
}
