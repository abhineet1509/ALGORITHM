#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int solve(vector<int>& coins, int amount, vector<int>& dp) {
    if (amount == 0) return 0;
    if (amount < 0) return INT_MAX;
    if (dp[amount] != -1) return dp[amount];

    int minCoins = INT_MAX;
    for (int coin : coins) {
        int res = solve(coins, amount - coin, dp);
        if (res != INT_MAX)
            minCoins = min(minCoins, res + 1);
    }

    return dp[amount] = minCoins;
}

int coinChangeMemo(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, -1);
    int res = solve(coins, amount, dp);
    return res == INT_MAX ? -1 : res;
}

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    cout << "Minimum coins: " << coinChangeMemo(coins, amount) << endl;

    return 0;
}
