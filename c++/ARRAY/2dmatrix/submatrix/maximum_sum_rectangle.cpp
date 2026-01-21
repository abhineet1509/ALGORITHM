#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSumRectangle(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int maxSum = INT_MIN;

        // Fix top row
        for (int top = 0; top < n; top++) {
            vector<int> colSum(m, 0);

            // Fix bottom row
            for (int bottom = top; bottom < n; bottom++) {

                // Compress rows
                for (int c = 0; c < m; c++)
                    colSum[c] += mat[bottom][c];

                // Kadane on colSum
                int currSum = 0;
                for (int c = 0; c < m; c++) {
                    currSum = max(colSum[c], currSum + colSum[c]);
                    maxSum = max(maxSum, currSum);
                }
            }
        }
        return maxSum;
    }
};

// -------- Driver --------
int main() {
    vector<vector<int>> mat = {
        { 1,  2, -1, -4, -20},
        {-8, -3,  4,  2,   1},
        { 3,  8, 10,  1,   3},
        {-4, -1,  1,  7,  -6}
    };

    Solution sol;
    cout << sol.maxSumRectangle(mat) << endl;

    return 0;
}
