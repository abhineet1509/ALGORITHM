#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return n;

        int up = 1, down = 1;

        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                up = down + 1;
            } 
            else if (nums[i] < nums[i - 1]) {
                down = up + 1;
            }
            // equal case → ignore
        }
        return max(up, down);
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 7, 4, 9, 2, 5};
    vector<int> nums2 = {1, 17, 5, 10, 13, 15, 10, 5, 16, 8};
    vector<int> nums3 = {1, 1, 1, 1};

    cout << sol.wiggleMaxLength(nums1) << endl; // 6
    cout << sol.wiggleMaxLength(nums2) << endl; // 7
    cout << sol.wiggleMaxLength(nums3) <<
