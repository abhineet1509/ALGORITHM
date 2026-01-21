#include <bits/stdc++.h>
using namespace std;

// Check if we can split nums into <= m subarrays with max sum <= target
bool canSplit(vector<int>& nums, int m, long long target) {
    long long sum = 0;
    int count = 1; // at least one subarray
    for (int num : nums) {
        if (sum + num > target) {
            sum = num;
            count++;
            if (count > m) return false;
        } else {
            sum += num;
        }
    }
    return true;
}

int splitArray(vector<int>& nums, int m) {
    long long left = *max_element(nums.begin(), nums.end());
    long long right = accumulate(nums.begin(), nums.end(), 0LL);
    long long ans = right;

    while (left <= right) {
        long long mid = left + (right - left) / 2;
        if (canSplit(nums, m, mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return (int)ans;
}

int main() {
    vector<int> nums = {7, 2, 5, 10, 8};
    int m = 2;
    cout << "Minimum largest sum: " << splitArray(nums, m) << endl; // 18
    return 0;
}
