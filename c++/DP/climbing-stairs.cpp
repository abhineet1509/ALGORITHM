#include <bits/stdc++.h>
using namespace std;


int topDown(int n, vector<int>& dp) {
    if (n <= 1) return 1;        // ways for 0 or 1 step
    if (dp[n] != -1) return dp[n];

    return dp[n] = topDown(n - 1, dp) + topDown(n - 2, dp);
}

int bottomUp(int n) {
    if (n <= 1) return 1;
    vector<int> dp(n + 1);

    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];

    return dp[n];
}

int main() {
    int n = 5;  // example

    // top-down
    vector<int> dp(n + 1, -1);
    int ans1 = topDown(n, dp);

    // bottom-up
    int ans2 = bottomUp(n);

    cout << "Top-Down:  " << ans1 << endl;
    cout << "Bottom-Up: " << ans2 << endl;
}
