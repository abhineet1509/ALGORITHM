#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLength(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
        vector<int> dp(m + 1, 0);
        int ans = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = m; j >= 1; j--) {
                if (a[i - 1] == b[j - 1]) {
                    dp[j] = dp[j - 1] + 1;
                    ans = max(ans, dp[j]);
                } else {
                    dp[j] = 0;
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 2, 3, 2, 1};
    vector<int> nums2 = {3, 2, 1, 4, 7};

    cout << sol.findLength(nums1, nums2) << endl;

    return 0;
}
