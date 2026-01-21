#include <bits/stdc++.h>
using namespace std;

int countNegatives(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int row = 0, col = m - 1;
    int count = 0;
    
    while(row < n && col >= 0){
        if(grid[row][col] < 0){
            count += (col + 1); // all elements left are negative
            row++;               // move to next row
        } else {
            col--;               // move left
        }
    }
    
    return count;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> grid[i][j];
    
    cout << countNegatives(grid) << endl;
    return 0;
}
