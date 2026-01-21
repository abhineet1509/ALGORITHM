#include <bits/stdc++.h>
using namespace std;

bool dfs(int node,
         vector<vector<int>>& adj,
         vector<int>& visited,
         vector<int>& pathVis) {

    visited[node] = 1;
    pathVis[node] = 1;

    for (int nbr : adj[node]) {
        if (!visited[nbr]) {
            if (dfs(nbr, adj, visited, pathVis))
                return true;
        }
        else if (pathVis[nbr]) {
            return true; // cycle detected
        }
    }

    pathVis[node] = 0; // backtrack
    return false;
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    // Graph (adjacency list)
    vector<vector<int>> adj(V);

    cout << "Enter directed edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<int> visited(V, 0);
    vector<int> pathVis(V, 0);

    bool hasCycle = false;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, adj, visited, pathVis)) {
                hasCycle = true;
                break;
            }
        }
    }

    if (hasCycle)
        cout << "Cycle Detected\n";
    else
        cout << "No Cycle\n";

    return 0;
}
