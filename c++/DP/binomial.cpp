#include <bits/stdc++.h>
using namespace std;


int binomialTopDown(int n, int r, vector<vector<int>>& dp) {
    if (r == 0 || r == n) return 1;
    if (dp[n][r] != -1) return dp[n][r];
    return dp[n][r] = binomialTopDown(n - 1, r - 1, dp) + binomialTopDown(n - 1, r, dp);
}

int binomialBottomUp(int n, int r) {
    vector<vector<int>> dp(n + 1, vector<int>(r + 1, 0));

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= min(i, r); j++) {
            if (j == 0 || j == i)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }
    return dp[n][r];
}

int main() {
    int n, r;
    cin >> n >> r;

    // Top-Down
    vector<vector<int>> dpTopDown(n + 1, vector<int>(r + 1, -1));
    int ansTopDown = binomialTopDown(n, r, dpTopDown);

    // Bottom-Up
    int ansBottomUp = binomialBottomUp(n, r);

    cout << "Top-Down: " << ansTopDown << endl;
    cout << "Bottom-Up: " << ansBottomUp << endl;

    return 0;
}
