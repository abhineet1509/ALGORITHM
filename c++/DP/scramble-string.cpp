#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string, bool> mp;

bool isScramble(string s1, string s2) {
    if (s1 == s2) return true;
    if (s1.length() != s2.length()) return false;

    string key = s1 + " " + s2;
    if (mp.find(key) != mp.end()) return mp[key];

    int n = s1.length();
    for (int i = 1; i < n; ++i) {
        // Check without swapping
        if (isScramble(s1.substr(0, i), s2.substr(0, i)) &&
            isScramble(s1.substr(i), s2.substr(i)))
            return mp[key] = true;

        // Check with swapping
        if (isScramble(s1.substr(0, i), s2.substr(n - i)) &&
            isScramble(s1.substr(i), s2.substr(0, n - i)))
            return mp[key] = true;
    }

    return mp[key] = false;
}

int main() {
    string s1 = "great", s2 = "rgeat";
    cout << "Is Scramble: " << (isScramble(s1, s2) ? "Yes" : "No") << endl;
    return 0;
}
