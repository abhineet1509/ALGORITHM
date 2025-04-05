#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int maximumRectangleScore(vector<vector<int>>& arr) {
    int m = arr.size();
    int n = arr[0].size();
    int maxScore = INT_MIN;

    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 1][j + 1]) {
                maxScore = max(maxScore, arr[i][j]);
            }
        }
    }

    return maxScore == INT_MIN ? 0 : maxScore;
}

int main() {
    int m = 4, n = 4;
    vector<vector<int>> arr(m, vector<int>(n));

    cout << "Enter a 4x4 matrix:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    int result = maximumRectangleScore(arr);
    cout << "Maximum value among identical 2x2 squares: " << result << endl;

    return 0;
}
