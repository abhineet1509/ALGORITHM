#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c) {
    return c=='+' || c=='-' || c=='*' || c=='/' || c=='^';
}

string postfixToPrefix(string s) {
    stack<string> st;

    for (char c : s) {
        // Operand
        if (isalnum(c)) {
            st.push(string(1, c));
        }
        // Operator
        else if (isOperator(c)) {
            string op2 = st.top(); st.pop();
            string op1 = st.top(); st.pop();

            string expr = c + op1 + op2;
            st.push(expr);
        }
    }

    return st.top();
}

int main() {
    string postfix;
    cin >> postfix;

    cout << postfixToPrefix(postfix) << endl;
    return 0;
}
