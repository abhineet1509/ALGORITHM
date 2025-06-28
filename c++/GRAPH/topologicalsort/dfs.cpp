#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &st) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor])
            dfs(neighbor, adj, visited, st);
    }
    st.push(node); // push after visiting neighbors
}
 // linear ordering of vertex in DAGs
vector<int> topoSortDFS(int V, vector<vector<int>> &adj) {
    vector<bool> visited(V, false);
    stack<int> st;
    for (int i = 0; i < V; i++) {
        if (!visited[i])
            dfs(i, adj, visited, st);
    }

    vector<int> topo;
    while (!st.empty()) {
        topo.push_back(st.top());
        st.pop();
    }

    return topo;
}

int main() {
    int V = 6;
    vector<vector<int>> adj(V);
    
    // Same graph
    adj[5] = {0, 2};
    adj[4] = {0, 1};
    adj[2] = {3};
    adj[3] = {1};

    vector<int> result = topoSortDFS(V, adj);

    cout << "Topological Sort (DFS): ";
    for (int x : result) cout << x << " ";
    cout << endl;

    return 0;
}
