#include <bits/stdc++.h>
using namespace std;

int numFactoredBinaryTrees(vector<int>& arr) {
    const int MOD = 1e9 + 7;
    sort(arr.begin(), arr.end());

    unordered_map<int, long long> dp;
    for (int x : arr) dp[x] = 1; // single node tree

    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] % arr[j] == 0) {
                int right = arr[i] / arr[j];
                if (dp.count(right)) {
                    dp[arr[i]] = (dp[arr[i]] + dp[arr[j]] * dp[right]) % MOD;
                }
            }
        }
    }

    long long ans = 0;
    for (auto &p : dp)
        ans = (ans + p.second) % MOD;

    return ans;
}

int main() {
    vector<int> arr = {2,4,5,10};
    cout << numFactoredBinaryTrees(arr); // Output: 7
    return 0;
}
