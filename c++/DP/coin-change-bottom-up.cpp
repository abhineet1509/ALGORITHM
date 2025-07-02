#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int coinChangeTabulation(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;  // Base case

    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (i - coin >= 0 && dp[i - coin] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    cout << "Minimum coins: " << coinChangeTabulation(coins, amount) << endl;

    return 0;
}
