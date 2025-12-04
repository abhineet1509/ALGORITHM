#include <bits/stdc++.h>
using namespace std;

bool canPaint(vector<int> &arr, int k, long long limit) {
    long long curr = 0;
    int painters = 1;

    for (int x : arr) {
        if (x > limit) return false;

        if (curr + x <= limit) {
            curr += x;
        } else {
            painters++;
            curr = x;
            if (painters > k) return false;
        }
    }
    return true;
}

long long painterPartition(vector<int> &arr, int k) {
    long long low = *max_element(arr.begin(), arr.end());
    long long high = accumulate(arr.begin(), arr.end(), 0LL);
    long long ans = high;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (canPaint(arr, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {10, 20, 30, 40};
    int k = 2;

    cout << painterPartition(arr, k) << endl;
    return 0;
}
