#include <iostream>
#include <vector>
using namespace std;

// Linear House Robber (optimized)
int rob_linear(vector<int>& nums, int start, int end) {
    int prev2 = 0, prev1 = 0;

    for (int i = start; i <= end; i++) {
        int pick = nums[i] + prev2;
        int skip = prev1;
        int curr = max(pick, skip);
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

// House Robber II main function
int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];

    // Two cases: exclude first or last house
    int option1 = rob_linear(nums, 0, n - 2);
    int option2 = rob_linear(nums, 1, n - 1);

    return max(option1, option2);
}

int main() {
    vector<int> nums = {2, 3, 2}; // Example
    cout << "Max money: " << rob(nums) << endl;
}
