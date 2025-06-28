#include <iostream>
#include <vector>
using namespace std;
  // parent detection mechanism
bool dfs(int node, int parent, vector<vector<int>> &adj, vector<bool> &visited) {
    visited[node] = true;
    
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (dfs(neighbor, node, adj, visited)) return true;
        } else if (neighbor != parent) {
            // Back edge found
            return true;
        }
    }
    return false;
}

bool hasCycle(int V, vector<vector<int>> &adj) {
    vector<bool> visited(V, false); // dont visit the same node again through different paths
    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            if (dfs(i, -1, adj, visited)) return true;
        }
    }
    return false;
}

int main() {
    int V = 5;
    vector<vector<int>> adj(V);
    
    // Sample undirected graph with a cycle
    adj[0] = {1};
    adj[1] = {0, 2, 3};
    adj[2] = {1, 3};
    adj[3] = {1, 2};
    adj[4] = {}; // Disconnected node

    if (hasCycle(V, adj))
        cout << "Cycle detected (DFS)\n";
    else
        cout << "No cycle (DFS)\n";
    return 0;
}
