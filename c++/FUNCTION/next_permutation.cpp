#include <bits/stdc++.h>
using namespace std;

void permute(vector<int>& nums, int l, vector<vector<int>>& res) {
    if (l == nums.size()) {
        res.push_back(nums);
        return;
    }
    for (int i = l; i < nums.size(); i++) {
        swap(nums[l], nums[i]);
        permute(nums, l+1, res);
        swap(nums[l], nums[i]);
    }
}

int main() {
    vector<int> nums = {1, 2, 3};

    vector<int> stlVersion = nums;
    if (next_permutation(stlVersion.begin(), stlVersion.end())) {
        cout << "Next permutation (STL): ";
        for (int x : stlVersion) cout << x << " ";
        cout << "\n";
    } else {
        cout << "No next permutation (STL)\n";
    }

    vector<vector<int>> allPerms;
    permute(nums, 0, allPerms);
    sort(allPerms.begin(), allPerms.end());

    auto it = find(allPerms.begin(), allPerms.end(), nums);
    if (it != allPerms.end() && ++it != allPerms.end()) {
        cout << "Next permutation (Recursion): ";
        for (int x : *it) cout << x << " ";
        cout << "\n";
    } else {
        cout << "No next permutation (Recursion)\n";
    }
}
