#include <bits/stdc++.h>
using namespace std;

/* ---------- 1️⃣ Check single 3x3 Magic Square ---------- */
bool isMagicSquare3x3(vector<vector<int>>& m) {
    bool used[10] = {false};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int v = m[i][j];
            if (v < 1 || v > 9 || used[v]) return false;
            used[v] = true;
        }
    }

    int sum = m[0][0] + m[0][1] + m[0][2];

    for (int i = 0; i < 3; i++)
        if (m[i][0] + m[i][1] + m[i][2] != sum)
            return false;

    for (int j = 0; j < 3; j++)
        if (m[0][j] + m[1][j] + m[2][j] != sum)
            return false;

    if (m[0][0] + m[1][1] + m[2][2] != sum) return false;
    if (m[0][2] + m[1][1] + m[2][0] != sum) return false;

    return true;
}

/* ---------- 2️⃣ Count Magic Squares in Grid (840) ---------- */
bool isMagic(vector<vector<int>>& g, int r, int c) {
    if (g[r+1][c+1] != 5) return false;

    bool used[10] = {false};
    for (int i = r; i < r + 3; i++) {
        for (int j = c; j < c + 3; j++) {
            int v = g[i][j];
            if (v < 1 || v > 9 || used[v]) return false;
            used[v] = true;
        }
    }

    int s = g[r][c] + g[r][c+1] + g[r][c+2];

    return
        g[r+1][c] + g[r+1][c+1] + g[r+1][c+2] == s &&
        g[r+2][c] + g[r+2][c+1] + g[r+2][c+2] == s &&
        g[r][c] + g[r+1][c] + g[r+2][c] == s &&
        g[r][c+1] + g[r+1][c+1] + g[r+2][c+1] == s &&
        g[r][c+2] + g[r+1][c+2] + g[r+2][c+2] == s &&
        g[r][c] + g[r+1][c+1] + g[r+2][c+2] == s &&
        g[r][c+2] + g[r+1][c+1] + g[r+2][c] == s;
}

int numMagicSquaresInside(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    int count = 0;

    for (int i = 0; i + 2 < n; i++) {
        for (int j = 0; j + 2 < m; j++) {
            if (isMagic(grid, i, j)) count++;
        }
    }
    return count;
}

/* ---------- Main ---------- */
int main() {
    // Check single 3x3
    vector<vector<int>> m = {
        {4,3,8},
        {9,5,1},
        {2,7,6}
    };
    cout << "Is Magic Square (3x3): " << isMagicSquare3x3(m) << endl;

    // Count in grid
    vector<vector<int>> grid = {
        {4,3,8,4},
        {9,5,1,9},
        {2,7,6,2}
    };
    cout << "Magic Squares in Grid: " << numMagicSquaresInside(grid) << endl;

    return 0;
}
