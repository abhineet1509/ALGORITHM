#include <bits/stdc++.h>
using namespace std;

vector<int> minCoins(int N) {
    vector<int> nums{1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    vector<int> res;
    
    for(int i = nums.size() - 1; i >= 0; i--) {
        while(N >= nums[i]) {  // Use as many of the current coin as possible
            N -= nums[i];
            res.push_back(nums[i]);
        }
    }
    return res;
}

int main() {
    int N = 43;  // Example input
    vector<int> result = minCoins(N);

    cout << "Minimum coins required: ";
    for(int coin : result) {
        cout << coin << " ";
    }
    return 0;
}
