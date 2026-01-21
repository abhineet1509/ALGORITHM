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
    // ===== DFS (RECURSION) =====
    int maxDepthDFS(Node* root) {
        if (!root) return 0;

        int depth = 0;
        for (auto child : root->children)
            depth = max(depth, maxDepthDFS(child));

        return depth + 1;
    }

    // ===== BFS (LEVEL ORDER) =====
    int maxDepthBFS(Node* root) {
        if (!root) return 0;

        queue<Node*> q;
        q.push(root);
        int depth = 0;

        while (!q.empty()) {
            int sz = q.size();
            depth++;

            while (sz--) {
                Node* curr = q.front(); q.pop();
                for (auto child : curr->children)
                    q.push(child);
            }
        }
        return depth;
    }
};

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

    cout << "Max Depth (DFS): " << ob.maxDepthDFS(root) << endl;
    cout << "Max Depth (BFS): " << ob.maxDepthBFS(root) << endl;

    return 0;
}
