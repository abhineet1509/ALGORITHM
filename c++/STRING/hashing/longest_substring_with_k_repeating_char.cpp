#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    pair<int, string> helper(string &s, int l, int r, int k) {
        if (r - l < k) return {0, ""};   // if(s.size() < k) return 0;

        unordered_map<char, int> freq;
        for (int i = l; i < r; i++) freq[s[i]]++;

        for (int i = l; i < r; i++) {
            if (freq[s[i]] < k) {
                auto left  = helper(s, l, i, k);
                auto right = helper(s, i + 1, r, k);

                if (left.first >= right.first)
                    return left;    //max(left,right);
                else
                    return right;
            }
        }

        return {r - l, s.substr(l, r - l)}; // return s.size();
    }

    pair<int, string> longestSubstringWithString(string s, int k) {
        return helper(s, 0, s.size(), k);
    }
};

int main() {
    Solution sol;

    string s = "aaabb";
    int k = 3;          // left == aaa right == b  (Half open interval convention)
    auto res1 = sol.longestSubstringWithString(s, k);
    cout << "Length: " << res1.first
         << ", Substring: " << res1.second << endl;

    s = "ababbc";
    k = 2;
    auto res2 = sol.longestSubstringWithString(s, k);
    cout << "Length: " << res2.first
         << ", Substring: " << res2.second << endl;

    return 0;
}
