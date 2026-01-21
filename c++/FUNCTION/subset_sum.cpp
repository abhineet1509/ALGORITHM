#include <bits/stdc++.h>
using namespace std;

bool subsetSum(int idx, int sum, int k, vector<int>& arr) {
    if (idx == arr.size())
        return sum == k;

    // take
    if (subsetSum(idx + 1, sum + arr[idx], k, arr))
        return true;

    // not take
    if (subsetSum(idx + 1, sum, k, arr))
        return true;

    return false;
}

int countSubsetSum(int idx, int sum, int k, vector<int>& arr) {
    if (idx == arr.size())
        return (sum == k);

    // take
    int take = countSubsetSum(idx + 1, sum + arr[idx], k, arr);

    // not take
    int notTake = countSubsetSum(idx + 1, sum, k, arr);

    return take + notTake;
}
int main() {
    vector<int> arr = {1, 2, 3, 4};
    int k = 5;

    cout << (subsetSum(0, 0, k, arr) ? "YES" : "NO");
    return 0;
}
