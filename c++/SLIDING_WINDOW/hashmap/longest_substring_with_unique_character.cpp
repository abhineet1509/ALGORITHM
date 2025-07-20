#include <iostream>
#include <unordered_map>
using namespace std;

int longestSubstringWithKUniqueChars(string s, int k) {
    int n = s.length();
    int maxLen = -1;
    int start = 0, end = 0;
    unordered_map<char, int> freq;

    while (end < n) {
        // Include current character in the map
        freq[s[end]]++;

        // If unique characters exceed k, shrink the window
        while (freq.size() > k) {
            freq[s[start]]--;
            if (freq[s[start]] == 0)
                freq.erase(s[start]);
            start++;
        }

        // Check if current window has exactly k unique characters
        if (freq.size() == k) {
            maxLen = max(maxLen, end - start + 1);
        }

        end++;
    }

    return maxLen;
}

int main() {
    string s = "aabacbebebe";
    int k = 3;
    cout << "Longest substring length with exactly " << k << " unique characters: "
         << longestSubstringWithKUniqueChars(s, k) << endl;
    return 0;
}
