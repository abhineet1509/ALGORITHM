#include <bits/stdc++.h>
using namespace std;

// O(n^2) Brute Force
bool equilibriumBrute(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        int left = accumulate(arr.begin(), arr.begin() + i, 0);
        int right = accumulate(arr.begin() + i + 1, arr.end(), 0);
        if (left == right) return true;
    }
    return false;
}

// O(n) Optimal
bool equilibriumOptimal(vector<int>& arr) {
    int total = accumulate(arr.begin(), arr.end(), 0), left = 0;
    for (int i = 0; i < arr.size(); i++) {
        int right = total - left - arr[i];
        if (left == right) return true;
        left += arr[i];
    }
    return false;
}

int main() {
    vector<int> arr = {1, 3, 5, 2, 2};

    cout << "Brute Force: " << (equilibriumBrute(arr) ? "true" : "false") << "\n";
    cout << "Optimal: "     << (equilibriumOptimal(arr) ? "true" : "false") << "\n";
}
