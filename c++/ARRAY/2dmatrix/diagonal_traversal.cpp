#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int n = mat.size(), m = mat[0].size();
    vector<vector<int>> diagonals(n + m - 1);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            diagonals[i + j].push_back(mat[i][j]);

  
      vector<int> ans;
        for(int d = 0; d < diagonals.size(); d++) {
            if(d % 2 == 0)
                reverse(diagonals[d].begin(), diagonals[d].end());
            
            for(int val : diagonals[d])
                ans.push_back(val);
        }

    for (int x : ans) cout << x << " ";
}
