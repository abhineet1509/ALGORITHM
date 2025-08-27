#include <iostream>
#include <vector>
using namespace std;

void printSpiral(const vector<vector<int>> &mat) {
    int top = 0;
    int left = 0;
    int bottom = mat.size() - 1;
    if (bottom < 0) return;
    int right = mat[0].size() - 1;

    while (top <= bottom && left <= right) {
        // Traverse top row
        for (int j = left; j <= right; j++)
            cout << mat[top][j] << " ";
        top++;

        // Traverse right column
        for (int i = top; i <= bottom; i++)
            cout << mat[i][right] << " ";
        right--;

        // Traverse bottom row
        if (top <= bottom) {
            for (int j = right; j >= left; j--)
                cout << mat[bottom][j] << " ";
            bottom--;
        }

        // Traverse left column
        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                cout << mat[i][left] << " ";
            left++;
        }
    }
    cout << "\n";
}

int main() {
    vector<vector<int>> mat = {
        {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9, 10, 11, 12},
        {13,14, 15,16}
    };

    cout << "Matrix in Spiral Order:\n";
    printSpiral(mat);
}
