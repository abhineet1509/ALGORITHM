#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dist(n, vector<int>(m, -1)); // distance array
        queue<pair<int,int>> q;

        // Step 1: Initialize queue with all 0 cells
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0){
                    dist[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

        // 4 directions: up, down, left, right
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};

        // Step 2: BFS
        while(!q.empty()){
            auto cell = q.front(); q.pop();
            int x = cell.first, y = cell.second;

            for(int k = 0; k < 4; k++){
                int nx = x + dx[k];
                int ny = y + dy[k];
                // check boundaries and if unvisited
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && dist[nx][ny] == -1){
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        return dist;
    }
};

// ----------- Main Function to Test -----------
int main() {
    Solution sol;
    vector<vector<int>> mat = {
        {0,0,0},
        {0,1,0},
        {1,1,1}
    };

    vector<vector<int>> ans = sol.updateMatrix(mat);

    cout << "Updated Matrix (Distance to nearest 0):\n";
    for(auto &row : ans){
        for(int val : row) cout << val << " ";
        cout << endl;
    }

    return 0;
}
