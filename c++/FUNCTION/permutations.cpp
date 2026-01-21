#include <bits/stdc++.h>
using namespace std;

/* Permutations I */        // o(n!)
void permute1(int idx, vector<int>& nums, vector<vector<int>>& res) {
    if (idx == nums.size()) {
        res.push_back(nums);
        return;
    }
    for (int i = idx; i < nums.size(); i++) {
        swap(nums[idx], nums[i]);
        permute1(idx + 1, nums, res);
        swap(nums[idx], nums[i]);
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    permute1(0, nums, res);
    return res;
}

/* Permutations II */ // o(n!)
void permute2(int idx, vector<int>& nums, vector<vector<int>>& res) {
    if (idx == nums.size()) {
        res.push_back(nums);
        return;
    }
    unordered_set<int> used;
    for (int i = idx; i < nums.size(); i++) {
        if (used.count(nums[i])) continue;
        used.insert(nums[i]);
        swap(nums[idx], nums[i]);
        permute2(idx + 1, nums, res);
        swap(nums[idx], nums[i]);
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    permute2(0, nums, res);
    return res;
}

/* Next Permutation */
void nextPermutation(vector<int>& nums) {
    int n = nums.size(), i = n - 2;
    while (i >= 0 && nums[i] >= nums[i + 1]) i--;
    if (i >= 0) {
        int j = n - 1;
        while (nums[j] <= nums[i]) j--;
        swap(nums[i], nums[j]);
    }
    reverse(nums.begin() + i + 1, nums.end());
}
 string getPermutation(int n, int k) {
        vector<int> nums;
        int fact = 1;
        for (int i = 1; i <= n; i++) {
            nums.push_back(i);
            fact *= i;
        }

        k--; // convert to 0-based index
        string ans = "";

        for (int i = n; i >= 1; i--) {
            fact /= i;
            int index = k / fact;
            ans += to_string(nums[index]);
            nums.erase(nums.begin() + index);
            k %= fact;
        }

        return ans;
    }
int main() {
    vector<int> a = {1,2,3};
    vector<int> b = {1,1,2};
    vector<int> c = {1,2,3};

    permute(a);
    permuteUnique(b);
    nextPermutation(c);

    return 0;
}
