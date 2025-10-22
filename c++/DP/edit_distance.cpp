#include <bits/stdc++.h>
using namespace std;

class EditDistance {
public:

    // 1️⃣ Pure Recursion
    int rec(string &a, string &b, int i, int j) {
        if (i == a.size()) return b.size() - j;
        if (j == b.size()) return a.size() - i;
        if (a[i] == b[j]) return rec(a, b, i + 1, j + 1);

        int deleteOp = 1 + rec(a, b, i + 1, j);
        int insertOp = 1 + rec(a, b, i, j + 1);
        int replaceOp = 1 + rec(a, b, i + 1, j + 1);

        return min({deleteOp, insertOp, replaceOp});
    }

    // 2️⃣ Recursion + Memoization
    int recMemo(string &a, string &b, int i, int j, vector<vector<int>> &dp) {
        if (i == a.size()) return b.size() - j;
        if (j == b.size()) return a.size() - i;
        if (dp[i][j] != -1) return dp[i][j];
        if (a[i] == b[j]) return dp[i][j] = recMemo(a, b, i + 1, j + 1, dp);

        int deleteOp = 1 + recMemo(a, b, i + 1, j, dp);
        int insertOp = 1 + recMemo(a, b, i, j + 1, dp);
        int replaceOp = 1 + recMemo(a, b, i + 1, j + 1, dp);

        return dp[i][j] = min({deleteOp, insertOp, replaceOp});
    }

    // 3️⃣ Bottom-up DP
    int bottomUp(string &a, string &b) {
        int n = a.size(), m = b.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i <= n; i++) dp[i][0] = i;
        for (int j = 0; j <= m; j++) dp[0][j] = j;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[i - 1] == b[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
            }
        }
        return dp[n][m];
    }

    // 4️⃣ Space-optimized DP
    int spaceOpt(string &a, string &b) {
        int n = a.size(), m = b.size();
        vector<int> prev(m + 1, 0), curr(m + 1, 0);

        for (int j = 0; j <= m; j++) prev[j] = j;

        for (int i = 1; i <= n; i++) {
            curr[0] = i;
            for (int j = 1; j <= m; j++) {
                if (a[i - 1] == b[j - 1])
                    curr[j] = prev[j - 1];
                else
                    curr[j] = 1 + min({prev[j], curr[j - 1], prev[j - 1]});
            }
            prev = curr;
        }
        return prev[m];
    }

    // Wrapper functions
    int minDistanceRecursion(string word1, string word2) {
        return rec(word1, word2, 0, 0);
    }

    int minDistanceMemo(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return recMemo(word1, word2, 0, 0, dp);
    }

    int minDistanceDP(string word1, string word2) {
        return bottomUp(word1, word2);
    }

    int minDistanceOptimized(string word1, string word2) {
        return spaceOpt(word1, word2);
    }
};

// Example usage:
int main() {
    EditDistance ed;
    string w1 = "horse", w2 = "ros";

    cout << "Pure Recursion: " << ed.minDistanceRecursion(w1, w2) << endl;
    cout << "Recursion + Memo: " << ed.minDistanceMemo(w1, w2) << endl;
    cout << "Bottom-up DP: " << ed.minDistanceDP(w1, w2) << endl;
    cout << "Space Optimized DP: " << ed.minDistanceOptimized(w1, w2) << endl;

    return 0;
}
