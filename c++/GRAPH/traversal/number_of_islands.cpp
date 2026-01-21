#include <iostream>
#include <vector>
using namespace std;
 // Battleship in a board
class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        int n = grid.size();
        int m = grid[0].size();

        // Boundary and water check
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == '0') return;

        // Mark the current land as visited
        grid[i][j] = '0';

        // Visit all 4 connected directions
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;

        int m = grid[0].size();
        int count = 0;

        // Traverse the entire grid
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '1') {
                    count++;
                    dfs(grid, i, j); // sink this island
                }
            }
        }
        return count;
    }
};

int main() {
    Solution sol;

    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };

    int islands = sol.numIslands(grid);
    cout << "Number of islands: " << islands << endl;

    return 0;
}
