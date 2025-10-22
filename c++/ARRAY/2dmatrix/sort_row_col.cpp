#include <bits/stdc++.h>
using namespace std;

void sortRows(vector<vector<int>>& mat) {
    for (auto& row : mat) {
        sort(row.begin(), row.end()); // sort each row ascending
    }
}

void sortCols(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    for (int j = 0; j < n; j++) {
        vector<int> col;
        for (int i = 0; i < m; i++) col.push_back(mat[i][j]);
        sort(col.begin(), col.end()); // sort each column ascending
        for (int i = 0; i < m; i++) mat[i][j] = col[i];
    }
}

int main() {
    vector<vector<int>> mat = {
        {3, 2, 1},
        {9, 8, 7},
        {6, 4, 5}
    };

    cout << "Original Matrix:\n";
    for (auto& row : mat) {
        for (int x : row) cout << x << " ";
        cout << "\n";
    }

    sortRows(mat);
    cout << "\nAfter Row-wise Sort:\n";
    for (auto& row : mat) {
        for (int x : row) cout << x << " ";
        cout << "\n";
    }

    sortCols(mat);
    cout << "\nAfter Column-wise Sort:\n";
    for (auto& row : mat) {
        for (int x : row) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
