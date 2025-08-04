#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int bruteForceDivByK(vector<int>& nums, int k) {
    int n = nums.size(), maxLen = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += nums[j];
            if (sum % k == 0)
                maxLen = max(maxLen, j - i + 1);
        }
    }
    return maxLen;
}

int optimizedDivByK(vector<int>& nums, int k) {
    unordered_map<int, int> remIndex;
    remIndex[0] = -1;
    int sum = 0, maxLen = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        int rem = ((sum % k) + k) % k;
        if (remIndex.find(rem) != remIndex.end())
            maxLen = max(maxLen, i - remIndex[rem]);
        else
            remIndex[rem] = i;
    }
    return maxLen;
}

int main() {
    vector<int> nums = {2, 7, 6, 1, 4, 5};
    int k = 3;
    cout << "Brute Force: " << bruteForceDivByK(nums, k) << endl;
    cout << "Optimized: " << optimizedDivByK(nums, k) << endl;
    return 0;
}
