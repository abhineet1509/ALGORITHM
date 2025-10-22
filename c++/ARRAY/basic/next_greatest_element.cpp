#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreatestElement(const vector<int>& arr) {
    int n = arr.size();
    vector<int> res(n, -1);
    int maxRight = INT_MIN;

    for (int i = n - 1; i >= 0; --i) {
        if (maxRight > arr[i]) res[i] = maxRight;
        else res[i] = -1;
        if (arr[i] > maxRight) maxRight = arr[i];
    }
    return res;
}

int main() {
    vector<int> arr = {7,1,5,3,6,4};
    vector<int> ans = nextGreatestElement(arr);
    for (int x : ans) cout << x << " ";
    cout << "\n"; // output: -1 6 6 6 -1 -1
    return 0;
}
