#include <bits/stdc++.h>
using namespace std;

bool isStretchy(const string& s, const string& w) {
    int i = 0, j = 0;
    int n = s.size(), m = w.size();

    while (i < n && j < m) {
        if (s[i] != w[j]) return false;

        int i0 = i, j0 = j;
        while (i < n && s[i] == s[i0]) i++;
        while (j < m && w[j] == w[j0]) j++;

        int lenS = i - i0;
        int lenW = j - j0;

        if (lenS < 3 && lenS != lenW) return false;
        if (lenS >= 3 && lenW > lenS) return false;
    }

    return i == n && j == m;
}

int expressiveWords(string s, vector<string>& words) {
    int count = 0;
    for (const string& w : words)
        if (isStretchy(s, w)) count++;
    return count;
}

int main() {
    string s = "heeellooo";
    vector<string> words = {"hello","hi","helo"};

    cout << expressiveWords(s, words); // Output: 1
    return 0;
}
