#include <bits/stdc++.h>
using namespace std;

int n; // number of nodes
vector<vector<int>> adj;
vector<int> visited, depth;
int maxCycle = -1;

void dfs(int u, int d) {
    visited[u] = 1;
    depth[u] = d;
    
    for(int v : adj[u]) {
        if(!visited[v]) {
            dfs(v, d+1);
        } else if(visited[v]==1) {
            // back edge found -> cycle
            maxCycle = max(maxCycle, d - depth[v] + 1);
        }
    }
    visited[u] = 2; // mark done
}

int longestCycle(int nodes) {
    visited.assign(nodes, 0);
    depth.assign(nodes, 0);
    for(int i=0;i<nodes;i++)
        if(!visited[i])
            dfs(i,0);
    return maxCycle;
}

int main() {
    n = 5; // example
    adj.assign(n, vector<int>());

    // example edges
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(0); // cycle of length 3
    adj[2].push_back(3);
    adj[3].push_back(4);

    cout << "Length of longest cycle: " << longestCycle(n) << endl; // Output: 3
}
