#include <bits/stdc++.h>
using namespace std;

int solve(int i, int j, vector<vector<int>>& t, vector<vector<int>>& dp) {
    if (i == t.size() - 1) return t[i][j];
    if (dp[i][j] != -1) return dp[i][j];

    int down = solve(i + 1, j, t, dp);
    int diag = solve(i + 1, j + 1, t, dp);

    return dp[i][j] = t[i][j] + min(down, diag);
}

int minimumTotalBU(vector<vector<int>>& t) {
    int n = t.size();
    vector<vector<int>> dp = t;
    for (int i = n - 2; i >= 0; i--)
        for (int j = 0; j <= i; j++)
            dp[i][j] += min(dp[i + 1][j], dp[i + 1][j + 1]);
    return dp[0][0];
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> tri(n);
    for (int i = 0; i < n; i++) {
        tri[i].resize(i + 1);
        for (int j = 0; j <= i; j++) cin >> tri[i][j];
    }

    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout << solve(0, 0, tri, dp) << endl;
    cout << minimumTotalBU(tri) << endl;
}
