#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int k) {
        // If all characters are matched
        if (k == word.size()) return true;

        // Check boundaries and character mismatch
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[k])
            return false;

        // Mark current cell as visited
        char temp = board[i][j];
        board[i][j] = '#';

        // Explore all 4 directions
        bool found = dfs(board, word, i + 1, j, k + 1) ||
                     dfs(board, word, i - 1, j, k + 1) ||
                     dfs(board, word, i, j + 1, k + 1) ||
                     dfs(board, word, i, j - 1, k + 1);

        // Backtrack (restore cell)
        board[i][j] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0] && dfs(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    string word = "ABCCED";
    
    if (s.exist(board, word))
        cout << "Word Found" << endl;
    else
        cout << "Word Not Found" << endl;

    return 0;
}
