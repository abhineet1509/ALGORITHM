#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> pascal1(int n) {
    vector<vector<int>> t(n);
    for (int i = 0; i < n; i++) {
        t[i].resize(i + 1);
        t[i][0] = t[i][i] = 1;
        for (int j = 1; j < i; j++)
            t[i][j] = t[i-1][j-1] + t[i-1][j];
    }
    return t;
}

vector<int> pascal2(int r) {
    vector<int> row(r + 1, 1);
    long long val = 1;
    for (int i = 1; i < r; i++) {
        val = val * (r - i + 1) / i;
        row[i] = val;
    }
    return row;
}

int main() {
    int n, r;
    cin >> n >> r;

    auto tri = pascal1(n);
    for (auto &v : tri) {
        for (int x : v) cout << x << " ";
        cout << endl;
    }

    auto row = pascal2(r);
    for (int x : row) cout << x << " ";
}
