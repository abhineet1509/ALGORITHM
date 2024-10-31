#include <iostream>
using namespace std;
#include <vector>
int topdown(int n, vector<int>&dp) {
    if (n <= 1) {
        return n;
    }
    if (dp[n] != -1) { 
        return dp[n];
    }
dp[n] = topdown(n - 1,dp) + topdown(n - 2,dp);
    return dp[n];
}

int main() {
   int n;
   cout<<"number of fibonacci terms:";
   cin>>n;
    vector<int>dp(n + 1, -1); 
    for(int i=0;i<dp.size();i++)
    cout<< topdown(i,dp) << " ";
    return 0;
}
