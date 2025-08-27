#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& arr, int i, int sum, vector<int>& path, vector<vector<int>>& res) {
    if (sum == 0) { 
        res.push_back(path); 
        return; 
    }
    if (i == arr.size() || sum < 0) return;

    // include current element
    path.push_back(arr[i]);
    solve(arr, i+1, sum-arr[i], path, res);
    path.pop_back();

    // exclude current element
    solve(arr, i+1, sum, path, res);
}

int main() {
    vector<int> arr = {2,3,5,6,8,10};
    int sum = 10;
    vector<vector<int>> res;
    vector<int> path;

    solve(arr, 0, sum, path, res);

    cout << "Subsets with sum " << sum << ":\n";
    for (auto& subset : res) {
        for (int x : subset) cout << x << " ";
        cout << "\n";
    }
}
