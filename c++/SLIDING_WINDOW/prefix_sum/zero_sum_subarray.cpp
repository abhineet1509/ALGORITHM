#include <bits/stdc++.h>
using namespace std;

// 🔸 Brute Force: Check if any subarray has sum = 0
bool hasZeroSumSubarrayBrute(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = i; j < n; ++j) {
            sum += nums[j];
            if (sum == 0) return true;
        }
    }
    return false;
}

long long countZeroSumSubarrays(vector<int>& arr) {
    unordered_map<long long, long long> mp;
    long long prefix = 0, count = 0;

    mp[0] = 1; 

    for (int x : arr) {
        prefix += x;

        if (mp.find(prefix) != mp.end()) {
            count += mp[prefix];
        }

        mp[prefix]++;
    }

    return count;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << countZeroSumSubarrays(arr) << endl;
    return 0;
}
