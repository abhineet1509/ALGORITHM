#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> freq;
        freq[0] = 1;   // empty prefix

        int sum = 0, ans = 0;

        for (int x : nums) {
            sum += x;
            if (freq.count(sum - goal))
                ans += freq[sum - goal];
            freq[sum]++;
        }
        return ans;
    }
};

int main() {
    int n, goal;
    cin >> n >> goal;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution sol;
    cout << sol.numSubarraysWithSum(nums, goal) << endl;

    return 0;
}
