#include <bits/stdc++.h>
using namespace std;

// ---------- Longest Subarray with SUM == K ----------
int longestSubarraySumK(vector<int>& a, long long K) {
    unordered_map<long long, int> mp;  // prefixSum -> first index
    long long sum = 0;
    int ans = 0;

    for (int i = 0; i < (int)a.size(); i++) {
        sum += a[i];

        if (sum == K)
            ans = max(ans, i + 1);

        if (mp.count(sum - K))
            ans = max(ans, i - mp[sum - K]);

        if (!mp.count(sum))
            mp[sum] = i;
    }
    return ans;
}

// ---------- Longest Subarray with SUM == 0 ----------
int longestSubarraySumZero(vector<int>& a) {
    unordered_map<long long, int> mp;  // prefixSum -> first index
    long long sum = 0;
    int ans = 0;

    for (int i = 0; i < (int)a.size(); i++) {
        sum += a[i];

        if (sum == 0)
            ans = max(ans, i + 1);

        if (mp.count(sum))
            ans = max(ans, i - mp[sum]);
        else
            mp[sum] = i;
    }
    return ans;
}

// ---------- Driver ----------
int main() {
    vector<int> a = {1, -1, 5, -2, 3};

    long long k = 3;

    cout << "Longest subarray with sum == K : "
         << longestSubarraySumK(a, k) << endl;

    cout << "Longest subarray with sum == 0 : "
         << longestSubarraySumZero(a) << endl;

    return 0;
}
