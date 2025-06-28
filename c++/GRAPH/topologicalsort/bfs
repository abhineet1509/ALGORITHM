#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> topoSortKahn(int V, vector<vector<int>> &adj) {
    vector<int> in_degree(V, 0);
    for (int u = 0; u < V; u++) {
        for (int v : adj[u]) {
            in_degree[v]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (in_degree[i] == 0) q.push(i);
    }

    vector<int> topo;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for (int neighbor : adj[node]) {
            in_degree[neighbor]--;
            if (in_degree[neighbor] == 0)
                q.push(neighbor);
        }
    }

    // Check for cycle
    if (topo.size() != V) {
        cout << "Cycle detected, topological sort not possible.\n";
        return {};
    }

    return topo;
}

int main() {
    int V = 6;
    vector<vector<int>> adj(V);
    
    // Graph: 5 → 0, 5 → 2, 4 → 0, 4 → 1, 2 → 3, 3 → 1
    adj[5] = {0, 2};
    adj[4] = {0, 1};
    adj[2] = {3};
    adj[3] = {1};

    vector<int> result = topoSortKahn(V, adj);

    if (!result.empty()) {
        cout << "Topological Sort (Kahn's Algorithm): ";
        for (int x : result) cout << x << " ";
        cout << endl;
    }

    return 0;
}
