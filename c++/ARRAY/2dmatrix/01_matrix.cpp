#include <bits/stdc++.h>
using namespace std;

// ================= BFS Solution =================
class SolutionBFS {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dist(n, vector<int>(m, -1));
        queue<pair<int,int>> q;

        // Directions: right, down, left, up
        int dirs[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

        // Push all zeros as sources
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push(make_pair(i,j));
                }
            }
        }

        // BFS
        while(!q.empty()) {
            pair<int,int> p = q.front(); q.pop();
            int x = p.first, y = p.second;

            for(int k = 0; k < 4; k++) {
                int nx = x + dirs[k][0];
                int ny = y + dirs[k][1];
                if(nx >= 0 && ny >= 0 && nx < n && ny < m && dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }

        return dist;
    }
};

// ================= DP 2-pass Solution =================
class SolutionDP {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int INF = n + m; // max possible distance
        vector<vector<int>> dp(n, vector<int>(m, INF));

        // First pass: top-left → bottom-right
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 0) dp[i][j] = 0;
                else {
                    if(i > 0) dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
                    if(j > 0) dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);
                }
            }
        }

        // Second pass: bottom-right → top-left
        for(int i = n-1; i >= 0; i--) {
            for(int j = m-1; j >= 0; j--) {
                if(i < n-1) dp[i][j] = min(dp[i][j], dp[i+1][j] + 1);
                if(j < m-1) dp[i][j] = min(dp[i][j], dp[i][j+1] + 1);
            }
        }

        return dp;
    }
};

// ================= Driver Program =================
int main() {
    vector<vector<int>> mat = {
        {0,0,0},
        {0,1,0},
        {1,1,1}
    };

    SolutionBFS bfsSolver;
    SolutionDP dpSolver;

    vector<vector<int>> bfsResult = bfsSolver.updateMatrix(mat);
    vector<vector<int>> dpResult = dpSolver.updateMatrix(mat);

    cout << "BFS Result:\n";
    for(int i = 0; i < bfsResult.size(); i++) {
        for(int j = 0; j < bfsResult[0].size(); j++)
            cout << bfsResult[i][j] << " ";
        cout << "\n";
    }

    cout << "\nDP 2-pass Result:\n";
    for(int i = 0; i < dpResult.size(); i++) {
        for(int j = 0; j < dpResult[0].size(); j++)
            cout << dpResult[i][j] << " ";
        cout << "\n";
    }

    return 0;
}
