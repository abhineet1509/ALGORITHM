#include <iostream>
#include <stack>
#include <string>
#include <cctype>  
using namespace std;
int evaluatePostfix(const string& exp) {
    stack<int> s;
    for (int i = 0; i < exp.length(); i++) {
        char ch = exp[i];
        if (ch == ' ') {
            continue;
        }
        if (isdigit(ch)) {
            s.push(ch - '0'); 
        }
        else {
            int val2 = s.top(); s.pop();
            int val1 = s.top(); s.pop();
            switch (ch) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
                default: 
                    cout << "Invalid operator encountered: " << ch << endl;
                    return -1;
            }
        }
    }
    return s.top();
}

int main() {
    string exp;
    cout << "Enter a postfix exp: ";
    getline(cin, exp);  //231*+9-
    int result = evaluatePostfix(exp);
    if (result != -1) {
        cout << "The result of the postfix exp is: " << result << endl;
    }
    return 0;
}
