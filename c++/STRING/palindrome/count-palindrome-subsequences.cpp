#include <iostream>
#include <vector>
using namespace std;

int countPalindromicSubsequences(string s) {
    int n = s.length();
    vector<vector<long long>> dp(n, vector<long long>(n, 0));

    // All substrings of length 1 are palindromes
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;

            if (s[i] == s[j]) {
                dp[i][j] = dp[i+1][j] + dp[i][j-1] + 1;
            } else {
                dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1];
            }
        }
    }

    return dp[0][n - 1];
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    cout << "Total Palindromic Subsequences: " << countPalindromicSubsequences(s) << endl;
    return 0;
}

