#include <bits/stdc++.h>
using namespace std;

// 🔸 Brute Force: Count number of subarrays with sum = k
int countSubarraysWithSumKBrute(vector<int>& nums, int k) {
    int count = 0, n = nums.size();
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = i; j < n; ++j) {
            sum += nums[j];
            if (sum == k) count++;
        }
    }
    return count;
}

// 🔸 Optimized: Using prefix sum + hashmap
int countSubarraysWithSumKOptimized(vector<int>& nums, int k) {
    unordered_map<int, int> prefixSumFreq;
    prefixSumFreq[0] = 1;
    int sum = 0, count = 0;

    for (int num : nums) {
        sum += num;
        if (prefixSumFreq.count(sum - k)) {
            count += prefixSumFreq[sum - k];
        }
        prefixSumFreq[sum]++;
    }
    return count;
}

int main() {
    vector<int> nums = {1, 2, 3, -2, 5};
    int k = 5;

    cout << "Subarray Sum Equals K:\n";
    cout << "Brute Force Count    : " << countSubarraysWithSumKBrute(nums, k) << endl;
    cout << "Optimized Count      : " << countSubarraysWithSumKOptimized(nums, k) << endl;

    return 0;
}
