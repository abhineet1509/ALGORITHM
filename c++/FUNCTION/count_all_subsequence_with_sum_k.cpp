#include <bits/stdc++.h>
using namespace std;

int countSubsets(int idx, int sum, int k, vector<int>& arr) {
    if (idx == arr.size())
        return (sum == k);

    // take
    int take = countSubsets(idx + 1, sum + arr[idx], k, arr);

    // not take
    int notTake = countSubsets(idx + 1, sum, k, arr);

    return take + notTake;
}

int main() {
    vector<int> arr = {1, 2, 3, 4};
    int k = 5;

    cout << countSubsets(0, 0, k, arr) << endl;

    return 0;
}
