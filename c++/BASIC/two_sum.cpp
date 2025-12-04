#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // ============================
    // 1️⃣ Brute Force — O(n²)
    // ============================
    vector<int> twoSumBrute(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target)
                    return {i, j};
            }
        }
        return {};
    }

    // ============================
    // 2️⃣ HashMap — O(n)
    // ============================
    vector<int> twoSumHashMap(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for (int i = 0; i < nums.size(); i++) {
            int need = target - nums[i];
            if (mp.count(need))
                return {mp[need], i};
            mp[nums[i]] = i;
        }
        return {};
    }

    // ============================
    // 3️⃣ Sort + Two Pointers — O(n log n)
    // ============================
    vector<int> twoSumTwoPointer(vector<int>& nums, int target) {
        vector<pair<int,int>> v;

        for (int i = 0; i < nums.size(); i++)
            v.push_back({nums[i], i});

        sort(v.begin(), v.end());

        int l = 0, r = nums.size() - 1;

        while (l < r) {
            int sum = v[l].first + v[r].first;
            if (sum == target)
                return {v[l].second, v[r].second};
            else if (sum < target)
                l++;
            else
                r--;
        }
        return {};
    }
};

int main() {
    Solution s;

    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    // Test each method
    auto a = s.twoSumBrute(nums, target);
    auto b = s.twoSumHashMap(nums, target);
    auto c = s.twoSumTwoPointer(nums, target);

    cout << "Brute force: " << a[0] << " " << a[1] << endl;
    cout << "HashMap: " << b[0] << " " << b[1] << endl;
    cout << "Two Pointer: " << c[0] << " " << c[1] << endl;

    return 0;
}
