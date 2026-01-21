#include <bits/stdc++.h>
using namespace std;

// Function to find max length zero-sum subarray
// Returns pair: {maxWidth, startingColumnIndex}
pair<int,int> maxLenZeroSum(vector<int>& arr) {
    unordered_map<int,int> mp;
    int sum = 0, maxLen = 0, startIdx = -1;

    for(int i = 0; i < arr.size(); i++){
        sum += arr[i];
        if(sum == 0){    // sum==x
            if(i + 1 > maxLen){
                maxLen = i + 1;
                startIdx = 0;
            }
        } else if(mp.count(sum)){    //sum-x
            if(i - mp[sum] > maxLen){
                maxLen = i - mp[sum]; // mp[sum-x]
                startIdx = mp[sum] + 1;
            }
        } else mp[sum] = i;
    }
    return {maxLen, startIdx};
}

// Function to find and print largest zero-sum submatrix
void largestZeroSumSubmatrix(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    int maxArea = 0;
    int topRow, bottomRow, leftCol, rightCol;

    for(int top = 0; top < m; top++){
        vector<int> sum(n, 0);
        for(int bottom = top; bottom < m; bottom++){
            for(int col = 0; col < n; col++)
                sum[col] += mat[bottom][col];

            pair<int,int> res = maxLenZeroSum(sum); 
            int width = res.first;
            int startCol = res.second;
            int area = width * (bottom - top + 1);

            if(area > maxArea){
                maxArea = area;
                topRow = top;
                bottomRow = bottom;
                leftCol = startCol;
                rightCol = startCol + width - 1;
            }
        }
    }

    cout << "Largest area: " << maxArea << endl;
    cout << "Submatrix elements:" << endl;
    for(int i = topRow; i <= bottomRow; i++){
        for(int j = leftCol; j <= rightCol; j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> mat = {
        {1, 2, -3},
        {3, -3, 3},
        {2, -2, 1}
    };

    largestZeroSumSubmatrix(mat);

    return 0;
}
