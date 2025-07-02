#include <iostream>
#include <string>
#include <vector>
using namespace std;

int longestCommonSubstring(string s1, string s2) {
    int maxLen = 0;                    //tc: O(n^2 * m), sc: O(1)
    for (int i = 0; i < s1.length(); i++) {
        for (int j = i; j < s1.length(); j++) {
            string sub = s1.substr(i, j - i + 1);
            if (s2.find(sub) != string::npos) {
                maxLen = max(maxLen, j - i + 1);
            }
        }
    }
    return maxLen;
}
int longestCommonSubstring(string s1, string s2) {
    int n = s1.length(), m = s2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0)); // +1 for safe indexing
    int result = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s1[i] == s2[j]) {
                dp[i + 1][j + 1] = 1 + dp[i][j];  // shifting index by 1
                result = max(result, dp[i + 1][j + 1]);
            } // else dp[i+1][j+1] remains 0
        }
    }

    return result;
}

int main() {
    string s1 = "abcde", s2 = "abfce";
    cout << "Length of Longest Common Substring: " << longestCommonSubstring(s1, s2) << endl;
    return 0;
}