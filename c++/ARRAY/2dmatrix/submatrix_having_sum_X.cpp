#include <bits/stdc++.h>
using namespace std;

// Function to compute number of square submatrices with sum = X
int countSquaresWithSumX(vector<vector<int>>& mat, int X) {
    int n = mat.size();
    int m = mat[0].size();
    
    // Compute prefix sum
    vector<vector<int>> pre(n+1, vector<int>(m+1, 0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            pre[i][j] = mat[i-1][j-1] + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
        }
    }

    int count = 0;
    // Try all square sizes
    for(int sz=1; sz<=min(n,m); sz++){
        for(int i=0;i<=n-sz;i++){
            for(int j=0;j<=m-sz;j++){
                int r1=i, c1=j, r2=i+sz-1, c2=j+sz-1;
                int sum = pre[r2+1][c2+1] - pre[r1][c2+1] - pre[r2+1][c1] + pre[r1][c1];
                if(sum == X) count++;
            }
        }
    }
    return count;
}

int main(){
    vector<vector<int>> mat = {
        {2, 4, 7, 8, 10},
        {3, 1, 1, 1, 1},
        {9, 11, 1, 2, 1},
        {12, -17, 1, 1, 1}
    };
    int X = 10;
    cout << countSquaresWithSumX(mat, X) << endl; // Output: 3
}
