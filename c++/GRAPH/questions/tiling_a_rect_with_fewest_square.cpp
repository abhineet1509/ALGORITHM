#include <bits/stdc++.h>
using namespace std;

class Solution {
    int res = INT_MAX;
public:
    void dfs(vector<vector<int>>& grid, int filled) {
        int n = grid.size(), m = grid[0].size();
        
        // find first empty cell
        int i=-1,j=-1;
        bool done = true;
        for(int r=0;r<n;r++){
            for(int c=0;c<m;c++){
                if(grid[r][c]==0){
                    i=r; j=c; 
                    done = false; 
                    break;
                }
            }
            if(!done) break;
        }
        
        if(done){
            res = min(res, filled);
            return;
        }
        
        // try placing largest possible square
        int maxSize = min(n-i, m-j);
        for(int sz = maxSize; sz>=1; sz--){
            bool canPlace = true;
            for(int r=i; r<i+sz && canPlace; r++)
                for(int c=j; c<j+sz && canPlace; c++)
                    if(grid[r][c]!=0) canPlace = false;
            
            if(canPlace){
                // place square
                for(int r=i;r<i+sz;r++)
                    for(int c=j;c<j+sz;c++)
                        grid[r][c]=1;
                
                dfs(grid, filled+1);
                
                // backtrack
                for(int r=i;r<i+sz;r++)
                    for(int c=j;c<j+sz;c++)
                        grid[r][c]=0;
            }
        }
    }
    
    int tilingRectangle(int n, int m) {
        vector<vector<int>> grid(n, vector<int>(m,0));
        dfs(grid,0);
        return res;
    }
};

int main(){
    Solution sol;
    cout << sol.tilingRectangle(2,3) << endl; // Output: 3
}
