#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSafe(int row, int col, vector<string>& board, int n) {
        for(int i = 0; i < row; i++) {
            if(board[i][col] == 'Q') return false;
            if(col - (row - i) >= 0 && board[i][col - (row - i)] == 'Q') return false;
            if(col + (row - i) < n && board[i][col + (row - i)] == 'Q') return false;
        }
        return true;
    }

    void solve(int row, int n, vector<string>& board, vector<vector<string>>& res) {
        if(row == n) {
            res.push_back(board);
            return;
        }
        for(int col = 0; col < n; col++) {
            if(isSafe(row, col, board, n)) {
                board[row][col] = 'Q';
                solve(row + 1, n, board, res);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        solve(0, n, board, res);
        return res;
    }
};

int main() {
    int n;
    cout << "Enter N: ";
    cin >> n;

    Solution sol;
    vector<vector<string>> solutions = sol.solveNQueens(n);

    cout << "Total solutions = " << solutions.size() << "\n\n";
    for(int k = 0; k < solutions.size(); k++) {
        cout << "Solution " << k+1 << ":\n";
        for(string row : solutions[k]) {
            cout << row << "\n";
        }
        cout << "\n";
    }

    return 0;
}
