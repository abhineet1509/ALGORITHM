#include <iostream>
#include <vector>
using namespace std;

void cyclicSort(vector<int>& nums) {
    int i = 0, n = nums.size();
    while (i < n) {
        if (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1])
            swap(nums[i], nums[nums[i] - 1]);
        else
            i++;  
    }
}

int main() {
    vector<int> nums = {3, 5, 2, 1, 4};
    cyclicSort(nums);
    for (int num : nums) cout << num << " ";
}
