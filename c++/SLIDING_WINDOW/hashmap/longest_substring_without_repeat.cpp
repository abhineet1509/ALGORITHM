#include <iostream>
#include <unordered_map>
using namespace std;

int longestSubstringWithoutRepeat(string s) {
    int n = s.size();
    unordered_map<char, int> freq;
    int maxLen = 0;
    int start = 0, end = 0;

    while (end < n) {
        freq[s[end]]++;

        // If character repeats, shrink window from the left
        while (freq[s[end]] > 1) {
            freq[s[start]]--;
            start++;
        }

        // Update max length
        maxLen = max(maxLen, end - start + 1);
        end++;
    }

    return maxLen;
}

int main() {
    string s = "abcabcbb";
    cout << "Length of longest substring without repeating characters: "
         << longestSubstringWithoutRepeat(s) << endl;
    return 0;
}
