#include <bits/stdc++.h>
using namespace std;

int m, n;
 //island is surrounded by one
bool dfs(vector<vector<int>>& grid, int i, int j) {
    if(i < 0 || i >= m || j < 0 || j >= n) 
        return false; // touches border → not closed
    if(grid[i][j] == 1) return true; // water → safe

    grid[i][j] = 1; // mark as visited
    bool up = dfs(grid, i-1, j);
    bool down = dfs(grid, i+1, j);
    bool left = dfs(grid, i, j-1);
    bool right = dfs(grid, i, j+1);

    return up && down && left && right;
}

int closedIsland(vector<vector<int>>& grid) {
    m = grid.size();
    n = grid[0].size();
    int count = 0;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j] == 0){
                if(dfs(grid, i, j)) count++;
            }
        }
    }
    return count;
}

int main() {
    vector<vector<int>> grid = {
        {1,1,1,1,0,1,1,1},
        {1,0,0,1,0,1,1,1},
        {1,0,1,1,0,1,0,1},
        {1,1,1,1,1,1,1,1}
    };
    cout << "Number of closed islands: " << closedIsland(grid) << endl;
}
