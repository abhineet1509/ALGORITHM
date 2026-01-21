#include <bits/stdc++.h>
using namespace std;

// LPS can be found using lcs s1,s2 where s2 is reverse of s1 

int lpsTDRec(int i, int j, string &s, vector<vector<int>>& dp) {
    if (i > j) return 0;
    if (i == j) return 1;
    if (dp[i][j] != -1) return dp[i][j];

    if (s[i] == s[j])
        return dp[i][j] = 2 + lpsTDRec(i+1, j-1, s, dp);
    else
        return dp[i][j] = max(lpsTDRec(i+1, j, s, dp), lpsTDRec(i, j-1, s, dp));
}

string printLPSTD(string &s, vector<vector<int>>& dp) {
    int i = 0, j = s.size()-1;
    string left = "", right = "";
    while (i <= j) {
        if (i == j) { left += s[i]; break; }
        if (s[i] == s[j]) { left += s[i]; right += s[j]; i++; j--; }
        else if (dp[i+1][j] >= dp[i][j-1]) i++;
        else j--;
    }
    reverse(right.begin(), right.end());
    return left + right;


    // Construct palindrome
    // int i = 0, j = n - 1;
    // string left = "", right = "";

    // while (i <= j) {
    //     if (i == j) {
    //         left += s[i];
    //         break;
    //     }
    //     if (s[i] == s[j]) {
    //         left += s[i];
    //         right += s[j];
    //         i++; j--;
    //     }
    //     else if (dp[i + 1][j] <= dp[i][j - 1]) {
    //         left += s[i];
    //         right += s[i];
    //         i++;
    //     }
    //     else {
    //         left += s[j];
    //         right += s[j];
    //         j--;
    //     }
    // }

    // reverse(right.begin(), right.end());
    // return left + right;
}

string longestPalindromeSubseq(string s) {
    int n = s.size();
    string r = s;
    reverse(r.begin(), r.end());

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

  
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i - 1] == r[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

  
    int i = n, j = n;
    string lps = "";

    while (i > 0 && j > 0) {
        if (s[i - 1] == r[j - 1]) {
            lps.push_back(s[i - 1]);
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }

    reverse(lps.begin(), lps.end());
    return lps;
}

int main(){
    string s;
    cin >> s;

    // Top-Down
    vector<vector<int>> memo(s.size(), vector<int>(s.size(), -1));
    int lenTD = lpsTDRec(0, s.size()-1, s, memo);
    string lpsTD = printLPSTD(s, memo);

    cout << "Top-Down LPS Length: " << lenTD << "\n";
    cout << "Top-Down LPS String: " << lpsTD << "\n\n";

    // minimum insert/delete to make a palindrome 
    //   int lps = dp[n][n];
    // return n - lps;
}
