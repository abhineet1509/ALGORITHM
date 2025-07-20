#include <bits/stdc++.h>
using namespace std;

int longestSubarrayBruteForce(vector<int>& nums, int limit) {
    int n = nums.size();
    int maxLen = 0;

    for (int i = 0; i < n; ++i) {
        int currMax = nums[i];
        int currMin = nums[i];

        for (int j = i; j < n; ++j) {
            currMax = max(currMax, nums[j]);
            currMin = min(currMin, nums[j]);

            if (currMax - currMin <= limit) {
                maxLen = max(maxLen, j - i + 1);
            } else {
                break;  // If difference exceeds limit, stop expanding
            }
        }
    }

    return maxLen;
}

int longestSubarrayOptimized(vector<int>& nums, int limit) {
    deque<int> maxDeque, minDeque;
    int left = 0, maxLen = 0;

    for (int right = 0; right < nums.size(); ++right) {
        // Maintain decreasing deque for max
        while (!maxDeque.empty() && nums[right] > maxDeque.back())
            maxDeque.pop_back();
        maxDeque.push_back(nums[right]);

        // Maintain increasing deque for min
        while (!minDeque.empty() && nums[right] < minDeque.back())
            minDeque.pop_back();
        minDeque.push_back(nums[right]);

        // If diff exceeds limit, shrink window from left
        while (!maxDeque.empty() && !minDeque.empty() &&
               maxDeque.front() - minDeque.front() > limit) {
            if (nums[left] == maxDeque.front()) maxDeque.pop_front();
            if (nums[left] == minDeque.front()) minDeque.pop_front();
            ++left;
        }

        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}

// Main function to test both
int main() {
    vector<int> nums = {8, 2, 4, 7};
    int limit = 4;

    int bruteForceResult = longestSubarrayBruteForce(nums, limit);
    int optimizedResult = longestSubarrayOptimized(nums, limit);

    cout << "Brute Force Result:   " << bruteForceResult << endl;
    cout << "Optimized Result:     " << optimizedResult << endl;

    return 0;
}
