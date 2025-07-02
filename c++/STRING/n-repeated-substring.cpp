#include <iostream>
#include <vector>
using namespace std;

bool repeatedSubstringPattern(string str) {
    int n = str.length();
    vector<int> lps(n, 0);  // Longest Prefix Suffix

    // Build the LPS array
    for (int i = 1, len = 0; i < n; ) {
        if (str[i] == str[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];  // Try shorter prefix
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    int len = lps[n - 1];  // Length of the longest prefix which is also suffix
    return (len > 0 && n % (n - len) == 0);
}

int main() {
    vector<string> testCases = {"abcabcabc", "abadabad", "aabaabaabaab", "abcdabc"};
    for (const string& str : testCases) {
        cout << "Input: " << str << "\nOutput: "
             << (repeatedSubstringPattern(str) ? "true" : "false") << "\n\n";
    }
    return 0;
}
