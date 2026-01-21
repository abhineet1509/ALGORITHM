#include <iostream>
#include <string>
#include<vector>
#include <climits>
using namespace std;                   // t.c O(2^n*n)


bool isPalindrome(const string &s, int i, int j) {
    while (i < j) {
        if (s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}

int minCuts(string s, int start) {
    if (start == s.length()) return 0; 

    int minCut = INT_MAX;

    for (int end = start; end < s.length(); end++) {
        if (isPalindrome(s, start, end)) {
            int cuts = 1 + minCuts(s, end + 1);
            minCut = min(minCut, cuts);
        }
    }

    return minCut;
}
              // tc O(n^2), sc O(n^2)
int minCut(string s) {
    int n = s.length();
    vector<vector<bool>> isPal(n, vector<bool>(n, false));
    vector<int> dp(n, 0);

    for (int i = 0; i < n; i++) {
        int minCut = i;
        for (int j = 0; j <= i; j++) {
            if (s[i] == s[j] && (i - j <= 1 || isPal[j + 1][i - 1])) {
                isPal[j][i] = true;
                minCut = (j == 0) ? 0 : min(minCut, dp[j - 1] + 1);
            }
        }
        dp[i] = minCut;
    }

    return dp[n - 1];
}
int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    // One less cut than total parts
    int result = minCuts(s, 0) - 1;
    cout << "Minimum cuts to partition into palindromes: " << result << endl;

    return 0;
}
