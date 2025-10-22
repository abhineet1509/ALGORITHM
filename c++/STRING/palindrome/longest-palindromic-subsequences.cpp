#include <iostream>
#include <vector>
using namespace std;

int longestPalindromeSubseq(string s) {
    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n, 0));

   
    for (int i = 0; i < n; i++)              // tc O(n^2) sc O(n^2)
        dp[i][i] = 1;

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;

            if (s[i] == s[j]) {
                if (len == 2)
                    dp[i][j] = 2;
                else
                    dp[i][j] = 2 + dp[i+1][j-1];
            } else {
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
    }

    return dp[0][n-1];
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    int length = longestPalindromeSubseq(s);
    cout << "Length of longest palindromic subsequence: " << length << endl;
    cout << " minimum deletions/insertions to make it a palindrome: " << s.length() - length << endl;
    return 0;
}
