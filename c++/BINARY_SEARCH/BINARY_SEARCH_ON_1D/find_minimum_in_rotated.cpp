#include <bits/stdc++.h>
using namespace std;


int findMinRotated(vector<int>& nums) {
    int l = 0, r = nums.size() - 1;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] > nums[r])
            l = mid + 1;
        else
            r = mid;
    }
    return nums[l];
}

int findMinRotatedDup(vector<int>& nums) {
    int l = 0, r = nums.size() - 1;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] > nums[r])
            l = mid + 1;
        else if (nums[mid] < nums[r])
            r = mid;
        else
            r--; 
    }
    return nums[l];
}

int main() {
    vector<int> nums1 = {4,5,6,7,0,1,2}; // No duplicates
    vector<int> nums2 = {2,2,2,0,1,2};   // With duplicates

    cout << "Minimum (no duplicates): " << findMinRotated(nums1) << endl;   // Output: 0
    cout << "Minimum (with duplicates): " << findMinRotatedDup(nums2) << endl; // Output: 0

    return 0;
}
