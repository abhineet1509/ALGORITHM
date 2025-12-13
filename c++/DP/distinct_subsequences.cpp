#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    int n, m;
    vector<vector<int>> memo;

    // -------- Recursive + Memoization --------
    int dfs(string &s, string &t, int i, int j) {
        if (j == m) return 1;       // empty t
        if (i == n) return 0;       // empty s
        if (memo[i][j] != -1) return memo[i][j];                 // Q. BETTER STRING

        if (s[i] == t[j])
            return memo[i][j] = dfs(s, t, i + 1, j + 1) + dfs(s, t, i + 1, j);
        else
            return memo[i][j] = dfs(s, t, i + 1, j);
    }

    int numDistinctRecursive(string s, string t) {
        n = s.size();
        m = t.size();
        memo.assign(n, vector<int>(m, -1));
        return dfs(s, t, 0, 0);
    }

    // -------- Bottom-Up DP --------
    int numDistinctDP(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<unsigned long long>> dp(n + 1, vector<unsigned long long>(m + 1, 0));

        // base case: empty t
        for (int i = 0; i <= n; i++) dp[i][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        // Optional: print DP table
        cout << "DP Table:" << endl;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) cout << dp[i][j] << " ";
            cout << endl;
        }

        return dp[n][m];
    }
};

int main() {
    Solution sol;
    string s = "rabbbit", t = "rabbit";

    int ans1 = sol.numDistinctRecursive(s, t);
    cout << "Recursive + Memoization: " << ans1 << endl;

    int ans2 = sol.numDistinctDP(s, t);
    cout << "Bottom-Up DP: " << ans2 << endl;

    return 0;
}
