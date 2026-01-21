#include <bits/stdc++.h>
using namespace std;

bool canPlace(vector<int>& stalls, int n, int k, int dist) {
    int cows = 1;
    int last = stalls[0];

    for (int i = 1; i < n; i++) {
        if (stalls[i] - last >= dist) {
            cows++;
            last = stalls[i];
            if (cows >= k) return true;
        }
    }
    return false;
}
  //O(n×log(maxDistance))
int aggressiveCowsOptimized(vector<int>& stalls, int n, int k) {
    sort(stalls.begin(), stalls.end());

    int low = 1;
    int high = stalls[n - 1] - stalls[0];
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canPlace(stalls, n, k, mid)) {
            ans = mid;
            low = mid + 1;   // try larger distance
        } else {
            high = mid - 1;
        }
    }
    return ans;
}
int aggressiveCowsBrute(vector<int>& stalls, int n, int k) {
    sort(stalls.begin(), stalls.end());

    int maxDist = stalls[n - 1] - stalls[0];
    int ans = 0;

    for (int d = 1; d <= maxDist; d++) {
        if (canPlace(stalls, n, k, d))
            ans = d;
        else
            break;
    }
    return ans;
}