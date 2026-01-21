#include <bits/stdc++.h>
using namespace std;

// ---------- N-ARY TREE NODE ----------
struct Node {
    int val;
    vector<Node*> children;
    Node(int x) : val(x) {}
};

// ---------- SOLUTION ----------
class Solution {
public:
    // ===== BFS LEVEL ORDER =====
    vector<vector<int>> levelOrderBFS(Node* root) {
        vector<vector<int>> ans;
        if (!root) return ans;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int sz = q.size();
            vector<int> level;

            while (sz--) {
                Node* curr = q.front(); q.pop();
                level.push_back(curr->val);

                for (auto child : curr->children)
                    q.push(child);
            }
            ans.push_back(level);
        }
        return ans;
    }

    // ===== DFS LEVEL ORDER =====
    void dfs(Node* root, int lvl, vector<vector<int>>& ans) {
        if (!root) return;

        if (ans.size() == lvl)
            ans.push_back({});

        ans[lvl].push_back(root->val);

        for (auto child : root->children)
            dfs(child, lvl + 1, ans);
    }

    vector<vector<int>> levelOrderDFS(Node* root) {
        vector<vector<int>> ans;
        dfs(root, 0, ans);
        return ans;
    }
};

// ---------- PRINT ----------
void print(vector<vector<int>>& v) {
    for (auto &lvl : v) {
        for (int x : lvl) cout << x << " ";
        cout << endl;
    }
}

// ---------- MAIN ----------
int main() {
    /*
            1
          / | \
         2  3  4
            |
            5
    */

    Node* root = new Node(1);
    root->children.push_back(new Node(2));
    root->children.push_back(new Node(3));
    root->children.push_back(new Node(4));
    root->children[1]->children.push_back(new Node(5));

    Solution ob;

    cout << "BFS Level Order:\n";
    auto bfs = ob.levelOrderBFS(root);
    print(bfs);

    cout << "\nDFS Level Order:\n";
    auto dfs = ob.levelOrderDFS(root);
    print(dfs);

    return 0;
}
