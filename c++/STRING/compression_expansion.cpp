#include <bits/stdc++.h>
using namespace std;

// Compress: "aabccc" -> "a2b1c3"
string compressString(const string &s) {
    stack<pair<char, int>> st;

    for (char ch : s) {
        if (!st.empty() && st.top().first == ch)
            st.top().second++;
        else
            st.push({ch, 1});
    }

    string res = "";
    stack<pair<char, int>> temp;
    while (!st.empty()) {
        temp.push(st.top());
        st.pop();
    }

    while (!temp.empty()) {
        res += temp.top().first;
        res += to_string(temp.top().second);
        temp.pop();
    }
    return res;
}

// Expand: "a2b1c3" -> "aabccc"
string expandString(const string &s) {
    stack<char> st;
    string res = "";

    for (int i = 0; i < s.size(); i++) {
        if (isalpha(s[i])) {
            st.push(s[i]);  // push character
        } else if (isdigit(s[i])) {
            int count = s[i] - '0';
            if (!st.empty()) {
                char ch = st.top();
                st.pop();
                // repeat character count times
                for (int j = 0; j < count; j++)
                    res += ch;
            }
        }
    }
    return res;
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    string compressed = compressString(s);
    cout << "Compressed: " << compressed << endl;

    string expanded = expandString(compressed);
    cout << "Expanded back: " << expanded << endl;

    return 0;
}
