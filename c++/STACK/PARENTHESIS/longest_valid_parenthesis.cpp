#include<bits/stdc++.h>
using namespace std;


#include <bits/stdc++.h>
using namespace std;

int longestValidParenthesesStack(const string &s) {
    int maxLen = 0;
    stack<int> st;
    st.push(-1); // base for current valid substring
    for (int i = 0; i < (int)s.size(); ++i) {
        if (s[i] == '(') {
            st.push(i);
        } else {
            st.pop();
            if (st.empty()) {
                st.push(i); // mark new base
            } else {
                maxLen = max(maxLen, i - st.top());
            }
        }
    }
    return maxLen;
}

int main() {
    vector<string> tests = {"(()", ")()())", "", "()(())", "(()())", "))((())"};
    for (auto &t : tests) {
        cout << "stack: " << longestValidParenthesesStack(t) << "\n";
    }
    return 0;
}
