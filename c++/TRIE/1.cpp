#include <bits/stdc++.h>
using namespace std;

string minAddPalindrome(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // DP table
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;
            if (s[i] == s[j])
                dp[i][j] = dp[i + 1][j - 1];
            else
                dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j - 1]);
        }
    }

    // Construct palindrome
    int i = 0, j = n - 1;
    string left = "", right = "";

    while (i <= j) {
        if (i == j) {
            left += s[i];
            break;
        }
        if (s[i] == s[j]) {
            left += s[i];
            right += s[j];
            i++; j--;
        }
        else if (dp[i + 1][j] <= dp[i][j - 1]) {
            left += s[i];
            right += s[i];
            i++;
        }
        else {
            left += s[j];
            right += s[j];
            j--;
        }
    }

    reverse(right.begin(), right.end());
    return left + right;
}

int main() {
    string s;
    cin >> s;

    string ans = minAddPalindrome(s);
    cout << "Minimum additions: " << ans.size() - s.size() << "\n";
    cout << "Palindrome: " << ans << "\n";

    return 0;
}
