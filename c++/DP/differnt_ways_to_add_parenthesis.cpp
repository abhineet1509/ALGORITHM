#include <bits/stdc++.h>
using namespace std;

// Memoization map: expression string -> all possible results
unordered_map<string, vector<int>> dp;

vector<int> diffWaysToCompute(string expression) {
    // If already computed, return from DP
    if (dp.count(expression)) return dp[expression];

    vector<int> result;
    for (int i = 0; i < expression.size(); i++) {
        char c = expression[i];
        if (c == '+' || c == '-' || c == '*') {
            string left = expression.substr(0, i);
            string right = expression.substr(i + 1);

            vector<int> leftResults = diffWaysToCompute(left);
            vector<int> rightResults = diffWaysToCompute(right);

            for (int l : leftResults) {
                for (int r : rightResults) {
                    if (c == '+') result.push_back(l + r);
                    else if (c == '-') result.push_back(l - r);
                    else if (c == '*') result.push_back(l * r);
                }
            }
        }
    }

    // Base case: if expression has no operator
    if (result.empty()) result.push_back(stoi(expression));

    // Save result in DP
    dp[expression] = result;
    return result;
}

int main() {
    string expr = "2*3-4*5";
    vector<int> res = diffWaysToCompute(expr);

    cout << "Different results: ";
    for (int val : res) cout << val << " ";
    cout << endl;

    return 0;
}
