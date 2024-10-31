#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int BottomUp(int amount, const vector<int>& coins) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0; 
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
    int n;
    cout<<"enter coins array size:";
    cin>>n;
    vector<int> coins;
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    int amount;
    cout<<"enter amount:";
    cin>>amount;
    int result = BottomUp(amount, coins);
    cout << result << endl;
    return 0;
}
