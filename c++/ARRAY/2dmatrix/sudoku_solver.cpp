#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validity(vector<vector<char>>& board, int a, int b, char k) {
        // check the same column
        for (int i = 0; i < 9; i++) {
            if (board[i][b] == k) return false;
        }

        // check the same row
        for (int j = 0; j < 9; j++) {
            if (board[a][j] == k) return false;
        }

        // check the 3x3 sub-box
        int startRow = (a / 3) * 3;
        int startCol = (b / 3) * 3;
        for (int i = startRow; i < startRow + 3; i++) {
            for (int j = startCol; j < startCol + 3; j++) {
                if (board[i][j] == k) return false;
            }
        }

        return true;
    }

    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char k = '1'; k <= '9'; k++) {
                        if (validity(board, i, j, k)) {
                            board[i][j] = k;  // place number
                            if (solve(board)) return true;  // recursive call
                            board[i][j] = '.';  // backtrack
                        }
                    }
                    return false;  // no valid number found
                }
            }
        }
        return true;  // solved completely
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};

int main() {
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    Solution s;
    s.solveSudoku(board);

    // print the solved board
    for (auto &row : board) {
        for (auto &c : row)
            cout << c << " ";
        cout << endl;
    }
    return 0;
}
