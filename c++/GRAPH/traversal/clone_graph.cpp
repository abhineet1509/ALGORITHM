#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>
using namespace std;

// --------- Node Definition ---------
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

// --------- DFS Cloner ---------
class DFS_Solution {
    unordered_map<Node*, Node*> mp;

public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        if (mp.find(node) != mp.end())
            return mp[node];

        Node* clone = new Node(node->val);
        mp[node] = clone;

        for (Node* neighbor : node->neighbors) {
            clone->neighbors.push_back(cloneGraph(neighbor));
        }

        return clone;
    }
};

// --------- BFS Cloner ---------
class BFS_Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        unordered_map<Node*, Node*> mp;
        queue<Node*> q;
        q.push(node);
        mp[node] = new Node(node->val);

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            for (Node* neighbor : curr->neighbors) {
                if (mp.find(neighbor) == mp.end()) {
                    mp[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                mp[curr]->neighbors.push_back(mp[neighbor]);
            }
        }

        return mp[node];
    }
};

// --------- Print Graph (BFS Traversal) ---------
void printGraph(Node* node) {
    if (!node) return;
    set<int> visited;
    queue<Node*> q;
    q.push(node);
    visited.insert(node->val);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        cout << "Node " << curr->val << " has neighbors: ";
        for (Node* n : curr->neighbors) {
            cout << n->val << " ";
            if (visited.find(n->val) == visited.end()) {
                visited.insert(n->val);
                q.push(n);
            }
        }
        cout << endl;
    }
}

// --------- Main Function ---------
int main() {
    int n, e;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;

    // Create node references
    vector<Node*> nodes(n + 1); // 1-based indexing
    for (int i = 1; i <= n; ++i) {
        nodes[i] = new Node(i);
    }

    // Read edges
    cout << "Enter " << e << " edges (u v means edge from u to v and v to u):\n";
    for (int i = 0; i < e; ++i) {
        int u, v;
        cin >> u >> v;
        nodes[u]->neighbors.push_back(nodes[v]);
        nodes[v]->neighbors.push_back(nodes[u]);
    }

    Node* original = nodes[1];

    cout << "\nOriginal Graph:\n";
    printGraph(original);

    // Clone with DFS
    DFS_Solution dfs_solver;
    Node* cloned_dfs = dfs_solver.cloneGraph(original);
    cout << "\nDFS Cloned Graph:\n";
    printGraph(cloned_dfs);

    // Clone with BFS
    BFS_Solution bfs_solver;
    Node* cloned_bfs = bfs_solver.cloneGraph(original);
    cout << "\nBFS Cloned Graph:\n";
    printGraph(cloned_bfs);

    return 0;
}
