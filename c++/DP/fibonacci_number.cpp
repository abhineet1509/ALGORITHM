#include <bits/stdc++.h>
using namespace std;

long long fibTop(int n, vector<long long>& dp) {
    if (n <= 1) return n;
    if (dp[n] != 0) return dp[n];
    return dp[n] = fibTop(n-1, dp) + fibTop(n-2, dp);
}

long long fibBottom(int n, vector<long long>& a) {
    a.resize(n+1);
    a[0] = 0;
    if (n >= 1) a[1] = 1;
    for (int i = 2; i <= n; i++) a[i] = a[i-1] + a[i-2];
    return a[n];
}

long long kBon(int n, int k, vector<long long>& a) {
    a.assign(n+1, 0);
    for (int i = 0; i < k && i <= n; i++) a[i] = 1;
    long long s = k * 1LL;
    for (int i = k; i <= n; i++) {
        a[i] = s;
        s += a[i] - a[i-k];
    }
    return a[n];
}

int lenLongestFibSubseq(vector<int>& arr) {
    int n = arr.size();
    unordered_map<int, int> index;
    for (int i = 0; i < n; i++) index[arr[i]] = i;

    vector<vector<int>> dp(n, vector<int>(n, 2));
    int ans = 0;

    for (int j = 0; j < n; j++) {
        for (int i = 0; i < j; i++) {
            int prev = arr[j] - arr[i];
            if (prev < arr[i] && index.count(prev)) {
                int k = index[prev];
                dp[i][j] = dp[k][i] + 1;
                ans = max(ans, dp[i][j]);
            }
        }
    }
    return ans >= 3 ? ans : 0;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<long long> dp(n+1, 0);
    long long t = fibTop(n, dp);
    cout << t << "\n";
    for (int i = 0; i <= n; i++) cout << dp[i] << " ";
    cout << "\n";

    vector<long long> b;
    long long bt = fibBottom(n, b);
    cout << bt << "\n";
    for (auto x : b) cout << x << " ";
    cout << "\n";

    vector<long long> kb;
    long long kv = kBon(n, k, kb);
    cout << kv << "\n";
    for (auto x : kb) cout << x << " ";
}
