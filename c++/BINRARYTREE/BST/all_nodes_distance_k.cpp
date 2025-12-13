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
    unordered_map<TreeNode*, TreeNode*> parent;

    // DFS to map each node to its parent
    void mapParents(TreeNode* root, TreeNode* par) {
        if (!root) return;
        parent[root] = par;
        mapParents(root->left, root);
        mapParents(root->right, root);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        mapParents(root, nullptr);

        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;
        q.push(target);
        visited.insert(target);
        int dist = 0;

        while (!q.empty()) {
            int sz = q.size();
            if (dist == k) break;
            dist++;

            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front(); q.pop();

                if (node->left && visited.find(node->left) == visited.end()) {
                    q.push(node->left);
                    visited.insert(node->left);
                }
                if (node->right && visited.find(node->right) == visited.end()) {
                    q.push(node->right);
                    visited.insert(node->right);
                }
                TreeNode* parNode = parent[node];
                if (parNode && visited.find(parNode) == visited.end()) {
                    q.push(parNode);
                    visited.insert(parNode);
                }
            }
        }

        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};

// ---------- MAIN ----------
int main() {
    /*
            3
           / \
          5   1
         / \ / \
        6  2 0  8
          / \
         7   4
    */

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    Solution ob;
    TreeNode* target = root->left; // node 5
    int k = 2;

    vector<int> ans = ob.distanceK(root, target, k);

    cout << "Nodes at distance " << k << " from " << target->val << ": ";
    for (int x : ans) cout << x << " ";
    cout << endl;

    return 0;
}
