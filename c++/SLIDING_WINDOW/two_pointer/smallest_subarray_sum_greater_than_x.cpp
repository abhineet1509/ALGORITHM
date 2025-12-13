#include <bits/stdc++.h>
using namespace std;

int smallestSubarray(int arr[], int n, int x) {
    int start = 0, sum = 0, ans = INT_MAX;

    for (int end = 0; end < n; end++) {
        sum += arr[end];

        while (sum > x) {
            ans = min(ans, end - start + 1);
            sum -= arr[start];
            start++;
        }
    }
    return ans;
}

int main() {
    int arr[] = {1, 4, 45, 6, 10, 19};
    int n = 6, x = 51;

    int res = smallestSubarray(arr, n, x);
    cout << "Smallest length = " << res;

    return 0;
}
