#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Helper function: check if two words differ by exactly one letter
    bool differByOne(const string &a, const string &b) {
        if (a.size() != b.size()) return false;
        int count = 0;
        for (int i = 0; i < a.size(); i++)
            if (a[i] != b[i]) count++;
        return count == 1;
    }

    // 1️⃣ Brute Force BFS (simple, slower)
    int ladderLengthBrute(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return 0;

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        while (!q.empty()) {
            auto [word, steps] = q.front();
            q.pop();

            if (word == endWord) return steps;

            vector<string> toRemove;
            for (auto &w : dict) {
                if (differByOne(word, w)) {
                    q.push({w, steps + 1});
                    toRemove.push_back(w);
                }
            }
            for (auto &w : toRemove) dict.erase(w);
        }

        return 0;
    }

    // 2️⃣ Optimized BFS (uses preprocessed patterns)
    int ladderLengthOptimized(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return 0;

        unordered_map<string, vector<string>> allCombo;
        int L = beginWord.size();

        // Preprocess all generic patterns (*ot, h*t, ho*)
        for (auto &word : wordList) {
            for (int i = 0; i < L; i++) {
                string pattern = word;
                pattern[i] = '*';
                allCombo[pattern].push_back(word);
            }
        }

        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        unordered_set<string> visited;
        visited.insert(beginWord);

        while (!q.empty()) {
            auto [word, steps] = q.front();
            q.pop();

            for (int i = 0; i < L; i++) {
                string pattern = word;
                pattern[i] = '*';

                for (auto &adj : allCombo[pattern]) {
                    if (adj == endWord) return steps + 1;
                    if (!visited.count(adj)) {
                        visited.insert(adj);
                        q.push({adj, steps + 1});
                    }
                }
            }
        }

        return 0;
    }
};

int main() {
    Solution sol;
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    // Choose which version to run:
    bool useOptimized = true;

    int result;
    if (useOptimized)
        result = sol.ladderLengthOptimized(beginWord, endWord, wordList);
    else
        result = sol.ladderLengthBrute(beginWord, endWord, wordList);

    cout << "Shortest transformation sequence length = " << result << endl;
    return 0;
}
