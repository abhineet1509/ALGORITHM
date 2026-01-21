#include <bits/stdc++.h>
using namespace std;

int partitionDisjoint(vector<int>& nums) {
    int leftMax = nums[0];
    int currMax = nums[0];
    int partitionIdx = 0;

    for (int i = 1; i < nums.size(); i++) {
        currMax = max(currMax, nums[i]);

        if (nums[i] < leftMax) {
            leftMax = currMax;
            partitionIdx = i;
        }
    }
    return partitionIdx + 1;
}

int main() {
    vector<int> nums = {5,0,3,8,6};
    cout << partitionDisjoint(nums); // Output: 3
    return 0;
}
