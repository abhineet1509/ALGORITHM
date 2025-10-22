#include <bits/stdc++.h>
using namespace std;

// ---------------- Recursive Solution ----------------
class RecursiveSolution {
public:
    bool isMatch(string s, string p) {
        return helper(s, p, 0, 0);
    }

private:
    bool helper(const string &s, const string &p, int i, int j) {
        if (j == p.size()) return i == s.size();

        bool first_match = (i < s.size() && (s[i] == p[j] || p[j] == '.'));

        if (j + 1 < p.size() && p[j+1] == '*') {
            return helper(s, p, i, j+2) || (first_match && helper(s, p, i+1, j));
        } else {
            return first_match && helper(s, p, i+1, j+1);
        }
    }
};

// ---------------- DP Solution ----------------
class DPSolution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[0][0] = true;

        for (int j = 1; j <= n; j++) {
            if (p[j-1] == '*')
                dp[0][j] = dp[0][j-2];
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j-1] == s[i-1] || p[j-1] == '.') {
                    dp[i][j] = dp[i-1][j-1];
                } else if (p[j-1] == '*') {
                    dp[i][j] = dp[i][j-2];
                    if (p[j-2] == s[i-1] || p[j-2] == '.')
                        dp[i][j] = dp[i][j] || dp[i-1][j];
                }
            }
        }

        return dp[m][n];
    }
};

// ---------------- Main Function ----------------
int main() {
    string s, p;
    cout << "Enter string: ";
    cin >> s;
    cout << "Enter pattern: ";
    cin >> p;

    cout << "\nChoose method:\n";
    cout << "1. Recursive Solution\n";
    cout << "2. Dynamic Programming Solution\n";
    cout << "Enter choice: ";
    int choice; cin >> choice;

    bool result = false;
    if (choice == 1) {
        RecursiveSolution rec;
        result = rec.isMatch(s, p);
    } else if (choice == 2) {
        DPSolution dp;
        result = dp.isMatch(s, p);
    } else {
        cout << "Invalid choice.\n";
        return 0;
    }

    cout << (result ? "\n✅ Match!\n" : "\n❌ No Match.\n");
    return 0;
}
