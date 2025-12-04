#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validity(vector<vector<char>>& board, char num, int a, int b) {
        // check the same column
        for (int i = 0; i < 9; i++) {
            if (i != a && board[i][b] == num)
                return false;
        }

        // check the same row
        for (int j = 0; j < 9; j++) {
            if (j != b && board[a][j] == num)
                return false;
        }

        // check the 3x3 sub-box
        int startRow = (a / 3) * 3;
        int startCol = (b / 3) * 3;
        for (int i = startRow; i < startRow + 3; i++) {
            for (int j = startCol; j < startCol + 3; j++) {
                if ((i != a || j != b) && board[i][j] == num)
                    return false;
            }
        }

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (!validity(board, board[i][j], i, j))
                        return false;
                }
            }
        }
        return true;
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
    cout << (s.isValidSudoku(board) ? "Valid Sudoku" : "Invalid Sudoku") << endl;
    return 0;
}
