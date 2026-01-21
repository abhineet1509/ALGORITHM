#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> mp;
    for (int i = 0; i < nums.size(); i++) {
        int need = target - nums[i];
        if (mp.count(need)) return {mp[need], i}; // {need, nums[i]}
        mp[nums[i]] = i;                          // mp[i] = nums[i]
    }
    return {};
}
vector<pair<int,int>> allTwoSumValues(vector<int>& nums, int target) {
    unordered_map<int, int> freq;
    vector<pair<int,int>> ans;

    for (int x : nums) {
        int need = target - x;
        if (freq[need] > 0) {
            ans.push_back({need, x});
            freq[need]--;
        } else {
            freq[x]++;
        }
    }
    return ans;
}
 // two sum - II
int twoSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int l = 0, r = nums.size() - 1;
    int ans = nums[l] + nums[r];

    while (l < r) {
        int sum = nums[l] + nums[r];
        if (abs(sum - target) < abs(ans - target))
            ans = sum;
        if (sum < target) l++;
        else r--;
    }
    return ans;
}

vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    int n = nums.size();

    for (int i = 0; i < n - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        int l = i + 1, r = n - 1;

        while (l < r) {
            int sum = nums[i] + nums[l] + nums[r];
            if (sum == 0) {
                res.push_back({nums[i], nums[l], nums[r]});
                while (l < r && nums[l] == nums[l + 1]) l++;
                while (l < r && nums[r] == nums[r - 1]) r--;
                l++; r--;
            } else if (sum < 0) l++;
            else r--;
        }
    }
    return res;
}

int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int ans = nums[0] + nums[1] + nums[2];

    for (int i = 0; i < n - 2; i++) {
        int l = i + 1, r = n - 1;
        while (l < r) {
            int sum = nums[i] + nums[l] + nums[r];
            if (abs(sum - target) < abs(ans - target))
                ans = sum;
            if (sum < target) l++;
            else if (sum > target) r--;
            else return target;
        }
    }
    return ans;
}

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    int n = nums.size();

    for (int i = 0; i < n - 3; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        for (int j = i + 1; j < n - 2; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;
            int l = j + 1, r = n - 1;

            while (l < r) {
                long long sum = (long long)nums[i] + nums[j] + nums[l] + nums[r];
                if (sum == target) {
                    res.push_back({nums[i], nums[j], nums[l], nums[r]});
                    while (l < r && nums[l] == nums[l + 1]) l++;
                    while (l < r && nums[r] == nums[r - 1]) r--;
                    l++; r--;
                } else if (sum < target) l++;
                else r--;
            }
        }
    }
    return res;
}

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    int target = 1;

    vector<int> res2 = twoSum(nums, target);
    int res2c = twoSumClosest(nums, target);
    vector<vector<int>> res3 = threeSum(nums);
    int res3c = threeSumClosest(nums, target);
    vector<vector<int>> res4 = fourSum(nums, target);

    return 0;
}
