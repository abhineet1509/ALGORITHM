#include <bits/stdc++.h>
using namespace std;

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    if (grid[0][0] == 1 || grid[n-1][m-1] == 1)
        return -1; // start or end blocked

    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    queue<pair<int,int>> q;

    int dr[8] = {-1,-1,-1,0,0,1,1,1};
    int dc[8] = {-1,0,1,-1,1,-1,0,1};

    dist[0][0] = 1; // start counts as step 1
    q.push({0,0});

    while (!q.empty()) {
        pair<int,int> p = q.front();
        int r = p.first;
        int c = p.second;
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nc >= 0 && nr < n && nc < m &&
                grid[nr][nc] == 0 && dist[nr][nc] > dist[r][c] + 1) {
                
                dist[nr][nc] = dist[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }

    return (dist[n-1][m-1] == INT_MAX) ? -1 : dist[n-1][m-1];
}

int main() {
    int n, m;
    cout << "Enter rows and columns: ";
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    cout << "Enter binary matrix (0 = free, 1 = blocked):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    int result = shortestPathBinaryMatrix(grid);
    if (result == -1)
        cout << "No path exists\n";
    else
        cout << "Shortest path length: " << result << endl;

    return 0;
}
