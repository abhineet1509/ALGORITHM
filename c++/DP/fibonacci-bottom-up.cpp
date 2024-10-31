#include <iostream>
#include <vector>
using namespace std;
int bottom_up(int n) {
    if (n <= 1) {
        return n;
    }
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main() {
    int n;
    cout<<"enter the number of  terms:";
    cin>>n;
    for(int i=0;i<n;i++)
    cout<< bottom_up(i) <<" ";
    return 0;
}
