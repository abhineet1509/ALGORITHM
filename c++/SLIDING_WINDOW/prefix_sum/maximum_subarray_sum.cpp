#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Returns pair {maxSum, length of max subarray}
pair<int,int> maxSubarraySumAndLength(vector<int>& nums) {
    int currSum = nums[0], maxSum = nums[0];
    int currLen = 1, maxLen = 1;

    for (int i = 1; i < nums.size(); i++) {
        currSum = (currSum + nums[i] > nums[i]) ? (currSum + nums[i]) : nums[i];
        currLen = (currSum == nums[i]) ? 1 : currLen + 1;
        maxLen = (currSum > maxSum) ? currLen : maxLen;
        maxSum = (currSum > maxSum) ? currSum : maxSum;
    }

    return {maxSum, maxLen};
}

// Returns pair {minSum, length of min subarray}
pair<int,int> minSubarraySumAndLength(vector<int>& nums) {
    int currSum = nums[0], minSum = nums[0];
    int currLen = 1, minLen = 1;

    for (int i = 1; i < nums.size(); i++) {
        currSum = (currSum + nums[i] < nums[i]) ? (currSum + nums[i]) : nums[i];
        currLen = (currSum == nums[i]) ? 1 : currLen + 1;
        minLen = (currSum < minSum) ? currLen : minLen;
        minSum = (currSum < minSum) ? currSum : minSum;
    }

    return {minSum, minLen};
}
int maxAbsoluteSum(vector<int>& nums) {
        int maxSum = 0, minSum = 0;
        int currMax = 0, currMin = 0;

        for (int x : nums) {
            currMax = max(x, currMax + x);
            currMin = min(x, currMin + x);

            maxSum = max(maxSum, currMax);
            minSum = min(minSum, currMin);
        }

        return max(maxSum, abs(minSum));
    }
int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    auto maxResult = maxSubarraySumAndLength(nums);
    auto minResult = minSubarraySumAndLength(nums);

    cout << "Maximum Subarray Sum: " << maxResult.first
         << ", Length: " << maxResult.second << endl;

    cout << "Minimum Subarray Sum: " << minResult.first
         << ", Length: " << minResult.second << endl;

    return 0;
}
