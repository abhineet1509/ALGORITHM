#include <bits/stdc++.h>
using namespace std;

int main() {
   
    int n, m;
    cin >> n >> m;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {

            if (i == j) dp[i][j] = 0;
            else {
                int best = INT_MAX;

                for (int cut = 1; cut < j; cut++)
                    best = min(best, 1 + dp[i][cut] + dp[i][j - cut]);

                for (int cut = 1; cut < i; cut++)
                    best = min(best, 1 + dp[cut][j] + dp[i - cut][j]);

                dp[i][j] = best;
            }
        }
    }

    cout << dp[n][m] << "\n";
    return 0;
}
