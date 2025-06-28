#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int maxProfit(vector<int>& prices, int K) {
    priority_queue<int> maxHeap(prices.begin(), prices.end());
    long long total = 0;
    const int MOD = 1e9 + 7;

    while (K-- && !maxHeap.empty()) {
        int top = maxHeap.top(); maxHeap.pop();
        total = (total + top) % MOD;

        if (top > 1)
            maxHeap.push(top - 1);
    }

    return total;
}

int main() {
    vector<int> prices = {3, 5};
    int K = 3;
    cout << "Maximum Profit: " << maxProfit(prices, K) << endl;
    return 0;
}
