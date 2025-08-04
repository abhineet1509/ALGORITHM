#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        string l = s + "#" + rev;

        vector<int> lps(l.size(), 0);
        for (int i = 1; i < l.size(); i++) {
            int len = lps[i - 1];
            while (len > 0 && l[i] != l[len])
                len = lps[len - 1];
            if (l[i] == l[len])
                len++;
            lps[i] = len;
        }

        return rev.substr(0, s.size() - lps.back()) + s;
    }
};

class Solution {
public:
    bool isPalindrome(const string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }

    string shortestPalindrome(string s) {
        int n = s.size();
        
        for (int i = n; i >= 1; i--) {
            if (isPalindrome(s, 0, i - 1)) {
                string suffix = s.substr(i);  // non-palindromic suffix
                reverse(suffix.begin(), suffix.end());
                return suffix + s;
            }
        }

        return "";  // This line won't be reached since at least 1-char prefix is always a palindrome
    }
};
int main() {
    Solution sol;

    vector<string> testInputs = {"aacecaaa", "abcd", "race", "aabba", "civic", "abcba"};
    
    for (string input : testInputs) {
        string result = sol.shortestPalindrome(input);
        cout << "Input: " << input << " -> Shortest Palindrome: " << result << endl;
    }

    return 0;
}
