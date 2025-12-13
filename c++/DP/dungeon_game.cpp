#include <bits/stdc++.h>
using namespace std;

int minInitialPoints(vector<vector<int>>& points) {
    int m = points.size();
    int n = points[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[m - 1][n - 1] = max(1, 1 - points[m - 1][n - 1]);

    for (int j = n - 2; j >= 0; j--) {
        dp[m - 1][j] = max(1, dp[m - 1][j + 1] - points[m - 1][j]);
    }

    for (int i = m - 2; i >= 0; i--) {
        dp[i][n - 1] = max(1, dp[i + 1][n - 1] - points[i][n - 1]);
    }

    for (int i = m - 2; i >= 0; i--) {
        for (int j = n - 2; j >= 0; j--) {
            int need = min(dp[i + 1][j], dp[i][j + 1]);
            dp[i][j] = max(1, need - points[i][j]);
        }
    }

    return dp[0][0];
}

int main() {
    vector<vector<int>> points = {
        {-2, -3, 3},
        {-5, -10, 1},
        {10, 30, -5}
    };
    cout << minInitialPoints(points) << endl;
    return 0;
}
