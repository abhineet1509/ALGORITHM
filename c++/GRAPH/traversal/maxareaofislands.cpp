#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        int n = grid.size();
        int m = grid[0].size();

        vector<pair<int, int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    int area = 0;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    grid[i][j] = 0;

                    while (!q.empty()) {
                        auto [x, y] = q.front(); q.pop();
                        area++;

                        for (auto [dx, dy] : directions) {
                            int nx = x + dx;
                            int ny = y + dy;

                            if (nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == 1) {
                                grid[nx][ny] = 0;
                                q.push({nx, ny});
                            }
                        }
                    }

                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};
