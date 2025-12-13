#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    vector<int> dirs = {0, 1, 0, -1, 0};

    int dfs(vector<vector<int>>& grid, int i, int j, int id) {
        if(i<0 || i>=n || j<0 || j>=n || grid[i][j]!=1) return 0;
        grid[i][j] = id;
        int size = 1;
        for(int k=0;k<4;k++){
            int x = i + dirs[k];
            int y = j + dirs[k+1];
            size += dfs(grid, x, y, id);
        }
        return size;
    }

    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        unordered_map<int,int> area;
        int id = 2;
        int res = 0;

        // Label each island and record its area
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int sz = dfs(grid,i,j,id);
                    area[id] = sz;
                    res = max(res, sz);
                    id++;
                }
            }
        }

        // Try flipping 0 to 1
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    unordered_set<int> seen;
                    int cur = 1;
                    for(int k=0;k<4;k++){
                        int x = i + dirs[k];
                        int y = j + dirs[k+1];
                        if(x>=0 && x<n && y>=0 && y<n && grid[x][y]>1){
                            if(seen.count(grid[x][y])==0){
                                cur += area[grid[x][y]];
                                seen.insert(grid[x][y]);
                            }
                        }
                    }
                    res = max(res, cur);
                }
            }
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {
        {1,0,1},
        {1,1,0},
        {0,1,1}
    };
    cout << sol.largestIsland(grid) << endl; 
    return 0;
}
