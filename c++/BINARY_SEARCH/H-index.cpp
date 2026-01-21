#include <bits/stdc++.h>
using namespace std;

/* H-Index I — Unsorted Array */
int hIndex(vector<int>& citations) {
    int n = citations.size();
    vector<int> count(n + 1, 0);

    for (int i = 0; i < n; i++) {
        if (citations[i] >= n) count[n]++;
        else count[citations[i]]++;
    }

    int total = 0;
    for (int i = n; i >= 0; i--) {
        total += count[i];
        if (total >= i) return i;
    }
    return 0;
}

/* H-Index II — Sorted Array */
int hIndexSorted(vector<int>& citations) {
    int n = citations.size();
    int l = 0, r = n - 1;

    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (citations[mid] == n - mid) return n - mid;
        else if (citations[mid] < n - mid) l = mid + 1;
        else r = mid - 1;
    }

    return n - l;
}

int main() {
    // H-Index I example (unsorted)
    vector<int> citations1 = {3,0,6,1,5};
    cout << "H-Index I: " << hIndex(citations1) << endl; // Output: 3

    // H-Index II example (sorted)
    vector<int> citations2 = {0,1,3,5,6};
    cout << "H-Index II: " << hIndexSorted(citations2) << endl; // Output: 3

    return 0;
}
