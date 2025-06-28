#include <iostream>
#include <vector>
using namespace std;

// Recursive DFS function
void dfs(int node, vector<bool> &visited, vector<vector<int>> &adj) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, visited, adj);
        }
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int>> adj(V);

    cout << "Enter " << E << " edges (u v) (0-based indexing):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;

        // Undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(V, false);

    int start;
    cout << "Enter starting node for DFS: ";
    cin >> start;

    cout << "DFS traversal: ";
    dfs(start, visited, adj);

    return 0;
}
