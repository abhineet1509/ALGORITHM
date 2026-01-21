#include <bits/stdc++.h>
using namespace std;

// Brute Force
int nthRootBrute(int n, int m) {
    for (int i = 1; i <= m; i++) {
        if (pow(i, n) == m)
            return i;
    }
    return -1;
}

// Optimized Binary Search
int nthRootOptimized(int n, int m) {
    int low = 1, high = m;

    while (low <= high) {
        int mid = (low + high) / 2;
        double val = pow(mid, n);

        if (val == m)
            return mid;
        else if (val < m)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    int n = 3, m = 27;

    cout << "Brute Force Answer: "
         << nthRootBrute(n, m) << endl;

    cout << "Optimized Answer: "
         << nthRootOptimized(n, m) << endl;
}
