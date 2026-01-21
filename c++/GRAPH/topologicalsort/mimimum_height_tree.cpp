#include <bits/stdc++.h>
using namespace std;

vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    if (n == 1) return {0};

    vector<vector<int>> graph(n);
    vector<int> degree(n, 0);

    for (auto &e : edges) {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
        degree[e[0]]++;
        degree[e[1]]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (degree[i] == 1)
            q.push(i);
    }

    int remaining = n;

    while (remaining > 2) {
        int sz = q.size();
        remaining -= sz;

        while (sz--) {
            int node = q.front();
            q.pop();

            for (int nei : graph[node]) {
                degree[nei]--;
                if (degree[nei] == 1)
                    q.push(nei);
            }
        }
    }

    vector<int> ans;
    while (!q.empty()) {
        ans.push_back(q.front());
        q.pop();
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> edges;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    vector<int> result = findMinHeightTrees(n, edges);

    for (int x : result)
        cout << x << " ";

    return 0;
}
