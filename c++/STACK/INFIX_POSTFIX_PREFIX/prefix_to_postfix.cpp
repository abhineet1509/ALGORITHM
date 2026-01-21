#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c) {
    return c=='+' || c=='-' || c=='*' || c=='/' || c=='^';
}

string prefixToPostfix(string s) {
    stack<string> st;

    for (int i = s.length() - 1; i >= 0; i--) {
        char c = s[i];

        // Operand
        if (isalnum(c)) {
            st.push(string(1, c));
        }
        // Operator
        else if (isOperator(c)) {
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();

            string expr = op1 + op2 + c;
            st.push(expr);
        }
    }

    return st.top();
}

int main() {
    string prefix;
    cin >> prefix;

    cout << prefixToPostfix(prefix) << endl;
    return 0;
}
