#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if(words.empty() || s.empty()) return res;

        int wordLen = words[0].size();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;

        unordered_map<string,int> wordMap;
        for(auto &w : words) wordMap[w]++;

        for(int i = 0; i < wordLen; i++) {
            int left = i, count = 0;
            unordered_map<string,int> seen;
            for(int j = i; j + wordLen <= s.size(); j += wordLen) {
                string sub = s.substr(j, wordLen);
                if(wordMap.count(sub)) {
                    seen[sub]++;
                    count++;
                    while(seen[sub] > wordMap[sub]) {
                        string leftWord = s.substr(left, wordLen);
                        seen[leftWord]--;
                        left += wordLen;
                        count--;
                    }
                    if(count == wordCount) res.push_back(left);
                } else {
                    seen.clear();
                    count = 0;
                    left = j + wordLen;
                }
            }
        }

        return res;
    }
};

int main() {
    string s = "barfoothefoobarman";
    vector<string> words = {"foo","bar"};

    Solution sol;
    vector<int> res = sol.findSubstring(s, words);
    for(int idx : res) cout << idx << " ";
    cout << endl; // Output: 0 9
    return 0;
}
