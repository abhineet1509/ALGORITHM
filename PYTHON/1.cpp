#include <bits/stdc++.h>
using namespace std;

bool isValid(const vector<int>& sub, int k) {
    if (sub.size() < 2) return false;
    int mod = (sub[0] + sub[1]) % k;
    for (int i = 1; i < sub.size() - 1; ++i) {
        if ((sub[i] + sub[i + 1]) % k != mod)
            return false;
    }
    return true;
}

int longestValidSubsequence(vector<int>& nums, int k) {
    int n = nums.size();
    int maxLen = 0;

    // Generate all subsets (2^n possibilities)
    for (int mask = 0; mask < (1 << n); ++mask) {
        vector<int> sub;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                sub.push_back(nums[i]);
            }
        }

        if (isValid(sub, k)) {
            maxLen = max(maxLen, (int)sub.size());
        }
    }

    return maxLen;
}

int main() {
    vector<int> nums1 = {1, 2, 3, 4, 5};
    int k1 = 2;
    cout << "Longest Valid Subsequence Length: " << longestValidSubsequence(nums1, k1) << endl;

    vector<int> nums2 = {1, 4, 2, 3, 1, 4};
    int k2 = 3;
    cout << "Longest Valid Subsequence Length: " << longestValidSubsequence(nums2, k2) << endl;

    return 0;
}
