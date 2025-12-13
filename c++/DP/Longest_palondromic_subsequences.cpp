#include <bits/stdc++.h>
using namespace std;

// ------------------- TOP-DOWN (Memoization) -------------------
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
}

// ------------------- BOTTOM-UP (DP Table) -------------------
pair<int,string> lpsBU(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n,0));

    for (int i = n-1; i >= 0; i--) {
        dp[i][i] = 1;
        for (int j = i+1; j < n; j++) {
            if (s[i]==s[j]) dp[i][j] = 2 + dp[i+1][j-1];
            else dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
        }
    }

    // reconstruct LPS
    string left="", right="";
    int i=0,j=n-1;
    while(i<=j){
        if(i==j){ left+=s[i]; break; }
        if(s[i]==s[j]){ left+=s[i]; right+=s[j]; i++; j--; }
        else if(dp[i+1][j]>=dp[i][j-1]) i++;
        else j--;
    }
    reverse(right.begin(), right.end());
    return {dp[0][n-1], left+right};
}

// ------------------- MAIN -------------------
int main(){
    string s;
    cin >> s;

    // Top-Down
    vector<vector<int>> memo(s.size(), vector<int>(s.size(), -1));
    int lenTD = lpsTDRec(0, s.size()-1, s, memo);
    string lpsTD = printLPSTD(s, memo);

    cout << "Top-Down LPS Length: " << lenTD << "\n";
    cout << "Top-Down LPS String: " << lpsTD << "\n\n";

    // Bottom-Up
    auto res = lpsBU(s);
    cout << "Bottom-Up LPS Length: " << res.first << "\n";
    cout << "Bottom-Up LPS String: " << res.second << "\n";
}
