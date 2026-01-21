#include <bits/stdc++.h>
using namespace std;

/* Rotated Array I — No Duplicates */
int searchRotated(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] == target) return mid;

        if (nums[l] <= nums[mid]) { // left half sorted
            if (nums[l] <= target && target < nums[mid])
                r = mid - 1;
            else
                l = mid + 1;
        } else { // right half sorted
            if (nums[mid] < target && target <= nums[r])
                l = mid + 1;
            else
                r = mid - 1;
        }
    }
    return -1;
}

/* Rotated Array II — With Duplicates */
bool searchRotatedDup(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] == target) return true;

        if (nums[l] == nums[mid] && nums[mid] == nums[r]) {
            l++; r--; // skip duplicates
        } else if (nums[l] <= nums[mid]) {
            if (nums[l] <= target && target < nums[mid])
                r = mid - 1;
            else
                l = mid + 1;
        } else {
            if (nums[mid] < target && target <= nums[r])
                l = mid + 1;
            else
                r = mid - 1;
        }
    }
    return false;
}

int main() {
    vector<int> nums1 = {4,5,6,7,0,1,2};
    int target1 = 0;

    vector<int> nums2 = {2,5,6,0,0,1,2};
    int target2 = 0;

    searchRotated(nums1, target1);
    searchRotatedDup(nums2, target2);

    return 0;
}
