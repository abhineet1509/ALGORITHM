#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

void dijkstra(int src, vector<vector<pii>> &adj, int n) {
    vector<int> dist(n, INT_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[src] = 0;
    pq.push(make_pair(0, src)); // {distance, node}

    while (!pq.empty()) {
        pii top = pq.top(); pq.pop();
        int d = top.first;
        int u = top.second;

        if (d > dist[u]) continue;

        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].first;
            int wt = adj[u][i].second;

            if (dist[v] > dist[u] + wt) {
                dist[v] = dist[u] + wt;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    // Output distances
    for (int i = 0; i < n; i++) {
        cout << "Shortest path from " << src << " to " << i << " is " << dist[i] << "\n";
    }
}

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<pii>> adj(n);

    cout << "Enter " << m << " edges (from to weight):\n";
    for (int i = 0; i < m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back(make_pair(v, wt)); // Directed edge
        // For undirected graph: also add adj[v].push_back({u, wt});
    }

    int src;
    cout << "Enter source node: ";
    cin >> src;

    dijkstra(src, adj, n);

    return 0;
}
