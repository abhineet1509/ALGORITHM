#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

// Function to convert parity vector to a string key
string makeKey(const vector<int>& count) {
    string key = "";
    for (int x : count) {
        key += to_string(x % 2); // only store 0 (even) or 1 (odd)
    }
    return key;
}

int longestEvenVowelSubstring(string s) {
    unordered_map<string, int> seen;
    vector<int> count(5, 0); // Count for a, e, i, o, u

    string initKey = "00000"; // all even
    seen[initKey] = -1; // Initial index before start

    int maxLen = 0;

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (c == 'a') count[0]++;
        else if (c == 'e') count[1]++;
        else if (c == 'i') count[2]++;
        else if (c == 'o') count[3]++;
        else if (c == 'u') count[4]++;

        string key = makeKey(count);

        if (seen.find(key) != seen.end()) {
            maxLen = max(maxLen, i - seen[key]);
        } else {
            seen[key] = i;
        }
    }

    return maxLen;
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    int result = longestEvenVowelSubstring(s);
    cout << "Longest substring length with even vowels: " << result << endl;

    return 0;
}
