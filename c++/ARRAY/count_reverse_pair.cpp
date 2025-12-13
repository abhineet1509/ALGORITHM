#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mergeSort(vector<int>& nums, int left, int right) {
        if(left >= right) return 0;
        int mid = left + (right-left)/2;
        int cnt = mergeSort(nums, left, mid) + mergeSort(nums, mid+1, right);

        // Count reverse pairs
        int j = mid + 1;
        for(int i = left; i <= mid; i++) {
            while(j <= right && (long long)nums[i] > 2LL * nums[j]) j++;
            cnt += (j - mid - 1);
        }

        // Merge two sorted halves
        vector<int> temp;
        int i = left; j = mid + 1;
        while(i <= mid && j <= right) temp.push_back(nums[i] <= nums[j] ? nums[i++] : nums[j++]);
        while(i <= mid) temp.push_back(nums[i++]);
        while(j <= right) temp.push_back(nums[j++]);
        for(int k = left; k <= right; k++) nums[k] = temp[k-left];

        return cnt;
    }

    int countReversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }
};

int main() {
    vector<int> arr = {3, 2, 4, 5, 1, 20};
    Solution sol;
    cout << sol.countReversePairs(arr) << endl; // Output: 3
}
