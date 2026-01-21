#include <iostream>
#include <vector>
using namespace std;

// Case 1: Fully row-wise sorted matrix
bool binarySearchMatrix1(const vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) return false;

    int m = matrix.size();
    int n = matrix[0].size();
    int low = 0, high = m * n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        int row = mid / n;
        int col = mid % n;

        if (matrix[row][col] == target)
            return true;
        else if (matrix[row][col] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}

// Case 2: Row and column-wise sorted matrix
bool binarySearchMatrix2(const vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) return false;

    int m = matrix.size();
    int n = matrix[0].size();
    int row = 0, col = n - 1;

    while (row < m && col >= 0) {
        if (matrix[row][col] == target)
            return true;
        else if (matrix[row][col] > target)
            col--;
        else
            row++;
    }
    return false;
}

int main() {
    // Case 1 matrix
    vector<vector<int>> matrix1 = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 50}
    };

    // Case 2 matrix
    vector<vector<int>> matrix2 = {
        {1, 4, 7, 11},
        {2, 5, 8, 12},
        {3, 6, 9, 16},
        {10, 13, 14, 17}
    };

    int target = 16;

    cout << "Case 1 (Fully sorted row-wise): ";
    cout << (binarySearchMatrix1(matrix1, target) ? "Found" : "Not Found") << endl;

    cout << "Case 2 (Row & Column sorted): ";
    cout << (binarySearchMatrix2(matrix2, target) ? "Found" : "Not Found") << endl;

    return 0;
}
