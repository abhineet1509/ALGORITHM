#include <bits/stdc++.h>
using namespace std;

int maxDistToClosest(vector<int>& seats) {
    int n = seats.size();
    int last = -1, ans = 0;

    for (int i = 0; i < n; i++) {
        if (seats[i] == 1) {
            if (last == -1) {
                // leading zeros
                ans = max(ans, i);
            } else {
                // middle zeros
                ans = max(ans, (i - last) / 2);
            }
            last = i;
        }
    }

    // trailing zeros
    ans = max(ans, n - 1 - last);
    return ans;
}

int main() {
    vector<int> seats = {1,0,0,0,1,0,1};
    cout << maxDistToClosest(seats); // Output: 2
    return 0;
}
