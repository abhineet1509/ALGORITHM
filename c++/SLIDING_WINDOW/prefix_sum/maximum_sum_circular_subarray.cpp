#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCircularSubarrayBruteForce(vector<int>& arr) {
    int n = arr.size();
    int maxSum = INT_MIN;

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int len = 0; len < n; len++) {
            sum += arr[(i + len) % n];
            maxSum = max(maxSum, sum);
        }
    }

    return maxSum;
}

    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0;
        int max_sum = nums[0], cur_max = 0;
        int min_sum = nums[0], cur_min = 0;

        for (int num : nums) {
            cur_max = max(cur_max + num, num);
            max_sum = max(max_sum, cur_max);

            cur_min = min(cur_min + num, num);
            min_sum = min(min_sum, cur_min);

            total += num;
        }

        // If all numbers are negative, return the max single element
        if (max_sum < 0) return max_sum;

        return max(max_sum, total - min_sum);
    }
};

int main() {
    Solution sol;

    vector<int> nums;
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter the elements:\n";
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        nums.push_back(val);
    }

    int result = sol.maxSubarraySumCircular(nums);
    cout << "Maximum Circular Subarray Sum = " << result << endl;

    return 0;
}
