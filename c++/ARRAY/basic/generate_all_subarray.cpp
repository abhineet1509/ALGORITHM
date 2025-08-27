#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> subarraysNestedLoops(vector<int>& arr) {
    vector<vector<int>> res;
    int n = arr.size();
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++) {
            vector<int> sub;
            for (int k = i; k <= j; k++) sub.push_back(arr[k]);
            res.push_back(sub);
        }
    return res;
}

void helperRecursion(vector<int>& arr, int start, vector<vector<int>>& res) {
    if (start == arr.size()) return;
    for (int end = start; end < arr.size(); end++) {
        vector<int> sub(arr.begin() + start, arr.begin() + end + 1);
        res.push_back(sub);
    }
    helperRecursion(arr, start + 1, res);
}
vector<vector<int>> subarraysRecursion(vector<int>& arr) {
    vector<vector<int>> res;
    helperRecursion(arr, 0, res);
    return res;
}

vector<vector<int>> subarraysPrefixSum(vector<int>& arr) {
    vector<vector<int>> res;
    int n = arr.size();
    vector<int> prefix(n+1, 0);
    for (int i = 0; i < n; i++) prefix[i+1] = prefix[i] + arr[i];
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++) {
            vector<int> sub(arr.begin()+i, arr.begin()+j+1);
            res.push_back(sub);
        }
    return res;
}

int main() {
    vector<int> arr = {1, 2, 3};

    auto res1 = subarraysNestedLoops(arr);
    cout << "Nested Loops:\n";
    for (auto &v : res1) { for (int x : v) cout << x << " "; cout << "\n"; }

    auto res2 = subarraysRecursion(arr);
    cout << "\nRecursion:\n";
    for (auto &v : res2) { for (int x : v) cout << x << " "; cout << "\n"; }

    auto res3 = subarraysPrefixSum(arr);
    cout << "\nPrefix Sum:\n";
    for (auto &v : res3) { for (int x : v) cout << x << " "; cout << "\n"; }

    return 0;
}
