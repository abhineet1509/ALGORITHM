#include <bits/stdc++.h>
using namespace std;

void dfs(int i, int j, vector<vector<char>>& board) {
    int m = board.size(), n = board[0].size();
    if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O') return;

    board[i][j] = 'S'; // mark as safe
    dfs(i+1, j, board);
    dfs(i-1, j, board);
    dfs(i, j+1, board);
    dfs(i, j-1, board);
}

void solve(vector<vector<char>>& board) {
    if (board.empty()) return;
    int m = board.size(), n = board[0].size();

    // Mark all 'O's on border and connected to border
    for (int i = 0; i < m; i++) {
        dfs(i, 0, board);
        dfs(i, n-1, board);
    }
    for (int j = 0; j < n; j++) {
        dfs(0, j, board);
        dfs(m-1, j, board);
    }

    // Flip surrounded 'O' → 'X', safe 'S' → 'O'
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 'O') board[i][j] = 'X';
            else if (board[i][j] == 'S') board[i][j] = 'O';
        }
}

int main() {
    vector<vector<char>> board = {
        {'X','X','X','X'},
        {'X','O','O','X'},
        {'X','X','O','X'},
        {'X','O','X','X'}
    };

    solve(board);

    for (auto &row : board) {
        for (char c : row) cout << c << " ";
        cout << endl;
    }

    return 0;
}
