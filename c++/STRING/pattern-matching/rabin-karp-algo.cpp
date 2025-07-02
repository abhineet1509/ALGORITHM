#include <iostream>
using namespace std;

#define d 256      // number of possible characters (ASCII)
#define q 101      // A prime number for modulo (to avoid overflow)

void rabinKarp(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    int p = 0, t = 0; // hash values for pattern and text window
    int h = 1;

    // h = pow(d, m-1) % q
    for (int i = 0; i < m - 1; i++)
        h = (h * d) % q;

    // Calculate initial hash values of pattern and first window of text
    for (int i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // Slide the pattern over text
    for (int i = 0; i <= n - m; i++) {
        if (p == t) {
            // Check character by character if hash matches
            bool match = true;
            for (int j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }
            if (match)
                cout << "Pattern found at index " << i << endl;
        }

        // Rolling hash: calculate hash of next window
        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;
            if (t < 0) t += q; // make sure hash is positive
        }
    }
}

int main() {
    string text = "abedbabacdba";
    string pattern = "dba";
    rabinKarp(text, pattern);
    return 0;
}
