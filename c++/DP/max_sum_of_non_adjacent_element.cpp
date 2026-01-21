#include <bits/stdc++.h>
using namespace std;

int maxSumMemo(vector<int>& arr, int i, vector<int>& dp) {
    if (i < 0) return 0;
    if (i == 0) return arr[0];
    if (dp[i] != -1) return dp[i];

    int pick = arr[i] + maxSumMemo(arr, i - 2, dp);
    int notPick = maxSumMemo(arr, i - 1, dp);

    return dp[i] = max(pick, notPick);
}

int maxSumNonAdjacent(vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return 0;
    if (n == 1) return arr[0];

    vector<int> dp(n, 0);
    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);

    for (int i = 2; i < n; i++) {
        dp[i] = max(arr[i] + dp[i - 2], dp[i - 1]);
    }

    return dp[n - 1];
}

int maxSum(vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return 0;
    if (n == 1) return arr[0];

    int prev2 = 0;
    int prev1 = arr[0];
    int curr;

    for (int i = 1; i < n; i++) {
        int pick = arr[i] + prev2;
        int notPick = prev1;
        curr = max(pick, notPick);

        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}
int main() {
    int n;
    cin >> n;
    vector<int> arr(n), dp(n, -1);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << maxSumMemo(arr, n - 1, dp) << endl;
}
