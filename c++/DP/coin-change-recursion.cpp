#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int coinChangeRecursive(vector<int>& coins, int amount) {
    if (amount == 0) return 0;
    if (amount < 0) return INT_MAX;

    int minCoins = INT_MAX;
    for (int coin : coins) {
        int res = coinChangeRecursive(coins, amount - coin);
        if (res != INT_MAX)
            minCoins = min(minCoins, res + 1);
    }

    return minCoins;
}

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    int res = coinChangeRecursive(coins, amount);
    cout << "Minimum coins: " << (res == INT_MAX ? -1 : res) << endl;

    return 0;
}
