#include <bits/stdc++.h>
using namespace std;

// Class to handle binary search operations on a matrix
class MatrixSearch {
private:
    vector<vector<int>> matrix; // Store the 2D matrix

    // Helper function: Perform binary search on a 1D vector
    bool binarySearch(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;

        // Binary search loop
        while (low <= high) {
            int mid = (low + high) / 2; // Middle index

            if (nums[mid] == target) {
                return true; // Target found
            } 
            else if (target > nums[mid]) {
                low = mid + 1; // Search in the right half
            } 
            else {
                high = mid - 1; // Search in the left half
            }
        }
        return false; // Target not found
    }

public:
    // Constructor to initialize the matrix
    MatrixSearch(vector<vector<int>>& mat) {
        matrix = mat;
    }

    // Function to search the target in the entire matrix
    bool searchElement(int target) {
        int n = matrix.size(); // Number of rows

        // Loop through each row and apply binary search
        for (int i = 0; i < n; i++) {
            if (binarySearch(matrix[i], target)) {
                return true; // Target found in current row
            }
        }
        return false; // Target not found in any row
    }
};

int main() {
    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };

    MatrixSearch ms(matrix);
    bool found = ms.searchElement(8);

    cout << (found ? "true\n" : "false\n");
}
