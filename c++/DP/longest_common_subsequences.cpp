#include <bits/stdc++.h>
using namespace std;

int solve(int i, int j, string &a, string &b, vector<vector<int>>& dp) {
    if (i == a.size() || j == b.size()) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    if (a[i] == b[j]) return dp[i][j] = 1 + solve(i+1, j+1, a, b, dp);
    return dp[i][j] = max(solve(i+1, j, a, b, dp), solve(i, j+1, a, b, dp));
}

int lcsTopDown(string a, string b) {
    vector<vector<int>> dp(a.size(), vector<int>(b.size(), -1));
    return solve(0, 0, a, b, dp);
}

pair<int,string> lcsBottomUp(string a, string b) {
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    // Corrected: loop i = 1..n, j = 1..m
    for (int i = 1; i <= n; i++) //lcs of empty string
        for (int j = 1; j <= m; j++)
            dp[i][j] = (a[i-1] == b[j-1]) ? 1 + dp[i-1][j-1] : max(dp[i-1][j], dp[i][j-1]);

    // reconstruct LCS
    int i = n, j = m;
    string s = "";
    while (i > 0 && j > 0) {
        if (a[i-1] == b[j-1]) {
            s += a[i-1];
            i--; j--;
        } else if (dp[i-1][j] > dp[i][j-1]) i--;
        else j--;
    }
    reverse(s.begin(), s.end());
    return {dp[n][m], s};
}

int main() {
    string a, b;
    cin >> a >> b;

    cout << lcsTopDown(a, b) << "\n";

    auto p = lcsBottomUp(a, b);
    cout << p.first << "\n" << p.second << "\n";
}
