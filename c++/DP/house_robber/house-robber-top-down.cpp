#include <iostream>
#include <vector>
using namespace std;

int robMemo(int i, vector<int>& nums, vector<int>& dp) {
    if (i == 0) return nums[0];
    if (i < 0) return 0;
    if (dp[i] != -1) return dp[i];

    int pick = nums[i] + robMemo(i - 2, nums, dp);
    int skip = robMemo(i - 1, nums, dp);

    return dp[i] = max(pick, skip);
}

int rob(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, -1);
    return robMemo(n - 1, nums, dp);
}
