#include <iostream>
#include <stack>
using namespace std;

 string decodeString(string s) {
        stack<string> st;
        stack<int> num;
        string curr = "";
        int k = 0;

        for (char c : s) {
            if (isdigit(c)) {
                k = k * 10 + (c - '0');  // number can also be 19 , 15
            }
            else if (c == '[') {
                num.push(k);           // 3 -> 2 , ""->"a"
                st.push(curr);
                k = 0;
                curr = "";
            }
            else if (c == ']') {
                int repeat = num.top(); num.pop();  
                string prev = st.top(); st.pop();

                while (repeat--) prev += curr;
                curr = prev;
            }
            else {
                curr += c;
            }
        }
        return curr;
    }

int main() {
    string input = "3[a2[c]]";
    cout << decodeString(input) << endl;
    return 0;
}
