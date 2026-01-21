#include <iostream>
using namespace std;

int josephus(int n, int k) {
    if (n == 1)
        return 0;
    else
        return (josephus(n - 1, k) + k) % n;  // (josephus(n - 1, k) + k-1) % n+1 for 1 -based indexing
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << josephus(n, k) + 1 << endl;
    return 0;
}
