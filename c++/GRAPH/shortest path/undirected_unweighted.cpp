#include <bits/stdc++.h>
using namespace std;
// dfs can't be to implement it
// Function to perform BFS and calculate shortest path from src
void bfsShortestPath(int src, vector<vector<int>> &adj, int n) {
    vector<int> dist(n, -1); // -1 means not visited yet
    queue<int> q;

    dist[src] = 0;
    q.push(src);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int i = 0; i < adj[node].size(); i++) {
            int neighbor = adj[node][i];
            if (dist[neighbor] == -1) {
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
            }
        }
    }

 
    for (int i = 0; i < n; i++) {
        cout << "Shortest path from " << src << " to " << i << " is " << dist[i] << "\n";
    }
}


int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<int>> adj(n);

    cout << "Enter " << m << " edges (0-based indexing):\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        // Undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int src;
    cout << "Enter source node: ";
    cin >> src;

    bfsShortestPath(src, adj, n);

    return 0;
}
