#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0, high = m - 1;

        while (low <= high) {
            int mid = (low + high) / 2;

            int maxRow = 0;
            for (int i = 0; i < n; i++) {
                if (mat[i][mid] > mat[maxRow][mid])
                    maxRow = i;
            }

            int left = (mid - 1 >= 0) ? mat[maxRow][mid - 1] : -1;
            int right = (mid + 1 < m) ? mat[maxRow][mid + 1] : -1;

            if (mat[maxRow][mid] >= left && mat[maxRow][mid] >= right)
                return {maxRow, mid};
            else if (left > mat[maxRow][mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        return {-1, -1};
    }
};

int main() {
    vector<vector<int>> mat = {
        {10, 20, 15},
        {21, 30, 14},
        {7, 16, 32}
    };

    Solution obj;
    vector<int> peak = obj.findPeakGrid(mat);
    cout << peak[0] << " " << peak[1];
}
