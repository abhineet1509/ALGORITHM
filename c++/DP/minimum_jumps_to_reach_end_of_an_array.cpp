#include <bits/stdc++.h>
using namespace std;

// ---------------- Top-Down Recursion + Memoization ----------------
int minJumpsTopDown(vector<int>& arr, int i, vector<int>& dp) {
    int n = arr.size();
    if (i >= n - 1) return 0;
    if (arr[i] == 0) return INT_MAX;
    if (dp[i] != -1) return dp[i];

    int steps = arr[i];
    int minJump = INT_MAX;
    for (int j = 1; j <= steps; j++) {
        int res = minJumpsTopDown(arr, i + j, dp);
        if (res != INT_MAX)
            minJump = min(minJump, res + 1);
    }
    return dp[i] = minJump;
}

// ---------------- Bottom-Up DP ----------------
int minJumpsBottomUp(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n, INT_MAX);
    dp[n - 1] = 0; // no jumps needed from last index

    for (int i = n - 2; i >= 0; i--) {
        int steps = arr[i];
        int minJump = INT_MAX;
        for (int j = 1; j <= steps && i + j < n; j++) {
            if (dp[i + j] != INT_MAX)
                minJump = min(minJump, 1 + dp[i + j]);
        }
        dp[i] = minJump;
    }
    return dp[0];
}

// ---------------- Greedy Approach ----------------
int minJumpsGreedy(vector<int>& arr) {
    int n = arr.size();
    if (n == 1) return 0;
    if (arr[0] == 0) return -1;

    int jumps = 1, farthest = arr[0], steps = arr[0];

    for (int i = 1; i < n; i++) {
        if (i == n - 1) return jumps;

        farthest = max(farthest, i + arr[i]);
        steps--;

        if (steps == 0) {
            jumps++;
            if (i >= farthest) return -1;
            steps = farthest - i;
        }
    }
    return -1;
}

// ---------------- Main Function ----------------
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // Top-Down
    vector<int> dpTopDown(n, -1);
    int ansTopDown = minJumpsTopDown(arr, 0, dpTopDown);
    if (ansTopDown == INT_MAX) ansTopDown = -1;

    // Bottom-Up
    int ansBottomUp = minJumpsBottomUp(arr);
    if (ansBottomUp == INT_MAX) ansBottomUp = -1;

    // Greedy
    int ansGreedy = minJumpsGreedy(arr);

    cout << "Top-Down: " << ansTopDown << endl;
    cout << "Bottom-Up: " << ansBottomUp << endl;
    cout << "Greedy: " << ansGreedy << endl;

    return 0;
}
