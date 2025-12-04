#include <bits/stdc++.h>
using namespace std;

bool win(vector<string>& b, char p) {
    for (int i = 0; i < 3; i++)
        if (b[i][0] == p && b[i][1] == p && b[i][2] == p)
            return true;
    for (int j = 0; j < 3; j++)
        if (b[0][j] == p && b[1][j] == p && b[2][j] == p)
            return true;
    if (b[0][0] == p && b[1][1] == p && b[2][2] == p)
        return true;
    if (b[0][2] == p && b[1][1] == p && b[2][0] == p)
        return true;
    return false;
}

bool validTicTacToe(vector<string>& board) {
    int xCount = 0, oCount = 0;
    for (auto& row : board)
        for (auto& c : row)
            if (c == 'X') xCount++;
            else if (c == 'O') oCount++;

    if (oCount > xCount) return false;
    if (xCount - oCount > 1) return false;

    bool xWin = win(board, 'X');
    bool oWin = win(board, 'O');

    if (xWin && oWin) return false;
    if (xWin && xCount != oCount + 1) return false;
    if (oWin && xCount != oCount) return false;

    return true;
}

int main() {
    vector<string> board = {
        "XOX",
        " X ",
        "   "
    };
    cout << (validTicTacToe(board) ? "true" : "false");
}
