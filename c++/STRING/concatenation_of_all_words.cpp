#include <bits/stdc++.h>
using namespace std;

// -----------------------------------------------------
// PART-1 : Concatenation of all words (valid window)
// -----------------------------------------------------
class Solution {
public:
    vector<pair<int,string>> findSubstring(string s, vector<string>& words) {

        unordered_map<string, int> mp, freq;
        for (string &w : words)
            mp[w]++;

        int wordLen = words[0].size();
        int totalWords = words.size();
        int totalLen = wordLen * totalWords;

        vector<pair<int,string>> res;

        for (int offset = 0; offset < wordLen; offset++) {

            int left = offset, right = offset;
            freq.clear();

            while (right + wordLen <= s.size()) {

                string curr = s.substr(right, wordLen);

                // Invalid → reset
                if (mp.find(curr) == mp.end()) {
                    freq.clear();
                    right += wordLen;
                    left = right;
                    continue;
                }

                freq[curr]++;

                // Shrink if extra occurrences
                while (freq[curr] > mp[curr]) {
                    string lw = s.substr(left, wordLen);
                    freq[lw]--;
                    left += wordLen;
                }

                // Full window matches
                if (right - left + wordLen == totalLen) {
                    string sub = s.substr(left, totalLen);
                    res.push_back({left, sub});

                    // move left ahead
                    string lw = s.substr(left, wordLen);
                    freq[lw]--;
                    left += wordLen;
                }

                right += wordLen;
            }
        }

        return res;
    }
};

// -----------------------------------------------------
// PART-2 : Individual word match with starting index
// -----------------------------------------------------
vector<pair<int,string>> findWordsWithIndex(string s, vector<string>& words) {
    vector<pair<int,string>> res;
    unordered_set<string> wordSet(words.begin(), words.end());
    int n = s.size();

    for (int i = 0; i < n; i++) {
        for (string w : words) {
            int len = w.size();
            if (i + len <= n && s.substr(i, len) == w) {
                res.push_back({i, w});
            }
        }
    }

    return res;
}

// -----------------------------------------------------
// MAIN
// -----------------------------------------------------
int main() {

    string s;
    int n;

    cout << "Enter string: ";
    cin >> s;

    cout << "Enter number of words: ";
    cin >> n;

    vector<string> words(n);
    cout << "Enter words:\n";
    for (int i = 0; i < n; i++)
        cin >> words[i];

    Solution obj;

    // PART 1 OUTPUT
    vector<pair<int,string>> concatResult = obj.findSubstring(s, words);

    cout << "\n=== Concatenated Matches ===\n";
    for (auto &p : concatResult)
        cout << p.first << " -> " << p.second << endl;

    // PART 2 OUTPUT
    vector<pair<int,string>> wordMatches = findWordsWithIndex(s, words);

    cout << "\n=== Individual Word Matches ===\n";
    for (auto &p : wordMatches)
        cout << p.first << " -> " << p.second << endl;

    return 0;
}
