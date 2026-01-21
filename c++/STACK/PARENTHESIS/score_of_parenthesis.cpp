#include <bits/stdc++.h>
using namespace std;

int scoreOfParentheses(string s) {
    stack<int> st;
    st.push(0); // base score

    for (char c : s) {
        if (c == '(')
            st.push(0); // new frame
        else {
            int v = st.top();
            st.pop();
            int top = st.top();
            st.pop();
            st.push(top + max(2 * v, 1));
        }
    }
    return st.top();
}

int main() {
    string s;
    cout << "Enter parentheses string: ";
    cin >> s;

    cout << "Score: " << scoreOfParentheses(s) << endl;
    return 0;
}
// Input: "()"      → Output: 1
// Input: "(())"    → Output: 2   (2*1)
// Input: "()()"    → Output: 2   (1+1)
// Input: "(()(()))"→ Output: 6   (2 + 2*2)