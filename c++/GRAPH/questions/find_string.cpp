#include <bits/stdc++.h>
using namespace std;

int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};

bool searchDir(vector<vector<char>>& grid, int x, int y, string& word) {
    int n = grid.size(), m = grid[0].size();
    int len = word.size();

    for (int dir = 0; dir < 8; dir++) {
        int nx = x, ny = y, k;

        for (k = 0; k < len; k++) {
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) break;
            if (grid[nx][ny] != word[k]) break;

            nx += dx[dir];
            ny += dy[dir];
        }
        if (k == len) return true;
    }
    return false;
}

vector<pair<int,int>> findString(vector<vector<char>>& grid, string word) {
    vector<pair<int,int>> result;
    int n = grid.size(), m = grid[0].size();

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j] == word[0])
                if (searchDir(grid, i, j, word))
                    result.push_back({i, j});

    return result;
}

int main() {
    vector<vector<char>> grid = {
        {'G','O','D'},
        {'D','E','O'},
        {'E','K','S'}
    };

    string word = "GOD";
    auto ans = findString(grid, word);

    for (auto &p : ans) 
        cout << p.first << " " << p.second << endl;

    return 0;
}
