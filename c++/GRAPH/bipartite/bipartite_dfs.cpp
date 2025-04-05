#include <iostream>
#include <vector>
using namespace std;

bool dfs(int node, vector<vector<int>> &graph, vector<int> &color, int currentColor) {
    color[node] = currentColor;

    for (int j : graph[node]) {
        if (color[j] == -1) { // If uncolored, color it with opposite color
            if (!dfs(j, graph, color, 1 - currentColor)) {
                return false;
            }
        } else if (color[j] == currentColor) { // Same color on both sides of an edge
            return false;
        }
    }
    return true;
}

bool isBipartite(vector<vector<int>> &graph, int n) {
    vector<int> color(n, -1); 

    for (int i = 0; i < n; ++i) {
        if (color[i] == -1) { // Check unvisited nodes
            if (!dfs(i, graph, color, 0)) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int n, e; 
    cout << "Enter number of vertices and edges: ";
    cin >> n >> e;

    vector<vector<int>> graph(n);
    cout << "Enter edges (u v):\n";
    for (int i = 0; i < e; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    if (isBipartite(graph, n)) {
        cout << "The graph is bipartite.\n";
    } else {
        cout << "The graph is not bipartite.\n";
    }

    return 0;
}
