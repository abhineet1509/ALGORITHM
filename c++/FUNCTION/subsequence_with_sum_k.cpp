#include <bits/stdc++.h>
using namespace std;

bool isSubsetSum(int idx, int sum, int k, vector<int>& arr) {
    if (idx == arr.size())
        return sum == k;

    // take
    if (isSubsetSum(idx + 1, sum + arr[idx], k, arr))
        return true;

    // not take
    if (isSubsetSum(idx + 1, sum, k, arr))
        return true;

    return false;
}

int main() {
    vector<int> arr = {1, 2, 3, 4};
    int k = 5;

    if (isSubsetSum(0, 0, k, arr))
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
