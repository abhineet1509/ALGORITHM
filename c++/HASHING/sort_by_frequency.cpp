#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> freq;
        for (int x : nums) freq[x]++;

        sort(nums.begin(), nums.end(), [&](int a, int b) {
            if (freq[a] == freq[b])
                return a > b;          // same freq → larger first
            return freq[a] < freq[b]; // smaller freq first
        });

        return nums;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {1,1,2,2,2,3};

    vector<int> res = obj.frequencySort(nums);
    for (int x : res) cout << x << " ";
    return 0;
}
