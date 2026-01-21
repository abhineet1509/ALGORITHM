#include <bits/stdc++.h>
using namespace std;

void reverseRows(vector<vector<int>>& mat) {
    for (auto &row : mat) {
        reverse(row.begin(), row.end());
    }
}

void reverseCols(vector<vector<int>>& mat) {
   int n = mat.size();
    int m = mat[0].size();
    for (int j = 0; j < m; j++) {
        int top = 0, bottom = n - 1;
        while (top < bottom) {
            swap(mat[top][j], mat[bottom][j]); // reverse each column
            top++;
            bottom--;
        }
    }
}
void reverseRows(int mat[][3], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m / 2; j++) {
            swap(mat[i][j], mat[i][m - 1 - j]);
        }
    }
}

void reverseCols(int mat[][3], int n, int m) {
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n / 2; i++) {
            swap(mat[i][j], mat[n - 1 - i][j]);
        }
    }
}

void printMatrix(const vector<vector<int>>& mat) {
    for (auto &row : mat) {
        for (auto x : row) cout << x << " ";
        cout << "\n";
    }
    cout << "\n";
}

int main() {
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Original:\n";
    printMatrix(mat);

    reverseRows(mat);
    cout << "After reversing rows:\n";
    printMatrix(mat);

    reverseCols(mat);
    cout << "After reversing columns:\n";
    printMatrix(mat);
}
