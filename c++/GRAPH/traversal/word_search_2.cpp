#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Trie node definition
struct TrieNode {
    TrieNode* children[26];
    string word;

    TrieNode() {
        for (int i = 0; i < 26; ++i)
            children[i] = nullptr;
        word = "";
    }
};

class Solution {
    vector<string> result;
    int m, n;

    void insert(TrieNode* root, const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx])
                node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->word = word; // store the word at the end node
    }

    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node) {
        char c = board[i][j];
        if (c == '#' || !node->children[c - 'a']) return;

        node = node->children[c - 'a'];
        if (!node->word.empty()) {
            result.push_back(node->word);
            node->word = ""; // prevent duplicates
        }

        board[i][j] = '#'; // mark as visited

        if (i > 0) dfs(board, i - 1, j, node);
        if (j > 0) dfs(board, i, j - 1, node);
        if (i < m - 1) dfs(board, i + 1, j, node);
        if (j < n - 1) dfs(board, i, j + 1, node);

        board[i][j] = c; // backtrack
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (string& word : words)
            insert(root, word);

        m = board.size();
        n = board[0].size();

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                dfs(board, i, j, root);

        return result;
    }
};

// Sample main function to test
int main() {
    vector<vector<char>> board = {
        {'o','a','a','n'},
        {'e','t','a','e'},
        {'i','h','k','r'},
        {'i','f','l','v'}
    };

    vector<string> words = {"oath","pea","eat","rain"};

    Solution sol;
    vector<string> foundWords = sol.findWords(board, words);

    cout << "Words found:\n";
    for (const string& word : foundWords)
        cout << word << endl;

    return 0;
}
