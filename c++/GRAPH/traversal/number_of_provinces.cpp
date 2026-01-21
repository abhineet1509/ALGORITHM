#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int node, vector<vector<int>>& isConnected, vector<int>& visited) {
        visited[node] = 1;

        for (int j = 0; j < isConnected.size(); j++) {
            if (isConnected[node][j] == 1 && !visited[j]) {
                dfs(j, isConnected, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n, 0);
        int provinces = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, isConnected, visited);
                provinces++;
            }
        }
        return provinces;
    }
};
//  void bfs(int start, vector<bool>& visited) {
//         queue<int> q;
//         q.push(start);
//         visited[start] = true;

//         while (!q.empty()) {
//             int node = q.front();
//             q.pop();

//             for (int j = 0; j < V; j++) {
//                 if (adj[node][j] == 1 && !visited[j]) {
//                     visited[j] = true;
//                     q.push(j);
//                 }
//             }
//         }
//     }

//     int countConnectedComponents() {
//         vector<bool> visited(V, false);
//         int components = 0;

//         for (int i = 0; i < V; i++) {
//             if (!visited[i]) {
//                 bfs(i, visited);
//                 components++;
//             }
//         }
//         return components;
//     }

int main() {
    int n;
    cout << "Enter number of cities: ";
    cin >> n;

    vector<vector<int>> isConnected(n, vector<int>(n));
    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> isConnected[i][j];
        }
    }

    Solution obj;
    cout << "Number of Provinces: " << obj.findCircleNum(isConnected) << endl;

    return 0;
}
