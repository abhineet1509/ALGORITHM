#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidTicTacToe(vector<string>& board) {
        int xCount = 0, oCount = 0;

        // Count X's and O's
        for (auto& row : board) {
            for (char c : row) {
                if (c == 'X') xCount++;
                if (c == 'O') oCount++;
            }
        }

        // Rule 1: 'X' goes first, and they alternate turns
        if (oCount > xCount || xCount - oCount > 1) return false;

        // Check win conditions
        bool xWin = playerWins(board, 'X');
        bool oWin = playerWins(board, 'O');

        // Rule 3: both cannot win
        if (xWin && oWin) return false;

        // Rule 2: if X wins, X must have one more than O
        if (xWin && xCount != oCount + 1) return false;

        // Rule 2: if O wins, X and O counts must be equal
        if (oWin && xCount != oCount) return false;

        return true;
    }

private:
    bool playerWins(vector<string>& board, char player) {
        // Rows, columns, diagonals
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
                return true;
            if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
                return true;
        }
        if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
            return true;
        if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
            return true;

        return false;
    }
};

int main() {
    Solution sol;
    vector<string> board = {
        "XOX",
        " X ",
        "   "
    };

    cout << (sol.isValidTicTacToe(board) ? "Valid" : "Invalid") << endl;
    return 0;
}
