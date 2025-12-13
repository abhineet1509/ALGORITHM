#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> ans;

    // remove extra `close` parentheses first (close = ')', open = '(')
    void removeInvalid(string s, int last_i, int last_j, char open, char close) {
        int balance = 0;

        for (int i = last_i; i < s.size(); i++) {
            if (s[i] == open) balance++;
            if (s[i] == close) balance--;

            if (balance >= 0) continue; // too many close? no → continue

            // extra close found
            for (int j = last_j; j <= i; j++) {
                if (s[j] == close && (j == last_j || s[j - 1] != close)) {
                    removeInvalid(s.substr(0, j) + s.substr(j + 1), i, j, open, close);
                }
            }
            return; // stop here, deeper recursion handles fixes
        }

        // now string is valid in this direction
        string rev = s;
        reverse(rev.begin(), rev.end());

        if (open == '(') {
            // now remove extra '(' in reversed string
            removeInvalid(rev, 0, 0, ')', '(');
        } else {
            // both passes done → string is fully valid
            ans.push_back(rev);
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        removeInvalid(s, 0, 0, '(', ')');
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution sol;
    string s; 
    cin >> s;
    vector<string> res = sol.removeInvalidParentheses(s);
    for (auto &x : res) cout << x << " ";
    return 0;
}
