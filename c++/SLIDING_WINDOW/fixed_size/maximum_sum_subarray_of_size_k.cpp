#include<bits/stdc++.h>
using namespace std;
int maximumSumSubarray(vector<int> &v, int n, int k) {
    int sum = 0;
    int maxSum = INT_MIN;
    int i = 0, j = 0;

    while (j < n) {
        sum += v[j];

        if (j - i + 1 == k) {
            maxSum = max(maxSum, sum);
            sum -= v[i];
            i++;
        }
        j++;
    }

    return maxSum;
}
int main() {
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout << maximumSumSubarray(v, n, k) << endl;
    return 0;
}