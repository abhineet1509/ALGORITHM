#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int minimumSemesters(int n, vector<vector<int>>& relations) {
    vector<vector<int>> adj(n + 1);
    vector<int> inDegree(n + 1, 0);

    // Step 1: Build the graph
    for (auto& rel : relations) {
        int u = rel[0], v = rel[1];
        adj[u].push_back(v);
        inDegree[v]++;
    }

    // Step 2: Kahn's BFS
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == 0)
            q.push(i);
    }

    int semester = 0;
    int completed = 0;

    while (!q.empty()) {
        int size = q.size(); // Number of courses this semester
        semester++;

        for (int i = 0; i < size; i++) {
            int u = q.front(); q.pop();
            completed++;

            for (int v : adj[u]) {
                inDegree[v]--;
                if (inDegree[v] == 0)
                    q.push(v);
            }
        }
    }

    return (completed == n) ? semester : -1; // -1 → cycle (impossible)
}
