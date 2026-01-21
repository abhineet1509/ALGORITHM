#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> subarraysNestedLoops(vector<int>& arr) {
    vector<vector<int>> res;
    int n = arr.size();
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++) {
            vector<int> sub;
            for (int k = i; k <= j; k++) sub.push_back(arr[k]);
            res.push_back(sub);
        }
    return res;
}
/* Subsets I — Distinct Integers */
void genSubsets1(int idx, vector<int>& nums,
                 vector<int>& cur, vector<vector<int>>& res) {
    if (idx == nums.size()) {
        res.push_back(cur);
        return;
    }
    cur.push_back(nums[idx]);
    genSubsets1(idx + 1, nums, cur, res);
    cur.pop_back();
    genSubsets1(idx + 1, nums, cur, res);
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> cur;
    genSubsets1(0, nums, cur, res);
    return res;
}

/* Subsets II — With Duplicates */
void genSubsets2(int idx, vector<int>& nums,
                 vector<int>& cur, vector<vector<int>>& res) {
    res.push_back(cur); // add current combination
    for (int i = idx; i < nums.size(); i++) {
        if (i > idx && nums[i] == nums[i - 1]) continue; // skip duplicates
        cur.push_back(nums[i]);
        genSubsets2(i + 1, nums, cur, res);
        cur.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    vector<int> cur;
    genSubsets2(0, nums, cur, res);
    return res;
}

/* Subsequences — String */
void genSubseq(int idx, string& s,
               string& cur, vector<string>& res) {
    if (idx == s.size()) {
        res.push_back(cur);
        return;
    }
    cur.push_back(s[idx]);
    genSubseq(idx + 1, s, cur, res);
    cur.pop_back();
    genSubseq(idx + 1, s, cur, res);
}

vector<string> subsequences(string s) {
    vector<string> res;
    string cur;
    genSubseq(0, s, cur, res);
    return res;
}

int main() {
    vector<int> nums1 = {1,2,3};
    vector<int> nums2 = {1,2,2};
    string s = "abc";

    subsets(nums1);
    subsetsWithDup(nums2);
    subsequences(s);

    return 0;
}
