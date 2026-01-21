#include <bits/stdc++.h>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> st;
    for (int x : nums) {
        if (st.count(x))
            return true;
        st.insert(x);
    }
    return false;
}

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++) {
        if (mp.count(nums[i]) && i - mp[nums[i]] <= k)
            return true;
        mp[nums[i]] = i;
    }
    return false;
}

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    if (k <= 0 || t < 0) return false;

    set<long long> s;
    for (int i = 0; i < nums.size(); i++) {
        auto it = s.lower_bound((long long)nums[i] - t);
        if (it != s.end() && abs(*it - nums[i]) <= t)
            return true;

        s.insert(nums[i]);
        if (s.size() > k)
            s.erase(nums[i - k]);
    }
    return false;
}

int main() {
    vector<int> nums = {1, 2, 3, 1};
    int k = 3;
    int t = 0;

    cout << (containsDuplicate(nums) ? "true" : "false") << endl;
    cout << (containsNearbyDuplicate(nums, k) ? "true" : "false") << endl;
    cout << (containsNearbyAlmostDuplicate(nums, k, t) ? "true" : "false") << endl;

    return 0;
}
