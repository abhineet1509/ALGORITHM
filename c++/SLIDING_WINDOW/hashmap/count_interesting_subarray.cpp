#include <bits/stdc++.h>
using namespace std;


long long countInterestingBruteForce(vector<int>& nums, int mod, int k) {
    long long count = 0;
    int n = nums.size();

    for (int i = 0; i < n; ++i) {
        int matchCount = 0;
        for (int j = i; j < n; ++j) {
            if (nums[j] % mod == k)
                matchCount++;

            if (matchCount % mod == k)
                count++;
        }
    }

    return count;
}


long long countInterestingOptimized(vector<int>& nums, int mod, int k) {
    unordered_map<int, long long> freq;
    freq[0] = 1;
    long long count = 0;
    int prefix = 0;

    for (int num : nums) {
        if (num % mod == k)
            prefix++;

        int currMod = prefix % mod;
        int target = (currMod - k + mod) % mod;

        if (freq.count(target))
            count += freq[target];

        freq[currMod]++;
    }

    return count;
}

int main() {
    vector<int> nums = {3, 1, 9, 6};
    int mod = 5;
    int k = 1;

    cout << "Input: nums = [3,1,9,6], mod = 5, k = 1\n" << endl;

    long long bruteForceResult = countInterestingBruteForce(nums, mod, k);
    long long optimizedResult  = countInterestingOptimized(nums, mod, k);

    cout << "🔴 Brute Force Result:   " << bruteForceResult << endl;
    cout << "✅ Optimized Result:     " << optimizedResult << endl;

    return 0;
}
