#include<iostream> 
#include<vector>
using namespace std;

class Solution {
public:
    int ncr(int n, int r, vector<vector<int>> &dp) {
        // base case
        if (r == 0 || r == n) return 1; 
        if (dp[n][r] != -1) return dp[n][r]; 

        //relation
        dp[n][r] = ncr(n - 1, r - 1, dp) + ncr(n - 1, r, dp);

        return dp[n][r];
    }

    int nCr(int n, int r) {
        if (r > n) return 0; 
        vector<vector<int>> dp(n + 1, vector<int>(r + 1, -1)); 
        return ncr(n, r, dp);
    }
};
int main(){
    int n,r;
    cin>>n>>r;
    Solution sol;
    cout<<sol.nCr(n,r);
}
