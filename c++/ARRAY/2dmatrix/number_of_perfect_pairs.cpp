#include <bits/stdc++.h>
using namespace std;

long long perfectPairs(vector<int>& nums) {
    long long n = nums.size();
    long long totalPairs = n * (n - 1) / 2;

    long long zeroCount = 0;
    for (int x : nums) {
        if (x == 0) zeroCount++;
    }

    long long zeroPairs = zeroCount * (zeroCount - 1) / 2;

    return totalPairs - zeroPairs;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << perfectPairs(nums);
    return 0;
}
