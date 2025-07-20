#include <iostream>
#include <stack>
using namespace std;

int calculate(string s) {
    stack<int> st;
    int num = 0;
    char op = '+';  // previous operator
    int n = s.size();

    for (int i = 0; i < n; i++) {
        char c = s[i];

        if (isdigit(c)) {
            num = num * 10 + (c - '0');
        }

        // If it's an operator or we're at the last char, evaluate
        if ((!isdigit(c) && c != ' ') || i == n - 1) {
            if (op == '+') {
                st.push(num);
            } else if (op == '-') {
                st.push(-num);
            } else if (op == '*') {
                int prev = st.top(); st.pop();
                st.push(prev * num);
            } else if (op == '/') {
                int prev = st.top(); st.pop();
                st.push(prev / num);
            }

            op = c;
            num = 0;
        }
    }

    // Sum the stack
    int result = 0;
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    return result;
}

int main() {
    string s;
    cout << "Enter expression (only + - * /): ";
    getline(cin, s);

    int ans = calculate(s);
    cout << "Result: " << ans << endl;

    return 0;
}
