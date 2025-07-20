#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class CombinedSolution {
public:
    // ---------- DFS Function ----------
    void dfs(vector<vector<int>>& grid, int x, int y, int time) {
        int m = grid.size(), n = grid[0].size();

        if (x < 0 || y < 0 || x >= m || y >= n ||
            grid[x][y] == 0 || (grid[x][y] > 1 && grid[x][y] < time)) return;

        grid[x][y] = time;

        dfs(grid, x + 1, y, time + 1);
        dfs(grid, x - 1, y, time + 1);
        dfs(grid, x, y + 1, time + 1);
        dfs(grid, x, y - 1, time + 1);
    }

    // ---------- DFS-based rotting ----------
    int dfsRotting(vector<vector<int>> grid) {
        int m = grid.size(), n = grid[0].size();

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == 2)
                    dfs(grid, i, j, 2); // start time from 2

        int maxTime = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == 1)
                    return -1; // fresh remains
                else
                    maxTime = max(maxTime, grid[i][j]);

        return maxTime - 2; // subtract offset
    }

    // ---------- BFS-based rotting ----------
    int bfsRotting(vector<vector<int>> grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == 2)
                    q.push({i, j});
                else if (grid[i][j] == 1)
                    fresh++;

        if (fresh == 0) return 0;

        int time = -1;
        vector<pair<int, int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};

        while (!q.empty()) {
            int sz = q.size();
            time++;

            for (int i = 0; i < sz; ++i) {
                auto [x, y] = q.front(); q.pop();

                for (auto [dx, dy] : dirs) {
                    int nx = x + dx, ny = y + dy;

                    if (nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                        fresh--;
                    }
                }
            }
        }

        return (fresh == 0) ? time : -1;
    }

    // ---------- Combined Runner ----------
    void run() {
        vector<vector<int>> grid = {
            {2,1,1},
            {1,1,0},
            {0,1,1}
        };

        int bfsTime = bfsRotting(grid);
        int dfsTime = dfsRotting(grid);

        cout << "BFS Time to rot all oranges: " << bfsTime << endl;
        cout << "DFS Time to rot all oranges: " << dfsTime << endl;

        if (bfsTime == dfsTime)
            cout << "✅ Both approaches gave the same result." << endl;
        else
            cout << "⚠️ Results differ! BFS is preferred for accuracy." << endl;
    }
};

int main() {
    CombinedSolution obj;
    obj.run();
    return 0;
}
