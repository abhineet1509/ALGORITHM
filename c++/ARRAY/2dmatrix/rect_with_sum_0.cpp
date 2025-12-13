#include <bits/stdc++.h>
using namespace std;

// Returns the length of the largest subarray with sum 0
int maxLenZeroSum(vector<int>& arr) {
    unordered_map<int,int> mp;
    int sum=0, maxLen=0;
    for(int i=0;i<arr.size();i++){
        sum += arr[i];
        if(sum==0) maxLen = i+1;
        if(mp.find(sum)!=mp.end()) maxLen = max(maxLen, i - mp[sum]);
        else mp[sum] = i;
    }
    return maxLen;
}

// Largest rectangular sub-matrix with sum 0
int largestRectZeroSum(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    int maxArea = 0;

    for(int top=0; top<n; top++){
        vector<int> temp(m,0);
        for(int bottom=top; bottom<n; bottom++){
            for(int col=0; col<m; col++)
                temp[col] += mat[bottom][col];

            int width = maxLenZeroSum(temp);
            maxArea = max(maxArea, width * (bottom - top + 1));
        }
    }
    return maxArea;
}

int main() {
    vector<vector<int>> mat = {
        {1, 2, -3},
        {4, -4, 0},
        {1, -1, 1}
    };

    cout << "Largest rectangular sub-matrix with sum 0 area: " 
         << largestRectZeroSum(mat) << endl;
}
