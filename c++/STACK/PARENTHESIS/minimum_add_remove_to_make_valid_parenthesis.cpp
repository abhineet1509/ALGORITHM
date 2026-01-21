#include <bits/stdc++.h>
using namespace std;

// ------------ LeetCode 921 -------------
int minAddToMakeValid(string s) {
    int balance = 0, add = 0;
    for (char c : s) {
        if (c == '(') {
            balance++;
        } else {
            if (balance == 0) {
                add++;
            } else {
                balance--;
            }
        }
    }
    return add + balance;
}

// ------------ LeetCode 1249 -------------
string minRemoveToMakeValid(string s) {
    int n = s.size();
    vector<bool> keep(n, true);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            st.push(i);
        } else if (s[i] == ')') {
            if (!st.empty()) {
                st.pop();
            } else {
                keep[i] = false;
            }
        }
    }

    while (!st.empty()) {
        keep[st.top()] = false;
        st.pop();
    }

    string result;
    for (int i = 0; i < n; i++) {
        if (keep[i]) result.push_back(s[i]);
    }
    return result;
}

int minSwaps(string s) {
        int balance = 0, maxImbalance = 0;
        for (char c : s) {
            if (c == '[') balance++;
            else balance--;
            maxImbalance = min(maxImbalance, balance);
        }
        return (-maxImbalance + 1) / 2;
    }
    
int main() {
    // Test for 921
    string s1 = "((())";
    cout << "921 Input: " << s1 << "\n";
    cout << "Minimum additions needed: " << minAddToMakeValid(s1) << "\n\n";

    // Test for 1249
    string s2 = "a)b(c)d";
    cout << "1249 Input: " << s2 << "\n";
    cout << "Valid parentheses result: " << minRemoveToMakeValid(s2) << "\n";

    return 0;
}
