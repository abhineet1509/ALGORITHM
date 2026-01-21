#include <bits/stdc++.h>
using namespace std;
 // colouring a border
int islandPerimeter(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int perimeter = 0;
    
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 1){
                int edges = 4;
                for(int k = 0; k < 4; k++){
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if(ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == 1){
                        edges--; // shared edge with neighbor
                    }
                }
                perimeter += edges;
            }
        }
    }
    
    return perimeter;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> grid[i][j];
    
    cout << islandPerimeter(grid) << endl;
    return 0;
}
