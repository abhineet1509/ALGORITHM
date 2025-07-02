#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int dp[1001][1001];

int lcsTopDown(string &s1, string &s2, int i, int j) {
    if (i == 0 || j == 0) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    if (s1[i-1] == s2[j-1])
        return dp[i][j] = 1 + lcsTopDown(s1, s2, i-1, j-1);
    return dp[i][j] = max(lcsTopDown(s1, s2, i-1, j), lcsTopDown(s1, s2, i, j-1));
}

int main() {
    string s1 = "abcde", s2 = "ace";
    memset(dp, -1, sizeof(dp));
    int result = lcsTopDown(s1, s2, s1.length(), s2.length());
    cout << "LCS length (Top-Down): " << result << endl;
    return 0;
}
