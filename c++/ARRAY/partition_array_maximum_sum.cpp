#include <bits/stdc++.h>
using namespace std;

int maxSumAfterPartitioning(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> dp(n + 1, 0);

    for (int i = n - 1; i >= 0; i--) {
        int maxVal = 0;
        int best = 0;

        for (int len = 1; len <= k && i + len <= n; len++) {
            maxVal = max(maxVal, arr[i + len - 1]);
            best = max(best, maxVal * len + dp[i + len]);
        }
        dp[i] = best;
    }
    return dp[0];
}

int main() {
    vector<int> arr = {1,15,7,9,2,5,10};
    int k = 3;
    cout << maxSumAfterPartitioning(arr, k);
    return 0;
}
