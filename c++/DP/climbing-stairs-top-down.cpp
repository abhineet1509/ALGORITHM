#include <iostream>
#include <vector>
using namespace std;
int climbStairsTopDown(int n, vector<int>& dp) {
    if (n <= 1) return 1;
    if (dp[n] != -1) return dp[n];
    dp[n] = climbStairsTopDown(n - 1, dp) + climbStairsTopDown(n - 2, dp);
    return dp[n];
}

int main() {
    int n;
    cout << "Enter number of stairs: ";
    cin >> n;
    vector<int> dp(n + 1, -1);
    cout << climbStairsTopDown(n, dp) << endl;
    return 0;
}
