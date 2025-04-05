#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int covidSpreadTime(vector<vector<int>> &graph, int n, int source) {
    vector<int> time(n, -1); 
    queue<int> q;

    q.push(source);
    time[source] = 0; 

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : graph[node]) {
            if (time[neighbor] == -1) { 
                time[neighbor] = time[node] + 1;
                q.push(neighbor);
            }
        }
    }

    //  maximum time taken to infect all nodes
    int maxTime = 0;
    for (int t : time) {
        if (t == -1) { // If any node is not unreachable
            return -1; // it means not all nodes can be affected
        }
        maxTime = max(maxTime, t);
    }
    return maxTime;
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

    int source;
    cout << "Enter the source node: ";
    cin >> source;

    int result = covidSpreadTime(graph, n, source);
    if (result == -1) {
        cout << "Not all nodes can be infected.\n";
    } else {
        cout << "Time taken to infect all nodes: " << result << "\n";
    }

    return 0;
}
