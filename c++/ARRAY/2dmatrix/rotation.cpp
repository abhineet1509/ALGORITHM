#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotateMatrix(vector<vector<int>>& mat, int degree) {
        int n = mat.size();
        degree = degree % 360; // handle >360 rotations

        // Normalize negative angles if needed
        if (degree < 0) degree += 360;

        // Perform rotation based on degree
        if (degree == 90) {
            transpose(mat);
            reverseRows(mat);
        }
        else if (degree == 180) {
            reverseRows(mat);
            reverseCols(mat);
        }
        else if (degree == 270) {
            transpose(mat);
            reverseCols(mat);
        }
        else if (degree == 360 || degree == 0) {
            // No rotation needed
            return;
        }
        else {
            cout << "Rotation not supported (use 90, 180, 270, 360)" << endl;
        }
    }

private:
    // Transpose matrix in-place
    void transpose(vector<vector<int>>& mat) {
        int n = mat.size();
        for (int i = 0; i < n; i++) {
            for (int j = i+1 ; j < n; j++) {
               // if(i-j>0)
                swap(mat[i][j], mat[j][i]);
            }
        }
    }

    // Reverse each row
    void reverseRows(vector<vector<int>>& mat) {
        for (auto& row : mat) reverse(row.begin(), row.end());
    }

    // Reverse each column
    void reverseCols(vector<vector<int>>& mat) {
        int n = mat.size();
        for (int j = 0; j < n; j++) {
            for (int i = 0, k = n - 1; i < k; i++, k--) {
                swap(mat[i][j], mat[k][j]);
            }
        }
    }
};

int main() {
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    Solution s;
    int degree;
    cout << "Enter rotation (90 / 180 / 270 / 360): ";
    cin >> degree;

    s.rotateMatrix(mat, degree);

    cout << "\nRotated Matrix:\n";
    for (auto& row : mat) {
        for (auto val : row)
            cout << val << " ";
        cout << endl;
    }

    return 0;
}
