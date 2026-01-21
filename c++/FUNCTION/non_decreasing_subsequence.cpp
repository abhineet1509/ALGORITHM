#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int>& nums, int index, vector<int>& cur, vector<vector<int>>& res, set<vector<int>>& seen) {
    if(cur.size() >= 2 && seen.find(cur) == seen.end()) {
        res.push_back(cur);
        seen.insert(cur);
    }

    for(int i = index; i < nums.size(); i++) {
        if(cur.empty() || nums[i] >= cur.back()) {
            cur.push_back(nums[i]);
            dfs(nums, i + 1, cur, res, seen);
            cur.pop_back();
        }
    }
}

vector<vector<int>> findSubsequences(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> cur;
    set<vector<int>> seen; // to avoid duplicates
    dfs(nums, 0, cur, res, seen);
    return res;
}

int main() {
    vector<int> nums = {4, 6, 7, 7};
    vector<vector<int>> ans = findSubsequences(nums);

    for(auto &v : ans) {
        for(int x : v) cout << x << " ";
        cout << endl;
    }

    return 0;
}
