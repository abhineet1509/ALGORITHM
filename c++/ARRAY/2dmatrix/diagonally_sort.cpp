#include <bits/stdc++.h>
using namespace std;

void diagonalSort(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    unordered_map<int, vector<int>> mp;

    // Step 1: Collect elements by diagonal key (row - col)
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            mp[i - j].push_back(mat[i][j]);
        }
    }

    // Step 2: Sort each diagonal
    for (auto& it : mp) {
        auto& v = it.second;
        if (it.first >= 0) { 
              
                sort(v.begin(), v.end(), greater<int>());
            } else {
            
                sort(v.begin(), v.end());
            }
    }

    // Step 3: Put back sorted values
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            mat[i][j] = mp[i - j].back();
            mp[i - j].pop_back();
        }
    }
}

int main() {
    vector<vector<int>> mat = {
        {3, 3, 1, 1},
        {2, 2, 1, 2},
        {1, 1, 1, 2}
    };

    diagonalSort(mat);

    // Print result
    for (auto& row : mat) {
        for (int x : row) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
