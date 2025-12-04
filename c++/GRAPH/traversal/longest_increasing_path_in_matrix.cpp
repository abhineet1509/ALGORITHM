#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n, m;
    vector<vector<int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    // ---------- DFS + Memoization ----------
    int dfs(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        if (dp[i][j] != -1) return dp[i][j];
        int maxLen = 1;

        for (auto& dir : directions) {
            int ni = i + dir[0];
            int nj = j + dir[1];

            if (ni >= 0 && ni < n && nj >= 0 && nj < m && matrix[ni][nj] > matrix[i][j]) {
                maxLen = max(maxLen, 1 + dfs(ni, nj, matrix, dp));
            }
        }

        return dp[i][j] = maxLen;
    }

    int longestIncreasingPathDFS(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int maxPath = 0;

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                maxPath = max(maxPath, dfs(i, j, matrix, dp));

        return maxPath;
    }

    // ---------- BFS + Topological Sort ----------
    int longestIncreasingPathBFS(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();

        vector<vector<int>> indegree(n, vector<int>(m, 0));
        queue<pair<int, int>> q;

        // Count in-degrees
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                for (auto& dir : directions) {
                    int ni = i + dir[0];
                    int nj = j + dir[1];
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m && matrix[ni][nj] > matrix[i][j]) {
                        indegree[ni][nj]++;
                    }
                }
            }
        }

        // Enqueue cells with 0 in-degree
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (indegree[i][j] == 0)
                    q.push({i, j});

        int level = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [i, j] = q.front();
                q.pop();
                for (auto& dir : directions) {
                    int ni = i + dir[0];
                    int nj = j + dir[1];
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m && matrix[ni][nj] > matrix[i][j]) {
                        indegree[ni][nj]--;
                        if (indegree[ni][nj] == 0) {
                            q.push({ni, nj});
                        }
                    }
                }
            }
            level++;
        }

        return level;
    }

    // ---------- Choose One Method ----------
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        // You can switch between:
        // return longestIncreasingPathDFS(matrix); // DFS with memoization
        return longestIncreasingPathBFS(matrix);    // BFS (Topological Sort)
    }
};

// ---------- Driver Code ----------
int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {9, 9, 4},
        {6, 6, 8},
        {2, 1, 1}
    };

    cout << "Longest Increasing Path Length = " << sol.longestIncreasingPath(matrix) << endl;
    return 0;
}
  auto [i, j] = q.front();