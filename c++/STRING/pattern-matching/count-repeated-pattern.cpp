#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Method 1: Brute Force Counting using repeated substring pattern approach
    int countByBrute(string text, string pattern) {
        int n = text.length();
        int m = pattern.length();
        int count = 0;

        for (int i = 0; i <= n - m; ++i) {
            string sub = text.substr(i, m);
            if (sub == pattern)
                count++;
        }

        return count;
    }

    // Method 2: KMP Counting using LPS array (as in repeatedSubstringPattern code)
    int countByKMP(string text, string pattern) {
        int n = text.length();
        int m = pattern.length();

        vector<int> lps(m, 0);
        int len = 0;

        for (int i = 1; i < m; i++) {
            while (len > 0 && pattern[i] != pattern[len])
                len = lps[len - 1];
            if (pattern[i] == pattern[len])
                len++;
            lps[i] = len;
        }

        int i = 0, j = 0, count = 0;

        while (i < n) {
            if (text[i] == pattern[j]) {
                i++;
                j++;
            }

            if (j == m) {
                count++;
                j = lps[j - 1];
            } else if (i < n && text[i] != pattern[j]) {
                if (j != 0)
                    j = lps[j - 1];
                else
                    i++;
            }
        }

        return count;
    }
};

int main() {
    Solution sol;
    string text = "abcabcabcabc";
    string pattern = "abc";

    cout << "Brute Force Count: " << sol.countByBrute(text, pattern) << endl;
    cout << "KMP Count: " << sol.countByKMP(text, pattern) << endl;

    return 0;
}
