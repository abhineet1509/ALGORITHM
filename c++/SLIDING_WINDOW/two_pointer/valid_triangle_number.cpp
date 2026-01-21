#include <bits/stdc++.h>
using namespace std;

int triangleNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int count = 0;

    for (int i = n - 1; i >= 2; i--) {
        int left = 0, right = i - 1;
        while (left < right) {
            if (nums[left] + nums[right] > nums[i]) {
                count += (right - left);
                right--;
            } else {
                left++;
            }
        }
    }

    return count;
}

int main() {
    vector<int> nums = {2, 2, 3, 4};
    cout << triangleNumber(nums) << endl; // Output: 3
    return 0;
}
