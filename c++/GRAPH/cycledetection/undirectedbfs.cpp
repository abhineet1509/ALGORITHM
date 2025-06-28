#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool bfs(int start, vector<vector<int>> &adj, vector<bool> &visited) {
    queue<pair<int, int>> q;  // {node, parent}
    visited[start] = true;
    q.push({start, -1});

    while (!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push({neighbor, node});
            } else if (neighbor != parent) {
                // Cycle found
                return true;
            }
        }
    }

    return false;
}

bool hasCycleBFS(int V, vector<vector<int>> &adj) {
    vector<bool> visited(V, false);
    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            if (bfs(i, adj, visited)) return true;
        }
    }
    return false;
}

int main() {
    int V = 5;
    vector<vector<int>> adj(V);

    // Same graph
    adj[0] = {1};
    adj[1] = {0, 2, 3};
    adj[2] = {1, 3};
    adj[3] = {1, 2};
    adj[4] = {};

    if (hasCycleBFS(V, adj))
        cout << "Cycle detected (BFS)\n";
    else
        cout << "No cycle (BFS)\n";
    return 0;
}
