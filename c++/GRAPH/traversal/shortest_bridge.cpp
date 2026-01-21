#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& grid, int x, int y, queue<pair<int,int>>& q) {
    int n = grid.size(), m = grid[0].size();
    if(x < 0 || x >= n || y < 0 || y >= m || grid[x][y] != 1) return;

    grid[x][y] = 2;  // mark as visited
    q.push({x, y});

    dfs(grid, x+1, y, q);
    dfs(grid, x-1, y, q);
    dfs(grid, x, y+1, q);
    dfs(grid, x, y-1, q);
}

int shortestBridge(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    queue<pair<int,int>> q;
    bool found = false;

    // Step 1: find first island and mark it
    for(int i = 0; i < n && !found; i++){
        for(int j = 0; j < m && !found; j++){
            if(grid[i][j] == 1){
                dfs(grid, i, j, q);
                found = true;
            }
        }
    }

    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    int steps = 0;

    // Step 2: BFS to reach second island
    while(!q.empty()){
        int sz = q.size();
        for(int i = 0; i < sz; i++){
            auto x = q.front().first;
            auto y = q.front().second;
            q.pop();
            for(int k = 0; k < 4; k++){
                int nx = x + dx[k];
                int ny = y + dy[k];

                if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                    if(grid[nx][ny] == 1) return steps; 
                    if(grid[nx][ny] == 0){
                        grid[nx][ny] = 2;  
                        q.push({nx, ny});
                    }
                }
            }
        }
        steps++;
    }

    return -1; // shouldn't happen
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> grid[i][j];

    int result = shortestBridge(grid);
    cout << result << endl;

    return 0;
}
