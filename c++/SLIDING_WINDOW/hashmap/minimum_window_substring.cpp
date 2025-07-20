#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // ✅ Optimized Sliding Window Approach
    string minWindow(string s, string t) {
        unordered_map<char, int> need, window;
        for (char c : t) need[c]++;
        int have = 0, needCount = need.size(), l = 0, resLen = INT_MAX, start = 0;

        for (int r = 0; r < s.size(); r++) {
            window[s[r]]++;
            if (need.count(s[r]) && window[s[r]] == need[s[r]]) have++;

            while (have == needCount) {
                if (r - l + 1 < resLen) resLen = r - l + 1, start = l;
                if (need.count(s[l]) && window[s[l]]-- == need[s[l]]) have--;
                l++;
            }
        }
        return resLen == INT_MAX ? "" : s.substr(start, resLen);
    }

    // 🐌 Brute Force Approach
    string minWindowBrute(string s, string t) {
        unordered_map<char, int> tFreq;
        for (char c : t) tFreq[c]++;
        int minLen = INT_MAX; string res = "";

        for (int i = 0; i < s.size(); i++) {
            unordered_map<char, int> window;
            for (int j = i; j < s.size(); j++) {
                window[s[j]]++;
                bool valid = true;
                for (auto &[c, f] : tFreq)
                    if (window[c] < f) { valid = false; break; }
                if (valid && j - i + 1 < minLen)
                    minLen = j - i + 1, res = s.substr(i, minLen);
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    string s = "ADOBECODEBANC", t = "ABC";

    cout << "Optimized: " << sol.minWindow(s, t) << endl;
    cout << "Brute Force: " << sol.minWindowBrute(s, t) << endl;

    return 0;
}
