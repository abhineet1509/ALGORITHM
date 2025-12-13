#include <bits/stdc++.h>
using namespace std;

// Function to find max length subarray with sum 0
int maxLenZeroSum(vector<int>& arr) {
    unordered_map<int,int> mp;
    int sum = 0, maxLen = 0;
    for(int i=0;i<arr.size();i++){
        sum += arr[i];
        if(sum == 0) maxLen = i + 1;
        else if(mp.count(sum)) maxLen = max(maxLen, i - mp[sum]);
        else mp[sum] = i;
    }
    return maxLen;
}

int largestZeroSumSubmatrix(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    int maxArea = 0;

    for(int top=0; top<m; top++){
        vector<int> sum(n,0);
        for(int bottom=top; bottom<m; bottom++){
            for(int col=0; col<n; col++){
                sum[col] += mat[bottom][col];
            }
            int width = maxLenZeroSum(sum);
            int area = width * (bottom - top + 1);
            maxArea = max(maxArea, area);
        }
    }

    return maxArea;
}

int main() {
    vector<vector<int>> mat = {
        {1, 2, -3},
        {3, -3, 3},
        {2, -2, 1}
    };
    cout << "Largest area: " << largestZeroSumSubmatrix(mat) << endl;
    return 0;
}
