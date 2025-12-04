#include <iostream>
#include <unordered_map>
using namespace std;

pair<int,string> longestSubstringWithoutRepeat(string s) {
    int n = s.size();
    unordered_map<char, int> freq;

    int maxLen = 0;
    int start = 0, end = 0;
    int bestStart = 0;  // to store starting index of best window

    while (end < n) {
        freq[s[end]]++;

        // if repeated character, shrink window
        while (freq[s[end]] > 1) {
            freq[s[start]]--;
            start++;
        }

        // update best window
        if (end - start + 1 > maxLen) {
            maxLen = end - start + 1;
            bestStart = start;
        }

        end++;
    }

    return {maxLen, s.substr(bestStart, maxLen)};
}

int main() {
    string s = "abcabcbb";

    auto ans = longestSubstringWithoutRepeat(s);

    cout << "Length: " << ans.first << endl;
    cout << "Substring: " << ans.second << endl;

    return 0;
}
