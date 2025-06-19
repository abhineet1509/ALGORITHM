#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool isInside(int x, int y, int n, int m) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<string> grid(n);
        for (int i = 0; i < n; ++i)
            cin >> grid[i];

        vector<vector<bool>> used(n, vector<bool>(m, false));
        set<pair<int, int>> goldCollected;

        for (int x = 0; x < n; ++x) {
            for (int y = 0; y < m; ++y) {
                if (grid[x][y] != '.') continue;

                int r1 = x - k, r2 = x + k;
                int c1 = y - k, c2 = y + k;

                // Top and Bottom rows
                for (int j = c1; j <= c2; ++j) {
                    if (r1 >= 0 && j >= 0 && r1 < n && j < m && grid[r1][j] == 'g')
                        goldCollected.insert({r1, j});
                    if (r2 >= 0 && j >= 0 && r2 < n && j < m && grid[r2][j] == 'g')
                        goldCollected.insert({r2, j});
                }

                // Left and Right columns (excluding corners already counted)
                for (int i = r1 + 1; i < r2; ++i) {
                    if (c1 >= 0 && i >= 0 && i < n && c1 < m && grid[i][c1] == 'g')
                        goldCollected.insert({i, c1});
                    if (c2 >= 0 && i >= 0 && i < n && c2 < m && grid[i][c2] == 'g')
                        goldCollected.insert({i, c2});
                }
            }
        }

        cout << goldCollected.size() << "\n";
    }

    return 0;
}
