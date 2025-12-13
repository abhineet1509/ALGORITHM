#include <bits/stdc++.h>
using namespace std;

int longestSubarraySumK(vector<int>& a, long long K) {
    unordered_map<long long, int> mp;  // prefix sum -> first index
    long long sum = 0;
    int ans = 0;

    for (int i = 0; i < (int)a.size(); i++) {
        sum += a[i];

        if (sum == K) ans = max(ans, i + 1);

        if (mp.count(sum - K))
            ans = max(ans, i - mp[sum - K]);

        if (!mp.count(sum)) mp[sum] = i;
    }
    return ans;
}

int main() {
    vector<int> a = {1, -1, 5, -2, 3};
    long long k = 3;
    cout << longestSubarraySumK(a, k);
}
