#include <bits/stdc++.h>
using namespace std;

void generateParenthesis(int n, string current, int open, int close, vector<string> &res) {
    if (current.size() == 2*n) {
        res.push_back(current);
        return;
    }
    if (open < n) generateParenthesis(n, current + '(', open + 1, close, res);
    if (close < open) generateParenthesis(n, current + ')', open, close + 1, res);
}

int main() {
    int n = 3; 
    vector<string> result;
    generateParenthesis(n, "", 0, 0, result);

    for (auto s : result) cout << s << "\n";
    return 0;
}
