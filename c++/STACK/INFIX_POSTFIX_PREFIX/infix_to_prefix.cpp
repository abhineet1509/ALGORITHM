#include <bits/stdc++.h>
using namespace std;

int prec(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

string infixToPostfix(string s) {
    stack<char> st;
    string res;

    for (char c : s) {
      
        if (isalnum(c)) {
            res += c;
        }
        // Opening bracket
        else if (c == '(') {
            st.push(c);
        }
       
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                res += st.top();
                st.pop();
            }
            st.pop(); // remove '('
        }
        // Operator
        else {
            while (!st.empty() && prec(st.top()) > prec(c)) {
                res += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        res += st.top();
        st.pop();
    }

    return res;
}

string infixToPrefix(string infix) {
    reverse(infix.begin(), infix.end());

    // Swap brackets
    for (char &c : infix) {
        if (c == '(') c = ')';
        else if (c == ')') c = '(';
    }

    string postfix = infixToPostfix(infix);
    reverse(postfix.begin(), postfix.end());

    return postfix;
}

int main() {
    string infix;
    cin >> infix;

    cout << infixToPrefix(infix) << endl;
    return 0;
}
