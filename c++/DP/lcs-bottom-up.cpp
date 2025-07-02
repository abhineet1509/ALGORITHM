#include <iostream>
#include <vector>
using namespace std;

int lcsBottomUp(string s1, string s2) {
    int n = s1.length(), m = s2.length();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i-1] == s2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][m];
}

int main() {
    string s1 = "abcde", s2 = "ace";
    int result = lcsBottomUp(s1, s2);
    cout << "LCS length (Bottom-Up): " << result << endl;
    return 0;
}
