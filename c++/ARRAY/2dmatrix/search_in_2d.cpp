#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix1(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int low = 0, high = n * m - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int row = mid / m;
            int col = mid % m;

            if (matrix[row][col] == target)
                return true;
            else if (matrix[row][col] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return false;
    }

    bool searchMatrix2(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int row = 0, col = m - 1;
        while (row < n && col >= 0) {
            if (matrix[row][col] == target)
                return true;
            else if (matrix[row][col] > target)
                col--;
            else
                row++;
        }
        return false;
    }
};

int main() {
    Solution s;

    vector<vector<int>> mat1 = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    vector<vector<int>> mat2 = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };

    int target = 16;

    cout << "Matrix I: " << (s.searchMatrix1(mat1, target) ? "Found" : "Not Found") << endl;
    cout << "Matrix II: " << (s.searchMatrix2(mat2, target) ? "Found" : "Not Found") << endl;

    return 0;
}
