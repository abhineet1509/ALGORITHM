#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for (int i = 1; i <= n / 2; ++i) {
            if (n % i == 0) {
                string pattern = s.substr(0, i);
                string repeated = "";
                for (int j = 0; j < n / i; ++j) {
                    repeated += pattern;
                }
                if (repeated == s)
                    return true;
            }
        }
        return false;
    }
};

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        vector<int> lps(n, 0); // Longest Prefix Suffix array
        int len = 0;

        for (int i = 1; i < n; i++) {
            while (len > 0 && s[i] != s[len])
                len = lps[len - 1];
            if (s[i] == s[len])
                len++;
            lps[i] = len;
        }

        int lastLPS = lps[n - 1];
        return (lastLPS > 0 && n % (n - lastLPS) == 0);
    }
};

int main() {
    Solution sol;
    string s1 = "abcabcabcabc";
    string s2 = "abab";
    string s3 = "abcd";
    string s4 = "aabaabaabaab";

    cout << boolalpha;
    cout << "s1: " << sol.repeatedSubstringPattern(s1) << endl;
    cout << "s2: " << sol.repeatedSubstringPattern(s2) << endl;
    cout << "s3: " << sol.repeatedSubstringPattern(s3) << endl;
    cout << "s4: " << sol.repeatedSubstringPattern(s4) << endl;

    return 0;
}
