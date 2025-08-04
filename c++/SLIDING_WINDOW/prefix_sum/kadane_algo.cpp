#include <bits/stdc++.h>
using namespace std;

int kadane(vector<int>& nums) {
    int currSum = 0, maxSum = INT_MIN;

    for (int i = 0; i < nums.size(); i++) {
        currSum += nums[i];
        if (currSum > maxSum) maxSum = currSum;
        if (currSum < 0) currSum = 0;
    }

    return maxSum;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter array elements:\n";
    for (int i = 0; i < n; i++) cin >> nums[i];

    int result = kadane(nums);
    cout << "Maximum subarray sum is: " << result << endl;

    return 0;
}
