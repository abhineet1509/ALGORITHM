#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>& nums, int threshold, int d) {
    int sum = 0;
    for (int x : nums) {
        sum += (x + d - 1) / d;   // ceil(x / d)
        if (sum > threshold) return false;
    }
    return true;
}

int smallestDivisor(vector<int>& nums, int threshold) {
    int low = 1;
    int high = *max_element(nums.begin(), nums.end());
    int ans = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isPossible(nums, threshold, mid)) {
            ans = mid;
            high = mid - 1;   // try smaller divisor
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n, threshold;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    cin >> threshold;

    cout << smallestDivisor(nums, threshold);
    return 0;
}
