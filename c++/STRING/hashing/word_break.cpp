#include <bits/stdc++.h>
using namespace std;

class DPSolution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; i++) {                              
            for (int j = 0; j < i; j++) {
                if (dp[j] && st.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};
//  n (outer)
// × n (inner)
// × n (substr copy)
// = O(n³)

class RecursiveSolution {
public:
    bool solve(int start, string &s, unordered_set<string>& st, vector<int>& dp) {
        if (start == s.size()) return true;
        if (dp[start] != -1) return dp[start];
        for (int end = start + 1; end <= s.size(); end++) {
            if (st.count(s.substr(start, end - start)) && solve(end, s, st, dp))
                return dp[start] = true;
        }
        return dp[start] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        vector<int> dp(s.size(), -1);
        return solve(0, s, st, dp);
    }
};

int main() {
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    DPSolution dp;
    RecursiveSolution rec;
    cout << (dp.wordBreak(s, wordDict) ? "True" : "False") << endl;
    cout << (rec.wordBreak(s, wordDict) ? "True" : "False") << endl;
}
// s = "leetcode"
// wordDict = ["leet", "code", "le", "etc", "ode", "cat", "dog"]
// Output: true
// s = "leetcoode"
// wordDict = ["leet", "code"]
// Output: false
