#include <bits/stdc++.h>
using namespace std;

int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    int maxSum = INT_MIN;

    for (int top = 0; top < rows; ++top) {
        vector<int> colSum(cols, 0);
        for (int bottom = top; bottom < rows; ++bottom) {
            for (int c = 0; c < cols; ++c) colSum[c] += matrix[bottom][c];

            set<int> prefixSums;
            prefixSums.insert(0);
            int currSum = 0;
            for (int sum : colSum) {
                currSum += sum;
                auto it = prefixSums.lower_bound(currSum - k);
                if (it != prefixSums.end()) maxSum = max(maxSum, currSum - *it);
                prefixSums.insert(currSum);
            }
        }
    }

    return maxSum;
}

int main() {
    vector<vector<int>> matrix = {{1,0,1},{0,-2,3}};
    int k = 2;
    cout << "Max sum no larger than k: " << maxSumSubmatrix(matrix, k) << endl; // Output: 2
    return 0;
}
