#include <bits/stdc++.h>
using namespace std;

class StockSolutions {
public:
    int maxProfit1(vector<int>& prices) {
        int minPrice = INT_MAX, maxProfit = 0;
        for (int p : prices) {
            minPrice = min(minPrice, p);
            maxProfit = max(maxProfit, p - minPrice);
        }
        return maxProfit;
    }

    int maxProfit2(vector<int>& prices) {
        int profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1])
                profit += prices[i] - prices[i - 1];
        }
        return profit;
    }
    int maxProfitStockIII(vector<int>& prices) {
    int buy1 = INT_MIN, sell1 = 0;
    int buy2 = INT_MIN, sell2 = 0;

    for (int p : prices) {
        buy1  = min(buy1, p);
        sell1 = max(sell1, p + buy1);
        buy2  = min(buy2, sell1 - p);
        sell2 = max(sell2, p + buy2);
    }

    return sell2;
}
    int maxProfit3(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        vector<int> left(n, 0), right(n, 0);

        int minPrice = prices[0];
        for (int i = 1; i < n; i++) {
            minPrice = min(minPrice, prices[i]);
            left[i] = max(left[i-1], prices[i] - minPrice);
        }

        int maxPrice = prices[n-1];
        for (int i = n-2; i >= 0; i--) {
            maxPrice = max(maxPrice, prices[i]);
            right[i] = max(right[i+1], maxPrice - prices[i]);
        }

        int profit = 0;
        for (int i = 0; i < n; i++) {
            profit = max(profit, left[i] + right[i]);
        }
        return profit;
    }

    int maxProfit4(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0 || k == 0) return 0;
        if (k >= n/2) return maxProfit2(prices);

        vector<vector<int>> dp(k+1, vector<int>(n, 0));

        for (int t = 1; t <= k; t++) {
            int maxDiff = -prices[0];
            for (int d = 1; d < n; d++) {
                dp[t][d] = max(dp[t][d-1], prices[d] + maxDiff);
                maxDiff = max(maxDiff, dp[t-1][d] - prices[d]);
            }
        }
        return dp[k][n-1];
    }
};

int main() {
    StockSolutions s;
    vector<int> prices = {7,1,5,3,6,4};

    cout << "Stock I   : " << s.maxProfit1(prices) << "\n";
    cout << "Stock II  : " << s.maxProfit2(prices) << "\n";
    cout << "Stock III : " << s.maxProfit3(prices) << "\n";
    cout << "Stock IV (k=2): " << s.maxProfit4(2, prices) << "\n";

    return 0;
}
