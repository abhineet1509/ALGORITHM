#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int r, int c,
             vector<vector<int>>& image,
             int oldColor, int newColor) {

        int n = image.size();
        int m = image[0].size();

      
        if (r < 0 || c < 0 || r >= n || c >= m)
            return;
        if (image[r][c] != oldColor)
            return;

        image[r][c] = newColor;

        // 4-direction DFS
        dfs(r - 1, c, image, oldColor, newColor); // up
        dfs(r + 1, c, image, oldColor, newColor); // down
        dfs(r, c - 1, image, oldColor, newColor); // left
        dfs(r, c + 1, image, oldColor, newColor); // right
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr, int sc, int newColor) {

        int oldColor = image[sr][sc];
        if (oldColor == newColor)
            return image;

        dfs(sr, sc, image, oldColor, newColor);
        return image;
    }
};
vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr, int sc, int newColor) {
        int n = image.size();
        int m = image[0].size();

        int oldColor = image[sr][sc];
        if (oldColor == newColor) return image;

        queue<pair<int,int>> q;
        q.push({sr, sc});
        image[sr][sc] = newColor;

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        while (!q.empty()) {
            pair<int,int> p = q.front();
            int r = p.first;
            int c = p.second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nc >= 0 && nr < n && nc < m &&
                    image[nr][nc] == oldColor) {

                    image[nr][nc] = newColor;
                    q.push({nr, nc});
                }
            }
        }
        return image;
    }
int main() {
    int n, m;
    cout << "Enter rows and columns: ";
    cin >> n >> m;

    vector<vector<int>> image(n, vector<int>(m));
    cout << "Enter image matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> image[i][j];

    int sr, sc, newColor;
    cout << "Enter start row, start column and new color: ";
    cin >> sr >> sc >> newColor;

    Solution obj;
    vector<vector<int>> result = obj.floodFill(image, sr, sc, newColor);

    cout << "Resulting Image:\n";
    for (auto &row : result) {
        for (int val : row)
            cout << val << " ";
        cout << endl;
    }

    return 0;
}
