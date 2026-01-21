#include <bits/stdc++.h>
using namespace std;

class Solution {
    static const int MOD = 1e9 + 7;
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        // dp[i][j][r] = number of paths to (i,j) such that sum % k == r
        vector<vector<vector<int>>> dp(m,
            vector<vector<int>>(n, vector<int>(k, 0)));

        dp[0][0][grid[0][0] % k] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int r = 0; r < k; r++) {
                    if (dp[i][j][r] == 0) continue;
                    long long cur = dp[i][j][r];
                    // move down
                    if (i + 1 < m) {
                        int nr = (r + grid[i+1][j]) % k;
                        dp[i+1][j][nr] = (dp[i+1][j][nr] + cur) % MOD;
                    }
                    // move right
                    if (j + 1 < n) {
                        int nr = (r + grid[i][j+1]) % k;
                        dp[i][j+1][nr] = (dp[i][j+1][nr] + cur) % MOD;
                    }
                }
            }
        }

        return dp[m-1][n-1][0];
    }
};

// Example usage:
int main() {
  Solution sol;
  vector<vector<int>> grid = {{5,2,4},{3,0,5},{0,7,2}};
  int k = 3;
  cout << sol.numberOfPaths(grid, k) << endl; // Output -> 2
}
