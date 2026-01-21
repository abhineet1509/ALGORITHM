#include <bits/stdc++.h>
using namespace std;

/*--------------------------------------------------
  1. RECURSION (Brute Force)
--------------------------------------------------*/
bool solveRec(int i, int open, string &s) {
    if (open < 0) return false;
    if (i == s.size()) return open == 0;

    if (s[i] == '(')
        return solveRec(i + 1, open + 1, s);
    else if (s[i] == ')')
        return solveRec(i + 1, open - 1, s);
    else
        return solveRec(i + 1, open + 1, s) ||
               solveRec(i + 1, open - 1, s) ||
               solveRec(i + 1, open, s);
}

bool checkValidStringRec(string s) {
    return solveRec(0, 0, s);
}

/*--------------------------------------------------
  2. DP (Memoization)
--------------------------------------------------*/
bool solveDP(int i, int open, string &s, vector<vector<int>> &dp) {
    if (open < 0) return false;
    if (i == s.size()) return open == 0;

    if (dp[i][open] != -1) return dp[i][open];

    bool res;
    if (s[i] == '(')
        res = solveDP(i + 1, open + 1, s, dp);
    else if (s[i] == ')')
        res = solveDP(i + 1, open - 1, s, dp);
    else
        res = solveDP(i + 1, open + 1, s, dp) ||
              solveDP(i + 1, open - 1, s, dp) ||
              solveDP(i + 1, open, s, dp);

    return dp[i][open] = res;
}

bool checkValidStringDP(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return solveDP(0, 0, s, dp);
}

/*--------------------------------------------------
  3. STACK APPROACH
--------------------------------------------------*/
bool checkValidStringStack(string s) {
    stack<int> open, star;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(')
            open.push(i);
        else if (s[i] == '*')
            star.push(i);
        else {
            if (!open.empty()) open.pop();
            else if (!star.empty()) star.pop();
            else return false;
        }
    }

    while (!open.empty()) {
        if (star.empty()) return false;
        if (open.top() > star.top()) return false;
        open.pop();
        star.pop();
    }
    return true;
}

/*--------------------------------------------------
  4. MOST OPTIMISED (Two Pointer / Greedy)
--------------------------------------------------*/
bool checkValidStringGreedy(string s) {
    int low = 0, high = 0;

    for (char c : s) {
        if (c == '(') {
            low++; high++;
        } else if (c == ')') {
            low--; high--;
        } else {
            low--; high++;
        }

        if (high < 0) return false;
        low = max(low, 0);
    }
    return low == 0;
}

/*--------------------------------------------------
  MAIN FUNCTION
--------------------------------------------------*/
int main() {
    string s;
    cin >> s;

    cout << "Recursion: " 
         << checkValidStringRec(s) << endl;

    cout << "DP: " 
         << checkValidStringDP(s) << endl;

    cout << "Stack: " 
         << checkValidStringStack(s) << endl;

    cout << "Greedy (Most Optimised): " 
         << checkValidStringGreedy(s) << endl;

    return 0;
}
