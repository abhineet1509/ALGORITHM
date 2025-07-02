#include <iostream>
#include <vector>
using namespace std;

int robRec(int n, vector<int>& nums) {
    if (n == 0) return nums[0];
    if (n < 0) return 0;

    int pick = nums[n] + robRec(n - 2, nums);
    int skip = robRec(n - 1, nums);

    return max(pick, skip);
}

int rob(vector<int>& nums) {
    int n = nums.size();
    return robRec(n - 1, nums);
}
int main() {
    vector<int> nums = {2, 7, 9, 3, 1};
    cout << "Maximum amount that can be robbed: " << rob(nums) << endl;
    return 0;
}