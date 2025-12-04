#include <bits/stdc++.h>
using namespace std;

int numDecodings(string s) {
    int n = s.size();
    if (n == 0 || s[0] == '0') return 0;

    vector<int> dp(n + 1, 0);
    dp[0] = 1; // empty string
    dp[1] = 1; // single valid char

    for (int i = 2; i <= n; i++) {
        int one = s[i - 1] - '0';                // single digit
        int two = stoi(s.substr(i - 2, 2));      // two digits

        if (one >= 1) dp[i] += dp[i - 1];        // if valid 1–9
        if (two >= 10 && two <= 26) dp[i] += dp[i - 2]; // if valid 10–26
    }

    return dp[n];
}

int main() {
    string s;
    cout << "Enter numeric string: ";
    cin >> s;
    cout << "Number of decoding ways: " << numDecodings(s) << endl;
}
