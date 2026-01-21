#include <bits/stdc++.h>
using namespace std;

/* Combination Sum I */
void dfs1(int idx, int target, vector<int>& nums,
          vector<int>& cur, vector<vector<int>>& res) {
    if (target == 0) {
        res.push_back(cur);
        return;
    }
    if (idx == nums.size() || target < 0) return;

    cur.push_back(nums[idx]);
    dfs1(idx, target - nums[idx], nums, cur, res);
    cur.pop_back();

    dfs1(idx + 1, target, nums, cur, res);
}

vector<vector<int>> combinationSum(vector<int>& nums, int target) {
    vector<vector<int>> res;
    vector<int> cur;
    dfs1(0, target, nums, cur, res);
    return res;
}

/* Combination Sum II */
void dfs2(int idx, int target, vector<int>& nums,
          vector<int>& cur, vector<vector<int>>& res) {
    if (target == 0) {
        res.push_back(cur);
        return;
    }

    for (int i = idx; i < nums.size(); i++) {
        if (i > idx && nums[i] == nums[i - 1]) continue;
        if (nums[i] > target) break;

        cur.push_back(nums[i]);
        dfs2(i + 1, target - nums[i], nums, cur, res);
        cur.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    vector<int> cur;
    dfs2(0, target, nums, cur, res);
    return res;
}
//------    Combinational Sum 3 ------//
void combSum3Helper(int start, int k, int n, vector<int>& cur, vector<vector<int>>& res) {
    if (cur.size() == k) {
        if (n == 0) res.push_back(cur);
        return;
    }

    for (int i = start; i <= 9; i++) {
        if (i > n) break; // pruning
        cur.push_back(i);
        combSum3Helper(i + 1, k, n - i, cur, res);
        cur.pop_back();
    }
}

vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> res;
    vector<int> cur;
    combSum3Helper(1, k, n, cur, res);
    return res;
}

int main() {
    vector<int> nums1 = {2,3,6,7};
    int target1 = 7;

    vector<int> nums2 = {10,1,2,7,6,1,5};
    int target2 = 8;

    vector<vector<int>> res1 = combinationSum(nums1, target1);
    vector<vector<int>> res2 = combinationSum2(nums2, target2);

    return 0;
}
