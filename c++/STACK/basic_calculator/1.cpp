#include <iostream>
#include <stack>
#include <string>
using namespace std;

int calculate(string s) {
    int result = 0;
    int num = 0;
    int sign = 1;
    stack<int> st;

    for (char c : s) {
        if (isdigit(c)) {
            num = num * 10 + (c - '0');
        } else if (c == '+') {
            result += sign * num;
            sign = 1;
            num = 0;
        } else if (c == '-') {
            result += sign * num;
            sign = -1;
            num = 0;
        } else if (c == '(') {
            st.push(result);
            st.push(sign);
            result = 0;
            sign = 1;
        } else if (c == ')') {
            result += sign * num;
            num = 0;
            result *= st.top(); st.pop();   // sign
            result += st.top(); st.pop();   // previous result
        }
        // Ignore spaces
    }

    // Add the last number if any
    result += sign * num;
    return result;
}

int main() {
    string expression;
    cout << "Enter expression: ";
    getline(cin, expression);

    int ans = calculate(expression);
    cout << "Result: " << ans << endl;

    return 0;
}
