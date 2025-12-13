#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> count, ans;
    vector<vector<int>> g;
    int n;

    void dfs1(int u, int p) {
        count[u] = 1;
        for (int v : g[u]) {
            if (v == p) continue;
            dfs1(v, u);
            count[u] += count[v];
            ans[0] += count[v];  
        }
    }

    void dfs2(int u, int p) {
        for (int v : g[u]) {
            if (v == p) continue;
            ans[v] = ans[u] - count[v] + (n - count[v]);
            dfs2(v, u);
        }
    }

    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        n = N;
        g.assign(n, {});
        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        count.assign(n, 0);
        ans.assign(n, 0);

        dfs1(0, -1);   // compute subtree sizes + ans[0]
        dfs2(0, -1);   // compute ans[i] for all nodes

        return ans;
    }
};

int main() {
    int n;
    cin >> n;

    vector<vector<int>> edges(n - 1, vector<int>(2));
    for (int i = 0; i < n - 1; i++)
        cin >> edges[i][0] >> edges[i][1];

    Solution ob;
    vector<int> res = ob.sumOfDistancesInTree(n, edges);

    for (int x : res) cout << x << " ";
    return 0;
}
