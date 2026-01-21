#include <bits/stdc++.h>
using namespace std;

string buildLongestPalindrome(string s) {
    unordered_map<char, int> freq;
    for (char c : s) freq[c]++;

    string half = "";
    char center = 0;

    for (auto &p : freq) {
        int count = p.second;
        half += string(count / 2, p.first); 
        if (count % 2 == 1 && center == 0) {
            center = p.first; 
        }
    }

    string rev_half = half;
    reverse(rev_half.begin(), rev_half.end());

    if (center != 0) return half + center + rev_half;
    return half + rev_half;
}

int main() {
    string s = "abccccdd";
    string longest = buildLongestPalindrome(s);
    cout << "Longest palindrome after rearrangement: " << longest << endl;
    cout << "Length: " << longest.size() << endl;

    return 0;
}
