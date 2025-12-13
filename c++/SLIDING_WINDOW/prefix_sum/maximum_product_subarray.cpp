#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    // 1. Brute Force: O(n^2)
    int maxProductBruteForce(vector<int>& nums) {
        int n = nums.size();
        int maxProd = nums[0];      // -2 ,-3,-4

        for (int i = 0; i < n; i++) {
            int prod = 1;
            for (int j = i; j < n; j++) {
                prod *= nums[j];
                maxProd = max(maxProd, prod);
            }
        }
        return maxProd;
    }

    // 2. Prefix-Suffix Product (Your Approach)
    int maxProductPrefixSuffix(vector<int>& nums) {
        int n = nums.size();
        int leftProduct = 1, rightProduct = 1;
        int maxProd = nums[0];

        for (int i = 0; i < n; i++) {
            leftProduct = (leftProduct == 0 ? 1 : leftProduct) * nums[i];
            rightProduct = (rightProduct == 0 ? 1 : rightProduct) * nums[n - 1 - i];
            maxProd = max({maxProd, leftProduct, rightProduct});
        }
        return maxProd;
    }

    // 3. Kadane’s-style for product
    int maxProductKadane(vector<int>& nums) {
        int currMax = nums[0], currMin = nums[0], result = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < 0) swap(currMax, currMin);

            currMax = max(nums[i], currMax * nums[i]);
            currMin = min(nums[i], currMin * nums[i]);

            result = max(result, currMax);
        }
        return result;
    }

    // Selector: Choose method (1, 2, or 3)
    int maxProduct(vector<int>& nums, int method = 3) {
        if (method == 1)
            return maxProductBruteForce(nums);
        else if (method == 2)
            return maxProductPrefixSuffix(nums);
        else
            return maxProductKadane(nums);  // default optimized
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 3, -2, 4, -1};

    cout << "Brute Force: " << sol.maxProduct(nums, 1) << endl;
    cout << "Prefix-Suffix: " << sol.maxProduct(nums, 2) << endl;
    cout << "Kadane Optimized: " << sol.maxProduct(nums, 3) << endl;

    return 0;
}
