#include <bits/stdc++.h>
using namespace std;
// with lexographically smallest
string removeDuplicateLetters(string s) {
    vector<int> freq(26, 0);
    vector<bool> used(26, false);

    for (int i = 0; i < s.size(); i++)
        freq[s[i] - 'a']++;

    string st = "";

    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        freq[c - 'a']--;

        if (used[c - 'a'])
            continue;

        while (!st.empty() && st.back() > c && freq[st.back() - 'a'] > 0) {
            used[st.back() - 'a'] = false;
            st.pop_back();
        }

        st.push_back(c);
        used[c - 'a'] = true;
    }

    return st;
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    cout << "Result: " << removeDuplicateLetters(s) << endl;
    return 0;
}
