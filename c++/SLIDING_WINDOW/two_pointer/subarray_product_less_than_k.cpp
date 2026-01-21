#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0; 
        int left = 0, count = 0;
        long long product = 1;
        for (int right = 0; right < nums.size(); ++right) {
            product *= nums[right];
            while (product >= k) {
                product /= nums[left];
                left++;
            }
            count += (right - left + 1);
        }
        return count;
    }
};

// Example usage
int main() {
    Solution sol;
    vector<int> nums = {10, 5, 2, 6};
    int k = 100;
    cout << sol.numSubarrayProductLessThanK(nums, k) << endl; // Output: 8
    return 0;
}
