#include <bits/stdc++.h>
using namespace std;

int findMedian(vector<vector<int>>& matrix, int n, int m) {
    int low = 1, high = 1e9;

    int req = (n * m) / 2;
    // int low = matrix[0][0];

    
    //     int high = matrix[0][cols - 1];
    //     for (int i = 1; i < rows; i++) {
    //         low = min(low, matrix[i][0]);
    //         high = max(high, matrix[i][cols - 1]);
    //     }

    while (low <= high) {
        int mid = (low + high) / 2;
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            cnt += upper_bound(matrix[i].begin(), matrix[i].end(), mid)
                   - matrix[i].begin();
        }

        if (cnt <= req)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}
    };

    cout << findMedian(matrix, 3, 3);
}
