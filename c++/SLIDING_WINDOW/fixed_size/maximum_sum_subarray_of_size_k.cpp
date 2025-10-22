#include <iostream>
#include <vector>
#include <climits>
using namespace std;

pair<int, int> maxMinSumSubarray(vector<int> &v, int n, int k) {
    int sum = 0;
    int maxSum = INT_MIN;
    int minSum = INT_MAX;
    int i = 0, j = 0;

    while (j < n) {
        sum += v[j];

        if (j - i + 1 == k) {
            maxSum = max(maxSum, sum);
            minSum = min(minSum, sum);
            sum -= v[i]; // slide window
            i++;
        }
        j++;
    }

    return {maxSum, minSum};
}

int main() {
    vector<int> v = {2, 1, 5, 1, 3, 2};
    int k = 3;

    pair<int,int> result = maxMinSumSubarray(v, v.size(), k);
    cout << "Maximum sum = " << result.first << endl;
    cout << "Minimum sum = " << result.second << endl;

    return 0;
}
