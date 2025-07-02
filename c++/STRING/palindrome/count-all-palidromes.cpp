#include <iostream>
#include <vector>
using namespace std;

int countSubstrings(string s) {
    int n = s.length(), count = 0;
    vector<vector<bool>> dp(n, vector<bool>(n, false));

    // Traverse from smaller to larger substrings
    for (int len = 1; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;

            if (s[i] == s[j]) {
                if (len <= 2)
                    dp[i][j] = true;
                else
                    dp[i][j] = dp[i+1][j-1];

                if (dp[i][j])
                    count++;
            }
        }
    }

    return count;
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    cout << "Total palindromic substrings: " << countSubstrings(s) << endl;
    return 0;
}
