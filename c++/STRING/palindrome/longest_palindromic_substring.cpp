#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(const string &s) {
    int i = 0, j = s.size() - 1;
    while (i < j) {
        if (s[i] != s[j]) return false;
        i++; j--;
    }
    return true;
}

string longestPalindrome(const string &s) {
    int n = s.size();
    string longest = ""; 
    
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            string sub = s.substr(i, j - i + 1);
            if (isPalindrome(sub) && sub.size() > longest.size()) {
                longest = sub;
            }
        }
    }
    
    return longest;
}

int main() {
    string s = "ababa";
    
    string longest = longestPalindrome(s);
    cout << "Longest palindromic substring: " << longest << endl;
    
    return 0;
}
