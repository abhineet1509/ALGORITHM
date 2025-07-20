#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxSubarrayLengthWithMaxSum(vector<int>& nums) {
    int currSum = 0, currLen = 0, maxSum = INT_MIN, maxLen = 0;
    for (int x : nums) {
        currSum = (currSum <= 0 ? x : currSum + x);
        currLen = (currSum == x ? 1 : currLen + 1);
        maxLen = (currSum > maxSum ? currLen : currSum == maxSum ? max(maxLen, currLen) : maxLen);
        maxSum = max(maxSum, currSum);
    }
    return maxLen;
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Length of subarray with maximum sum: " << maxSubarrayLengthWithMaxSum(nums) << endl;
    return 0;
}
