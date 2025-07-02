#include <iostream>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstringKDistinct(string s, int k) {
    if (k == 0 || s.empty()) return 0;

    unordered_map<char, int> freq;
    int start = 0, maxLen = 0;

    for (int end = 0; end < s.length(); end++) {
        freq[s[end]]++;

        while (freq.size() > k) {
            freq[s[start]]--;
            if (freq[s[start]] == 0)
                freq.erase(s[start]);
            start++;
        }

        maxLen = max(maxLen, end - start + 1);
    }

    return maxLen;
}

int main() {
    string s = "eceba";
    int k = 2;
    cout << "Longest substring with at most " << k << " distinct characters: "
         << lengthOfLongestSubstringKDistinct(s, k) << endl;
    return 0;
}
