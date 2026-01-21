#include <bits/stdc++.h>
using namespace std;

bool canShip(vector<int>& w, int days, int cap) {
    int usedDays = 1, load = 0;

    for (int x : w) {
        if (load + x <= cap) {
            load += x;
        } else {
            usedDays++;
            load = x;
            if (usedDays > days) return false;
        }
    }
    return true;
}

int shipWithinDays(vector<int>& w, int days) {
    int low = *max_element(w.begin(), w.end());
    int high = accumulate(w.begin(), w.end(), 0);
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canShip(w, days, mid)) {
            ans = mid;
            high = mid - 1;   // minimize capacity
        } else {
            low = mid + 1;
        }
    }
    return ans;
}
