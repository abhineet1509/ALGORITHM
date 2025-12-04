#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> result;

    bool isValid(const string &seg) {
        if (seg.size() > 1 && seg[0] == '0') return false;
        int val = stoi(seg);
        return val >= 0 && val <= 255;
    }

    void backtrack(string &s, int idx, int parts, string curr) {
        if (parts == 4 && idx == s.size()) {
            curr.pop_back(); // remove last dot
            result.push_back(curr);
            return;
        }

        if (parts >= 4) return;

        for (int len = 1; len <= 3 && idx + len <= s.size(); len++) {
            string seg = s.substr(idx, len);
            if (!isValid(seg)) continue;

            backtrack(s, idx + len, parts + 1, curr + seg + ".");
        }
    }

    vector<string> restoreIpAddresses(string s) {
        backtrack(s, 0, 0, "");
        return result;
    }
};

int main() {
    Solution sol;
    string s = "25525511135";
    vector<string> ans = sol.restoreIpAddresses(s);

    for (auto &ip : ans)
        cout << ip << endl;

    return 0;
}
