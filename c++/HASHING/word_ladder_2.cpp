#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        vector<vector<string>> res;
        if(!dict.count(endWord)) return res;

        unordered_map<string, vector<string>> parents; 
        unordered_set<string> level{beginWord};
        bool found = false;

        while(!level.empty() && !found) {
            unordered_set<string> nextLevel;
            for(auto w : level) dict.erase(w); // remove current level words

            for(auto word : level) {
                string cur = word;
                for(int i=0; i<cur.size(); i++) {
                    char old = cur[i];
                    for(char c='a'; c<='z'; c++) {
                        cur[i] = c;
                        if(dict.count(cur)) {
                            nextLevel.insert(cur);
                            parents[cur].push_back(word); // record parent
                            if(cur == endWord) found = true;
                        }
                    }
                    cur[i] = old;
                }
            }
            level = nextLevel;
        }

        if(!found) return res;

        vector<string> path = {endWord};
        function<void(string)> dfs = [&](string word){
            if(word == beginWord){
                vector<string> tmp = path;
                reverse(tmp.begin(), tmp.end());
                res.push_back(tmp);
                return;
            }
            for(auto p : parents[word]){
                path.push_back(p);
                dfs(p);
                path.pop_back();
            }
        };
        dfs(endWord);
        return res;
    }
};

int main() {
    Solution sol;
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    string beginWord = "hit";
    string endWord = "cog";

    vector<vector<string>> ans = sol.findLadders(beginWord, endWord, wordList);
    for(auto &v : ans){
        for(auto &w : v) cout << w << " ";
        cout << endl;
    }

    return 0;
}
