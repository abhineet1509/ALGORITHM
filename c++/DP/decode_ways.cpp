#include <bits/stdc++.h>
using namespace std;

int solveTD(int i, string &s, vector<int> &dp) {
    if (i == s.size()) return 1;
    if (s[i] == '0') return 0;
    if (dp[i] != -1) return dp[i];

    int ways = solveTD(i + 1, s, dp);

    if (i + 1 < s.size()) {
        int num = (s[i] - '0') * 10 + (s[i + 1] - '0');
        if (num <= 26) ways += solveTD(i + 2, s, dp);
    }
    return dp[i] = ways;
}

int solveBU(string s) {
    int n = s.size();
    vector<int> dp(n + 1);
    dp[n] = 1;

    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '0') dp[i] = 0;
        else {
            dp[i] = dp[i + 1];
            if (i + 1 < n) {
                int num = (s[i] - '0') * 10 + (s[i + 1] - '0');
                if (num <= 26) dp[i] += dp[i + 2];
            }
        }
    }
    return dp[0];
}

int main() {
    string s;
    cin >> s;

    vector<int> dp(s.size(), -1);
    cout << "TopDown: " << solveTD(0, s, dp) << endl;
    cout << "BottomUp: " << solveBU(s) << endl;
}
