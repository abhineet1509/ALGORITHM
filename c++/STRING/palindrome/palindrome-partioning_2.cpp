#include <iostream>
#include <vector>
#include <string>
using namespace std;
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
    cout << "Minimum cuts needed: " << minCut(s) << endl;
    return 0;
}
