#include <iostream>
#include <map>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

/// 🔵 Top View Using BFS
void topViewBFS(Node* root) {
    if (!root) return;

    map<int, int> topNodes;  // HD -> node data
    queue<pair<Node*, int>> q;
    q.push(make_pair(root, 0));

    while (!q.empty()) {
        Node* currNode = q.front().first;
        int hd = q.front().second;
        q.pop();

        if (topNodes.find(hd) == topNodes.end()) {
            topNodes[hd] = currNode->data;
        }

        if (currNode->left) q.push(make_pair(currNode->left, hd - 1));
        if (currNode->right) q.push(make_pair(currNode->right, hd + 1));
    }

    cout << "Top View (BFS): ";
    for (auto it = topNodes.begin(); it != topNodes.end(); ++it) {
        cout << it->second << " ";
    }
    cout << endl;
}

/// 🔴 Top View Using DFS
void dfs(Node* node, int hd, int level, map<int, pair<int, int>>& topNodes) {
    if (!node) return;

    // Store if HD not present OR current level is less (i.e., higher up)
    if (topNodes.find(hd) == topNodes.end() || level < topNodes[hd].second) {
        topNodes[hd] = make_pair(node->data, level);
    }

    dfs(node->left, hd - 1, level + 1, topNodes);
    dfs(node->right, hd + 1, level + 1, topNodes);
}

void topViewDFS(Node* root) {
    map<int, pair<int, int>> topNodes; // HD -> (node data, level)
    dfs(root, 0, 0, topNodes);

    cout << "Top View (DFS): ";
    for (auto it = topNodes.begin(); it != topNodes.end(); ++it) {
        cout << it->second.first << " ";
    }
    cout << endl;
}

/// 🧪 Main Function for Testing
int main() {
    /*
            1
          /   \
         2     3
          \   / \
           4 5   6
              \
               7
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->right = new Node(7);

    topViewBFS(root);  // Expected: 2 1 3 6
    topViewDFS(root);  // Expected: 2 1 3 6

    return 0;
}
