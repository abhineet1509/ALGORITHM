#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
using namespace std;

int dp[101][10001];

int solve(int eggs, int floors) {
    if (floors == 0 || floors == 1) return floors;
    if (eggs == 1) return floors;

    if (dp[eggs][floors] != -1) return dp[eggs][floors];

    int ans = INT_MAX;

    // Binary search optimization
    int low = 1, high = floors;
    while (low <= high) {
        int mid = (low + high) / 2;
        int break_case = solve(eggs - 1, mid - 1);    // Egg breaks
        int not_break = solve(eggs, floors - mid);    // Egg doesn't break
        int temp = 1 + max(break_case, not_break);

        if (break_case > not_break)
            high = mid - 1;
        else
            low = mid + 1;

        ans = min(ans, temp);
    }

    return dp[eggs][floors] = ans;
}

int main() {
    int eggs = 2, floors = 10;
    memset(dp, -1, sizeof(dp));
    cout << "Minimum attempts: " << solve(eggs, floors) << endl;
    return 0;
}
