#include <iostream>
#include <vector>
using namespace std;

vector<int> maxSlidingWindowBrute(vector<int>& nums, int k) {
    vector<int> res;

    for (int i = 0; i <= nums.size() - k; i++) {
        int maxVal = nums[i];
        for (int j = i + 1; j < i + k; j++) {
            maxVal = max(maxVal, nums[j]);
        }
        res.push_back(maxVal);
    }

    return res;
}

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> result = maxSlidingWindowBrute(nums, k);

    for (int x : result) cout << x << " ";
    return 0;
}
