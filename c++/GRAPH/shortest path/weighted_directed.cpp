#include <bits/stdc++.h>
using namespace std;

void topoDFS(int node,
             vector<vector<pair<int,int>>>& adj,
             vector<int>& vis,
             stack<int>& st) {

    vis[node] = 1;
    for (auto it : adj[node]) {
        int v = it.first;
        if (!vis[v])
            topoDFS(v, adj, vis, st);
    }
    st.push(node);
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<pair<int,int>>> adj(V);

    cout << "Enter edges (u v wt):\n";
    for (int i = 0; i < E; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
    }

    // Topological Sort
    vector<int> vis(V, 0);
    stack<int> st;
    for (int i = 0; i < V; i++) {
        if (!vis[i])
            topoDFS(i, adj, vis, st);
    }

    int src;
    cout << "Enter source vertex: ";
    cin >> src;

    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    // Relax edges in topo order
    while (!st.empty()) {
        int node = st.top();
        st.pop();

        if (dist[node] != INT_MAX) {
            for (auto it : adj[node]) {
                int v = it.first;
                int wt = it.second;
                dist[v] = min(dist[v], dist[node] + wt);
            }
        }
    }

    cout << "Shortest distances from source:\n";
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX)
            cout << "INF ";
        else
            cout << dist[i] << " ";
    }

    return 0;
}
