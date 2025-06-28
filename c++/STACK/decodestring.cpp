#include <iostream>
#include <stack>
using namespace std;

string decodeString(string s) {
    stack<int> countStack;
    stack<string> strStack;
    string curr = "";
    int k = 0;

    for (char ch : s) {
        if (isdigit(ch)) {
            k = k * 10 + (ch - '0');
        } else if (ch == '[') {
            countStack.push(k);
            strStack.push(curr);
            k = 0;
            curr = "";
        } else if (ch == ']') {
            string temp = curr;
            curr = strStack.top(); strStack.pop();
            int count = countStack.top(); countStack.pop();
            while (count--) curr += temp;
        } else {
            curr += ch;
        }
    }
    return curr;
}

int main() {
    string input = "3[a2[c]]";
    cout << decodeString(input) << endl;
    return 0;
}
