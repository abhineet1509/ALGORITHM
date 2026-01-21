#include <bits/stdc++.h>
using namespace std;

/* Valid Anagram — Optimized */
bool isAnagramFreq(string s, string t) {
    if (s.size() != t.size()) return false;
    int cnt[26] = {0};
    for (char c : s) cnt[c - 'a']++;
    for (char c : t)
        if (--cnt[c - 'a'] < 0) return false;
    return true;
}

/* Valid Anagram — Sort */
bool isAnagramSort(string s, string t) {
    if (s.size() != t.size()) return false;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
}

/* Group Anagrams — Optimized */
vector<vector<string>> groupAnagramsFreq(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;

    for (string s : strs) {
        int cnt[26] = {0};
        for (char c : s) cnt[c - 'a']++;

        string key;
        for (int i = 0; i < 26; i++)
            key += "#" + to_string(cnt[i]);

        mp[key].push_back(s);
    }

    vector<vector<string>> res;
    for (auto &p : mp) res.push_back(p.second);
    return res;
}

/* Group Anagrams — Sort */
vector<vector<string>> groupAnagramsSort(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;

    for (string s : strs) {
        string key = s;
        sort(key.begin(), key.end());
        mp[key].push_back(s);
    }

    vector<vector<string>> res;
    for (auto &p : mp) res.push_back(p.second);
    return res;
}

int main() {
    string s = "anagram", t = "nagaram";
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};

    isAnagramFreq(s, t);
    isAnagramSort(s, t);

    groupAnagramsFreq(strs);
    groupAnagramsSort(strs);

    return 0;
}
