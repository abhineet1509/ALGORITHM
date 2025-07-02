#include <iostream>
#include <vector>
#include <string>
using namespace std;

class PatternMatching {
public:
    // ---------- BRUTE FORCE METHOD ----------
    vector<int> bruteForce(string text, string pattern) {
        vector<int> result;
        int n = text.length();
        int m = pattern.length();

        for (int i = 0; i <= n - m; i++) {
            int j = 0;
            while (j < m && text[i + j] == pattern[j])
                j++;
            if (j == m)
                result.push_back(i);
        }

        return result;
    }

    // ---------- BUILD LPS ARRAY FOR KMP ----------
    vector<int> buildLPS(string pattern) {
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

        return lps;
    }

    // ---------- KMP METHOD ----------
    vector<int> KMP(string text, string pattern) {
        vector<int> result;
        vector<int> lps = buildLPS(pattern);
        int i = 0, j = 0;
        int n = text.length(), m = pattern.length();

        while (i < n) {
            if (text[i] == pattern[j]) {
                i++;
                j++;
            }

            if (j == m) {
                result.push_back(i - j);
                j = lps[j - 1];
            } else if (i < n && text[i] != pattern[j]) {
                if (j != 0)
                    j = lps[j - 1];
                else
                    i++;
            }
        }

        return result;
    }
};

int main() {
    PatternMatching pm;

    string text = "ababcababcababc";
    string pattern = "ababc";

    // Brute Force Output
    vector<int> bruteRes = pm.bruteForce(text, pattern);
    cout << "Brute Force Matches at: ";
    for (int idx : bruteRes)
        cout << idx << " ";
    cout << endl;

    // KMP Output
    vector<int> kmpRes = pm.KMP(text, pattern);
    cout << "KMP Matches at: ";
    for (int idx : kmpRes)
        cout << idx << " ";
    cout << endl;

    return 0;
}
