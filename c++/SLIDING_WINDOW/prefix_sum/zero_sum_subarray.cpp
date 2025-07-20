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

// 🔸 Optimized: Using prefix sum + hashset
bool hasZeroSumSubarrayOptimized(vector<int>& nums) {
    unordered_set<int> seen;
    int sum = 0;
    for (int num : nums) {
        sum += num;
        if (sum == 0 || seen.count(sum)) return true;
        seen.insert(sum);
    }
    return false;
}

int main() {
    vector<int> nums = {4, 2, -3, 1, 6};

    cout << "Zero Sum Subarray Exists:\n";
    cout << "Brute Force Result     : " << (hasZeroSumSubarrayBrute(nums) ? "Yes" : "No") << endl;
    cout << "Optimized Result       : " << (hasZeroSumSubarrayOptimized(nums) ? "Yes" : "No") << endl;

    return 0;
}
