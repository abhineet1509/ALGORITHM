#include <iostream>
#include <vector>
using namespace std;

// Step 1: Build LPS array
vector<int> buildLPS(string pattern) {
    int n = pattern.size();
    vector<int> lps(n, 0);
    int len = 0; 

    for (int i = 1; i < n;) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0)
                len = lps[len - 1];
            else
                lps[i++] = 0;
        }
    }
    return lps;
}

// Step 2: KMP search
int KMP(string text, string pattern) {
    int m = text.size(), n = pattern.size();
    if (n == 0) return 0;

    vector<int> lps = buildLPS(pattern);
    int i = 0, j = 0;

    while (i < m) {
        if (text[i] == pattern[j]) {
            i++, j++;
        }
        if (j == n) {
            return i - j; // match found
        } else if (i < m && text[i] != pattern[j]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    return -1; 
}

int main() {
    string text, pattern;
    cout << "Enter text: ";
    getline(cin, text);
    cout << "Enter pattern: ";
    getline(cin, pattern);

    int index = KMP(text, pattern);
    if (index != -1)
        cout << "Pattern found at index: " << index << endl;
    else
        cout << "Pattern not found." << endl;

    return 0;
}
// text    = "xxabcxx"
// index     0 1 2 3 4 5 6

// pattern = "abc"
// length = 3
