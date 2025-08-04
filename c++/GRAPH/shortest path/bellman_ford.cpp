#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, wt;
};

void bellmanFord(int n, int m, int src, vector<Edge> &edges) {
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    // Relax all edges V-1 times
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int wt = edges[j].wt;

            if (dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // Check for negative weight cycle
    bool hasNegativeCycle = false;
    for (int j = 0; j < m; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int wt = edges[j].wt;

        if (dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
            hasNegativeCycle = true;
            break;
        }
    }

    if (hasNegativeCycle) {
        cout << "\nNegative weight cycle detected!\n";
    } else {
        cout << "\nShortest distances from source node " << src << ":\n";
        for (int i = 0; i < n; i++) {
            cout << "To node " << i << ": ";
            if (dist[i] == INT_MAX)
                cout << "Unreachable\n";
            else
                cout << dist[i] << "\n";
        }
    }
}

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<Edge> edges(m);
    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].wt;
    }

    int source;
    cout << "Enter source node: ";
    cin >> source;

    bellmanFord(n, m, source, edges);

    return 0;
}
