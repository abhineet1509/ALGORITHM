#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestEqual01Submatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        // Step 1: Convert 0 to -1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0)
                    mat[i][j] = -1;
            }
        }

        int maxArea = 0;

        // Step 2: Fix top row
        for (int top = 0; top < n; top++) {
            vector<int> colSum(m, 0);

            // Step 3: Fix bottom row
            for (int bottom = top; bottom < n; bottom++) {

                // Compress rows into colSum
                for (int c = 0; c < m; c++) {
                    colSum[c] += mat[bottom][c];
                }

                // Step 4: Longest zero-sum subarray
                unordered_map<int, int> firstIndex;
                int prefixSum = 0;
                firstIndex[0] = -1;

                for (int c = 0; c < m; c++) {
                    prefixSum += colSum[c];

                    if (firstIndex.count(prefixSum)) {
                        int width = c - firstIndex[prefixSum];
                        int height = bottom - top + 1;
                        maxArea = max(maxArea, width * height);
                    } else {
                        firstIndex[prefixSum] = c;
                    }
                }
            }
        }
        return maxArea;
    }
};

// ---------------- DRIVER CODE ----------------
int main() {
    vector<vector<int>> mat = {
        {1, 0, 0, 1},
        {0, 1, 1, 0},
        {1, 0, 1, 0}
    };

    Solution sol;
    cout << sol.largestEqual01Submatrix(mat) << endl;

    return 0;
}
