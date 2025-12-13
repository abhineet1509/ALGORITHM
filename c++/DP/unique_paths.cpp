#include <bits/stdc++.h>
using namespace std;

// ---------------- UNIQUE PATH I (NO OBSTACLES) ----------------

// Top-Down
int solveUP1(int i, int j, int m, int n, vector<vector<int>>& dp) {
    if (i == m-1 && j == n-1) return 1;
    if (i >= m || j >= n) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    int right = solveUP1(i, j+1, m, n, dp);
    int down  = solveUP1(i+1, j, m, n, dp);
    return dp[i][j] = right + down;
}

int uniquePathsTopDown(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return solveUP1(0, 0, m, n, dp);
}

// Bottom-Up
int uniquePathsBottomUp(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 1));
    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
    return dp[m-1][n-1];
}

// Combinatorics
long long uniquePathsCombi(int m, int n) {
    long long res = 1;
    int k = min(m-1, n-1);
    for (int i = 1; i <= k; i++)
        res = res * (m + n - 2 - (k - i)) / i;
    return res;
}

// ---------------- UNIQUE PATH II (WITH OBSTACLES) ----------------

// Top-Down
int solveUP2(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
    int m = grid.size(), n = grid[0].size();

    if (i >= m || j >= n || grid[i][j] == 1) return 0;
    if (i == m-1 && j == n-1) return 1;
    if (dp[i][j] != -1) return dp[i][j];

    int right = solveUP2(i, j+1, grid, dp);
    int down  = solveUP2(i+1, j, grid, dp);
    return dp[i][j] = right + down;
}

int uniquePathsWithObstaclesTopDown(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return solveUP2(0, 0, grid, dp);
}

// Bottom-Up
int uniquePathsWithObstaclesBottomUp(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<long long>> dp(m, vector<long long>(n, 0));

    if (grid[0][0] == 1) return 0;
    dp[0][0] = 1;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                dp[i][j] = 0;
                continue;
            }
            if (i > 0) dp[i][j] += dp[i-1][j];
            if (j > 0) dp[i][j] += dp[i][j-1];
        }
    }
    return dp[m-1][n-1];
}

// ---------------- MAIN ----------------
int main() {
    cout << "--- UNIQUE PATH I ---\n";
    cout << "Top-Down      : " << uniquePathsTopDown(3, 7) << "\n";
    cout << "Bottom-Up     : " << uniquePathsBottomUp(3, 7) << "\n";
    cout << "Combinatorics : " << uniquePathsCombi(3, 7) << "\n\n";

    cout << "--- UNIQUE PATH II (WITH OBSTACLES) ---\n";
    vector<vector<int>> grid = {
        {0,0,0},
        {0,1,0},
        {0,0,0}
    };

    cout << "Top-Down  : " << uniquePathsWithObstaclesTopDown(grid) << "\n";
    cout << "Bottom-Up : " << uniquePathsWithObstaclesBottomUp(grid) << "\n";

    return 0;
}
