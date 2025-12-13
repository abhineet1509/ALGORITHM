#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

// ---------------------------------------------------------
// 1. Pure Recursion
// ---------------------------------------------------------
int rec(int i, int amount, vector<int>& coins) {
    if (amount == 0) return 0;
    if (i == coins.size() || amount < 0) return INF;

    // take
    int take = 1 + rec(i, amount - coins[i], coins);
    // skip
    int skip = rec(i + 1, amount, coins);

    return min(take, skip);
}

// ---------------------------------------------------------
// 2. Top-Down DP (Memoization)
// ---------------------------------------------------------
int topdown(int i, int amount, vector<int>& coins, vector<vector<int>>& dp) {
    if (amount == 0) return 0;
    if (i == coins.size() || amount < 0) return INF;
    if (dp[i][amount] != -1) return dp[i][amount];

    int take = 1 + topdown(i, amount - coins[i], coins, dp);
    int skip = topdown(i + 1, amount, coins, dp);

    return dp[i][amount] = min(take, skip);
}

// ---------------------------------------------------------
// 3. Bottom-Up DP
// ---------------------------------------------------------
int bottomup(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, INF));

    for (int i = 0; i <= n; i++) dp[i][0] = 0;

    for (int i = n - 1; i >= 0; i--) {
        for (int a = 1; a <= amount; a++) {
            int skip = dp[i + 1][a];
            int take = INF;
            if (a - coins[i] >= 0)
                take = 1 + dp[i][a - coins[i]];

            dp[i][a] = min(take, skip);
        }
    }

    return dp[0][amount];
}

// ---------------------------------------------------------
// MAIN
// ---------------------------------------------------------
int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    // 1. Recursion
    int ans1 = rec(0, amount, coins);
    if (ans1 >= INF) ans1 = -1;

    // 2. Top-down
    vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
    int ans2 = topdown(0, amount, coins, dp);
    if (ans2 >= INF) ans2 = -1;

    // 3. Bottom-up
    int ans3 = bottomup(coins, amount);
    if (ans3 >= INF) ans3 = -1;

    cout << "Recursion: " << ans1 << endl;
    cout << "Top-Down: " << ans2 << endl;
    cout << "Bottom-Up: " << ans3 << endl;
}
