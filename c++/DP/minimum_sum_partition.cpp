#include <bits/stdc++.h>
using namespace std;

int minSumPartition(vector<int> &arr) {
    int n = arr.size();
    int total = accumulate(arr.begin(), arr.end(), 0);

    int W = total / 2;

    vector<int> dp(W + 1, 0);

    for (int x : arr) {
        for (int j = W; j >= x; j--) {
            dp[j] = max(dp[j], dp[j - x] + x);
        }
    }

    int best = dp[W];
    return total - 2 * best;
}

int main() {
    vector<int> arr = {1, 6, 11, 5};
    cout << minSumPartition(arr) << endl; 
    return 0;
}
