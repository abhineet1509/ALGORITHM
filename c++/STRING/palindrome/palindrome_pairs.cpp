#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /* ---------- COMMON PALINDROME CHECK ---------- */
    bool isPal(const string &s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }

    /* ---------- 1️⃣ BRUTE FORCE APPROACH ---------- */
    vector<vector<int>> palindromePairsBrute(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> res;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                string combined = words[i] + words[j];
                if (isPal(combined, 0, combined.size() - 1)) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }

    /* ---------- 2️⃣ OPTIMAL HASHMAP APPROACH ---------- */
    vector<vector<int>> palindromePairsOptimal(vector<string>& words) {
        unordered_map<string, int> mp;
        vector<vector<int>> res;

        // store word -> index
        for (int i = 0; i < words.size(); i++)
            mp[words[i]] = i;

        for (int i = 0; i < words.size(); i++) {
            string w = words[i];
            int len = w.size();

            for (int cut = 0; cut <= len; cut++) {
                string left = w.substr(0, cut);
                string right = w.substr(cut);

                // Case 1: left palindrome → rev(right) + w
                if (isPal(left, 0, left.size() - 1)) {
                    string revRight = right;
                    reverse(revRight.begin(), revRight.end());

                    if (mp.count(revRight) && mp[revRight] != i) {
                        res.push_back({mp[revRight], i});
                    }
                }

                // Case 2: right palindrome → w + rev(left)
                if (cut != len && isPal(right, 0, right.size() - 1)) {
                    string revLeft = left;
                    reverse(revLeft.begin(), revLeft.end());

                    if (mp.count(revLeft) && mp[revLeft] != i) {
                        res.push_back({i, mp[revLeft]});
                    }
                }
            }
        }
        return res;
    }
};

/* ---------- DRIVER CODE (OPTIONAL) ---------- */
int main() {
    Solution sol;
    vector<string> words = {"bat", "tab", "cat"};

    auto brute = sol.palindromePairsBrute(words);
    auto optimal = sol.palindromePairsOptimal(words);

    cout << "Brute Force Result:\n";
    for (auto &p : brute)
        cout << "[" << p[0] << "," << p[1] << "] ";

    cout << "\n\nOptimal Result:\n";
    for (auto &p : optimal)
        cout << "[" << p[0] << "," << p[1] << "] ";

    return 0;
}
