#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> dp;

int countTargetSum(vector<int>& nums, int index, int target) {
    string key = to_string(index) + "," + to_string(target);
    if (dp.count(key)) return dp[key];

    if (index == nums.size()) return target == 0 ? 1 : 0;

    int add = countTargetSum(nums, index + 1, target - nums[index]);
    int subtract = countTargetSum(nums, index + 1, target + nums[index]);

    dp[key] = add + subtract;
    return dp[key];
}

int main() {
    vector<int> nums = {1,1,1,1,1};
    int S = 3;
    cout << "Number of ways: " << countTargetSum(nums, 0, S) << endl;
    return 0;
}
