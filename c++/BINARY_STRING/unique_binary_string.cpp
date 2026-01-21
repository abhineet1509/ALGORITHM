#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
   
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string ans(n, '0');
        for (int i = 0; i < n; i++) {
            ans[i] = (nums[i][i] == '0') ? '1' : '0';
        }
        return ans;
    }
};

int main() {
    Solution sol;

    vector<string> nums1 = {"01", "10"};
    vector<string> nums2 = {"00", "01"};
    vector<string> nums3 = {"111", "011", "001"};

    cout << "Ans1: " << sol.findDifferentBinaryString(nums1) << "\n";
    cout << "Ans2: " << sol.findDifferentBinaryString(nums2) << "\n";
    cout << "Ans3: " << sol.findDifferentBinaryString(nums3) << "\n";

    return 0;
}
