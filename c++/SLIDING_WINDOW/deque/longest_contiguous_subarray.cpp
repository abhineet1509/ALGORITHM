#include <bits/stdc++.h>
using namespace std;

pair<int, vector<int>> longestContiguousSubarray(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return {0, {}};

    int maxLen = 1;
    int startIdx = 0;

    for (int i = 0; i < n; i++) {
        int minVal = nums[i], maxVal = nums[i];
        for (int j = i; j < n; j++) {
            minVal = min(minVal, nums[j]);
            maxVal = max(maxVal, nums[j]);
            if (maxVal - minVal > 1) break;
            if (j - i + 1 > maxLen) {
                maxLen = j - i + 1;
                startIdx = i;
            }
        }
    }

    vector<int> subarray(nums.begin() + startIdx, nums.begin() + startIdx + maxLen);
    return {maxLen, subarray};
}


int findMaxLength(vector<int>& nums) {
    unordered_map<int, int> prefixMap; // prefixSum -> first index
    prefixMap[0] = -1; // base case
    int maxLen = 0, prefixSum = 0;

    for (int i = 0; i < nums.size(); i++) {
        prefixSum += (nums[i] == 1 ? 1 : -1);

        if (prefixMap.find(prefixSum) != prefixMap.end()) {
            maxLen = max(maxLen, i - prefixMap[prefixSum]);
        } else {
            prefixMap[prefixSum] = i;
        }
    }

    return maxLen;
}

int main() {
    vector<int> nums = {1, 2, 2, 1, 2, 3, 2};
    pair<int, vector<int>> result = longestContiguousSubarray(nums);

    cout << "Length: " << result.first << endl;
    cout << "Subarray: ";
    for (int x : result.second) cout << x << " ";
    cout << endl;

    return 0;
}
