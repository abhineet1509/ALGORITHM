#include <bits/stdc++.h>
using namespace std;

/* -------- Last Stone Weight I (1046) -------- */
int lastStoneWeight1(vector<int>& stones) {
    priority_queue<int> pq;
    for (int x : stones) pq.push(x);

    while (pq.size() > 1) {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        if (a != b) pq.push(a - b);
    }

    return pq.empty() ? 0 : pq.top();
}

/* -------- Last Stone Weight II (1049) -------- */
int lastStoneWeight2(vector<int>& stones) {
    int total = 0;
    for (int x : stones) total += x;

    int target = total / 2;
    vector<bool> dp(target + 1, false);
    dp[0] = true;

    for (int stone : stones) {
        for (int j = target; j >= stone; j--) {
            dp[j] = dp[j] || dp[j - stone];
        }
    }

    for (int j = target; j >= 0; j--) {
        if (dp[j]) return total - 2 * j;
    }

    return 0;
}

/* -------- Main -------- */
int main() {
    vector<int> stones = {2,7,4,1,8,1};

    cout << "Last Stone Weight I: "
         << lastStoneWeight1(stones) << endl;

    cout << "Last Stone Weight II: "
         << lastStoneWeight2(stones) << endl;

    return 0;
}
