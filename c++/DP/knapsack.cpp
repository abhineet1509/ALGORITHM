#include <bits/stdc++.h>
using namespace std;

int knapsack(int W, vector<int>& wt, vector<int>& val, int n) {
    if (n == 0 || W == 0) return 0;

    if (wt[n - 1] > W)
        return knapsack(W, wt, val, n - 1); 
    else
        return max(
            val[n - 1] + knapsack(W - wt[n - 1], wt, val, n - 1), // include
            knapsack(W, wt, val, n - 1)                            // exclude
        );
}

struct Item {
    int value;
    int weight;
};


bool cmp(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, vector<Item>& items) {
    sort(items.begin(), items.end(), cmp);

    double totalValue = 0.0;
    for (auto item : items) {
        if (W == 0) break;

        if (item.weight <= W) {
            W -= item.weight;
            totalValue += item.value;
        } else {
            totalValue += (double)item.value * W / item.weight;
            W = 0;
        }
    }
    return totalValue;
}

int main() {
    int n, W;
    cin >> n >> W;
    vector<int> val(n), wt(n);
    for (int i = 0; i < n; i++)
        cin >> val[i] >> wt[i];  
        //  vector<Item> items(n);
        //for (int i = 0; i < n; i++)
       // cin >> items[i].value >> items[i].weight;


    int maxValue = knapsack(W, wt, val, n);
    cout << maxValue << endl;
}
