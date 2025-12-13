#include <bits/stdc++.h>
using namespace std;

// ------------------ Jump Game I (Reach or Not) ------------------

// Top-Down DP
bool canReachTopDown(int i, vector<int> &nums, vector<int> &dp) {
    int n = nums.size();
    if (i >= n-1) return true;
    if (dp[i] != -1) return dp[i];

    for (int step = 1; step <= nums[i]; step++) {
        if (canReachTopDown(i + step, nums, dp))
            return dp[i] = true;
    }
    return dp[i] = false;
}
bool canJumpTopDown(vector<int> &nums) {
    vector<int> dp(nums.size(), -1);
    return canReachTopDown(0, nums, dp);
}

// Bottom-Up DP
bool canJumpBottomUp(vector<int> &nums) {
    int n = nums.size();
    vector<bool> dp(n, false);
    dp[0] = true;

    for (int i = 0; i < n; i++) {
        if (!dp[i]) continue;
        for (int j = 1; j <= nums[i] && i + j < n; j++)
            dp[i+j] = true;
    }
    return dp[n-1];
}

// Greedy (Optimal)
bool canJumpGreedy(vector<int> &nums) {
    int reach = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (i > reach) return false;
        reach = max(reach, i + nums[i]);
    }
    return true;
}

// ------------------ Jump Game II (Min Jumps) ------------------

// Top-Down DP
int minJumpsTD(int i, vector<int> &nums, vector<int> &dp) {
    int n = nums.size();
    if (i >= n-1) return 0;
    if (dp[i] != -1) return dp[i];

    int ans = 1e9;
    for (int step = 1; step <= nums[i]; step++)
        ans = min(ans, 1 + minJumpsTD(i + step, nums, dp));
    return dp[i] = ans;
}
int jumpTopDown(vector<int> &nums) {
    vector<int> dp(nums.size(), -1);
    return minJumpsTD(0, nums, dp);
}

// Bottom-Up DP
int jumpBottomUp(vector<int> &nums) {
    int n = nums.size();
    vector<int> dp(n, 1e9);
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= nums[i] && i + j < n; j++)
            dp[i + j] = min(dp[i + j], dp[i] + 1);
    }
    return dp[n-1];
}

// Greedy (Optimal)
int jumpGreedy(vector<int> &nums) {
    int jumps = 0, currEnd = 0, farthest = 0;

    for (int i = 0; i < nums.size() - 1; i++) {
        farthest = max(farthest, i + nums[i]);
        if (i == currEnd) {
            jumps++;
            currEnd = farthest;
        }
    }
    return jumps;
}

// ------------------ Test in main ------------------
int main() {
    vector<int> nums = {2,3,1,1,4};

    cout << "--- Jump Game I (Reach?) ---\n";
    cout << "Top-Down : " << (canJumpTopDown(nums) ? "Yes" : "No") << "\n";
    cout << "Bottom-Up: " << (canJumpBottomUp(nums) ? "Yes" : "No") << "\n";
    cout << "Greedy   : " << (canJumpGreedy(nums) ? "Yes" : "No") << "\n\n";

    cout << "--- Jump Game II (Min Jumps) ---\n";
    cout << "Top-Down : " << jumpTopDown(nums) << "\n";
    cout << "Bottom-Up: " << jumpBottomUp(nums) << "\n";
    cout << "Greedy   : " << jumpGreedy(nums) << "\n";

    return 0;
}
