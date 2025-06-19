#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int maxChocolates(vector<int>& A, int K) {
    priority_queue<int> maxHeap(A.begin(), A.end());
    long long total = 0;
    const int MOD = 1e9 + 7;

    while (K-- && !maxHeap.empty()) {
        int top = maxHeap.top(); maxHeap.pop();
        total = (total + top) % MOD;
        maxHeap.push(top / 2);
    }

    return total;
}

int main() {
    vector<int> A = {6, 5};
    int K = 3;
    cout << "Maximum chocolates eaten: " << maxChocolates(A, K) << endl;
    return 0;
}
