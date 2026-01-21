#include <bits/stdc++.h>
using namespace std;

/* ---------- Smallest Palindromic Rearrangement I ----------
   Only lowercase letters (a-z)
*/
string smallestPalindromeI(string s) {
    vector<int> freq(26, 0);
    for (char c : s) freq[c - 'a']++;

    int oddCount = 0;
    char mid = 0;

    for (int i = 0; i < 26; i++) {
        if (freq[i] % 2) {
            oddCount++;
            mid = char('a' + i);
        }
    }

    if (oddCount > 1) return "-1";

    string left = "";
    for (int i = 0; i < 26; i++) {
        left += string(freq[i] / 2, char('a' + i));
    }

    string right = left;
    reverse(right.begin(), right.end());

    return (oddCount ? left + mid + right : left + right);
}

/* ---------- Smallest Palindromic Rearrangement II ----------
   Any characters
*/
string smallestPalindromeII(string s) {
    map<char, int> freq;
    for (char c : s) freq[c]++;

    int oddCount = 0;
    char mid = 0;

    for (auto &p : freq) {
        if (p.second % 2) {
            oddCount++;
            mid = p.first;
        }
    }

    if (oddCount > 1) return "-1";

    string left = "";
    for (auto &p : freq) {
        left += string(p.second / 2, p.first);
    }

    string right = left;
    reverse(right.begin(), right.end());

    return (oddCount ? left + mid + right : left + right);
}

/* -------------------- MAIN -------------------- */
int main() {
    string s1 = "aabb";
    string s2 = "aabbccdde";

    cout << "Palindrome I : " << smallestPalindromeI(s1) << endl;
    cout << "Palindrome II: " << smallestPalindromeII(s2) << endl;

    return 0;
}
