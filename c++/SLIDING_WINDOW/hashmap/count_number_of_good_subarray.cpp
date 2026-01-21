#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, long long> freq;
        long long pairs = 0, ans = 0;
        int left = 0, n = nums.size();

        for (int right = 0; right < n; right++) {
            // Add nums[right]
            pairs += freq[nums[right]];
            freq[nums[right]]++;

            while (pairs >= k) {
                ans += (n - right);

                freq[nums[left]]--;
                pairs -= freq[nums[left]];
                left++;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 1, 1, 1, 1};
    int k = 10;

    cout << sol.countGood(nums, k) << endl;  // Output: 1

    return 0;
}
