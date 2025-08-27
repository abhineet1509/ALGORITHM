#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int dp[101][10001]; // dp[eggs][floors]

    int solve(int eggs, int floors) {
        if (floors == 0 || floors == 1) return floors;
        if (eggs == 1) return floors;

        if (dp[eggs][floors] != -1) return dp[eggs][floors];

        int low = 1, high = floors;
        int ans = INT_MAX;

        while (low <= high) {
            int mid = (low + high) / 2;

            int breakCase = solve(eggs - 1, mid - 1);
            int notBreakCase = solve(eggs, floors - mid);
            int worst = 1 + max(breakCase, notBreakCase);

            if (breakCase < notBreakCase)
                low = mid + 1;
            else
                high = mid - 1;

            ans = min(ans, worst);
        }

        return dp[eggs][floors] = ans;
    }

    int superEggDrop(int k, int n) {
        for (int i = 0; i <= k; i++) {
            for (int j = 0; j <= n; j++) {
                dp[i][j] = -1;
            }
        }
        return solve(k, n);
    }
};

int main() {
    int eggs = 2;
    int floors = 10;

    Solution sol;
    int result = sol.superEggDrop(eggs, floors);
    cout << "Minimum attempts needed: " << result << endl;

    return 0;
}
