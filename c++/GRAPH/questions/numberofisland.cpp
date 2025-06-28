#include <iostream>
#include <vector>
using namespace std;

void dfs(int i, int j, vector<vector<char>> &grid) {
    int m = grid.size();
    int n = grid[0].size();

    // Boundary and water check
    if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == '0')
        return;

    // Mark this cell as visited (sink it)
    grid[i][j] = '0';

    // Visit all 4 neighbors (up, down, left, right)
    dfs(i + 1, j, grid);
    dfs(i - 1, j, grid);
    dfs(i, j + 1, grid);
    dfs(i, j - 1, grid);
}

int numIslands(vector<vector<char>> &grid) {
    if (grid.empty()) return 0;
    int count = 0;
    int m = grid.size(), n = grid[0].size();

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == '1') {
                ++count;
                dfs(i, j, grid); // Sink the island
            }
        }
    }

    return count;
}
