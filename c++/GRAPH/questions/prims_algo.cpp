#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

vector<pair<int, int>> primMST(int V, vector<vector<pair<int, int>>> &adj) {
    vector<int> key(V, INT_MAX);
    vector<bool> inMST(V, false);
    vector<int> parent(V, -1);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    key[0] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u]) continue;
        inMST[u] = true;

        for (auto &[v, weight] : adj[u]) {
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }

    vector<pair<int, int>> mstEdges;
    for (int i = 1; i < V; i++) {
        if (parent[i] != -1) mstEdges.push_back({parent[i], i});
    }

    return mstEdges;
}

int main() {
    int V = 5;
    vector<vector<pair<int, int>>> adj(V);
    adj[0].push_back({1, 2});
    adj[0].push_back({3, 6});
    adj[1].push_back({0, 2});
    adj[1].push_back({2, 3});
    adj[1].push_back({3, 8});
    adj[1].push_back({4, 5});
    adj[2].push_back({1, 3});
    adj[2].push_back({4, 7});
    adj[3].push_back({0, 6});
    adj[3].push_back({1, 8});
    adj[4].push_back({1, 5});
    adj[4].push_back({2, 7});

    vector<pair<int, int>> mst = primMST(V, adj);

    cout << "Edges in the MST:" << endl;
    for (auto &[u, v] : mst) {
        cout << u << " - " << v << endl;
    }

    return 0;
}

