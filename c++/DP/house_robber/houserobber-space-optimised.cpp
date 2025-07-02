#include <iostream>
#include <vector>
using namespace std;

int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];

    int prev2 = 0;
    int prev1 = nums[0];

    for (int i = 1; i < n; i++) {
        int pick = nums[i] + prev2;
        int skip = prev1;
        int curr = max(pick, skip);

        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}
