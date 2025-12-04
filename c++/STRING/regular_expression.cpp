#include <bits/stdc++.h>
using namespace std;

/* =========================
   Regular Expression Matching
   ========================= */
bool isMatchRegex(string s, string p) {
    int n = s.size(), m = p.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
    dp[0][0] = true;

    // Deals with patterns like a*, a*b*, a*b*c*
    for (int j = 2; j <= m; j++)
        if (p[j - 1] == '*')
            dp[0][j] = dp[0][j - 2];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (p[j - 1] == '.' || p[j - 1] == s[i - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else if (p[j - 1] == '*') {
                dp[i][j] = dp[i][j - 2]; // zero occurrence
                if (p[j - 2] == '.' || p[j - 2] == s[i - 1])
                    dp[i][j] = dp[i][j] || dp[i - 1][j]; // one or more
            }
        }
    }
    return dp[n][m];
}

/* =========================
   Wildcard Matching
   ========================= */
bool isMatchWildcard(string s, string p) {
    int n = s.size(), m = p.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
    dp[0][0] = true;

    // Leading '*' can match empty
    for (int j = 1; j <= m; j++)
        if (p[j - 1] == '*')
            dp[0][j] = dp[0][j - 1];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (p[j - 1] == s[i - 1] || p[j - 1] == '?')
                dp[i][j] = dp[i - 1][j - 1];
            else if (p[j - 1] == '*')
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
        }
    }
    return dp[n][m];
}

/* =========================
   Main Function
   ========================= */
int main() {
    string s, p;

    cout << "Enter string: ";
    cin >> s;
    cout << "Enter pattern: ";
    cin >> p;

    cout << "\nRegular Expression Matching (. and *): ";
    cout << (isMatchRegex(s, p) ? "Match" : "No Match") << endl;

    cout << "Wildcard Matching (? and *): ";
    cout << (isMatchWildcard(s, p) ? "Match" : "No Match") << endl;

    return 0;
}
