#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isBipartite(vector<vector<int>> &graph, int n) {
    vector<int> color(n, -1); // where n is the number of vertices

    for (int i = 0; i < n; ++i) {   // disconnected components 
        if (color[i] == -1) { // Check unvisited nodes
            queue<int> q;
            q.push(i);
            color[i] = 0;

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int j : graph[node]) {
                    if (color[j] == -1) { // if unvisited and not coloured
                        color[j] = 1 - color[node];
                        q.push(j);
                    } else if (color[j] == color[node]) {
                        return false; // Same color on both sides 
                    }
                }
            }
        }
    }
    return true;
}

int main() {
    int n, e; // enter the number of vertices and edges
    cout << "Enter number of vertices and edges: ";             //             0
    cin >> n >> e;           // 5 5                             //           / \ \
                                                                //           1 2  3
    vector<vector<int>> graph(n);                                //          \    /
    cout << "Enter edges (u v):\n";                              //             4
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
