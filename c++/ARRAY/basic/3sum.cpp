#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    int n = nums.size();

    for (int mid = 1; mid < n-1; mid++) {
        int left = 0;
        int right = n - 1;

        while (left < mid && right > mid) {
            int total = nums[left] + nums[mid] + nums[right];

            if (total == 0) {
                result.push_back({nums[left], nums[mid], nums[right]});

                while (left < mid && nums[left] == nums[left+1]) left++;
                while (right > mid && nums[right] == nums[right-1]) right--;

                left++;
                right--;
            }
            else if (total < 0) {
                left++;
            }
            else {
                right--;
            }
        }
    }

    // Remove duplicates triplets
    sort(result.begin(), result.end());
    result.erase(unique(result.begin(), result.end()), result.end());

    return result;
}

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> triplets = threeSum(nums);

    cout << "Triplets that sum to 0:\n";
    for (auto &t : triplets) {
        for (int x : t) cout << x << " ";
        cout << "\n";
    }

    return 0;
}
