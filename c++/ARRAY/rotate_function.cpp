#include <bits/stdc++.h>
using namespace std;

int maxRotateFunction(vector<int>& nums) {
    int n = nums.size();
    long sum = 0, F = 0;
    for (int i = 0; i < n; i++) {
        sum += nums[i];
        F += i * nums[i];
    }

    long maxF = F;
    for (int i = n - 1; i >= 1; i--) {
        F = F + sum - (long)n * nums[i];
        maxF = max(maxF, F);
    }

    return (int)maxF;
}

int main() {
    vector<int> nums = {4,3,2,6};
    cout << maxRotateFunction(nums) << endl; // Output: 26
    return 0;
}
