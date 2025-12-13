#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestCycle(int V, vector<vector<int>> &edges) {
        // Build adjacency list
        vector<vector<int>> adj(V);
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int ans = INT_MAX;

        // Run BFS from each node
        for (int start = 0; start < V; start++) {
            vector<int> dist(V, -1);
            vector<int> parent(V, -1);

            queue<int> q;
            q.push(start);
            dist[start] = 0;

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : adj[u]) {
                    if (dist[v] == -1) {
                        // Not visited
                        dist[v] = dist[u] + 1;
                        parent[v] = u;
                        q.push(v);
                    }
                    else if (parent[u] != v) {
                        // Found a cycle
                        ans = min(ans, dist[u] + dist[v] + 1);
                    }
                }
            }
        }

        return (ans == INT_MAX ? -1 : ans);
    }
};


int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> edges(E, vector<int>(2));
    for (int i = 0; i < E; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    Solution ob;
    cout << ob.shortestCycle(V, edges);
}
