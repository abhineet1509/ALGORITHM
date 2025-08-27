#include <bits/stdc++.h>
using namespace std;

void printLeftLower(vector<vector<int>>& mat) {
    int n = mat.size();
    cout << "Left Lower Triangle:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) cout << mat[i][j] << " ";
        cout << "\n";
    }
}

void printLeftUpper(vector<vector<int>>& mat) {
    int n = mat.size();
    cout << "Left Upper Triangle:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) cout << mat[i][j] << " ";
        cout << "\n";
    }
}

void printRightLower(vector<vector<int>>& mat) {
    int n = mat.size();
    cout << "Right Lower Triangle:\n";
    for (int i = 0; i < n; i++) {
        for (int j = n - i - 1; j < n; j++) cout << mat[i][j] << " ";
        cout << "\n";
    }
}

void printRightUpper(vector<vector<int>>& mat) {
    int n = mat.size();
    cout << "Right Upper Triangle:\n";
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) cout << mat[i][j] << " ";
        cout << "\n";
    }
}

int main() {
    vector<vector<int>> mat = {
        {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9, 10, 11, 12},
        {13,14, 15, 16}
    };

    printLeftLower(mat);
    printLeftUpper(mat);
    printRightLower(mat);
    printRightUpper(mat);

    return 0;
}
