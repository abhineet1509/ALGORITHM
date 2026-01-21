#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsertBinary(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }

        // left is the correct insertion position
        return left;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 3, 5, 6};

    vector<int> targets = {5, 2, 7, 0};

    for (int target : targets) {
        cout << "Target " << target 
             << " → Insert Position: " 
             << sol.searchInsertBinary(nums, target) << endl;
    }

    return 0;
}
