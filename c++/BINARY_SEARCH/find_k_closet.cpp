#include <bits/stdc++.h>
using namespace std;

vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int n = arr.size();
    int left = 0, right = n - k; // leftmost index of window of size k

    while (left < right) {
        int mid = left + (right - left) / 2;
        // Compare distance between x and the edges of window
        if (x - arr[mid] > arr[mid + k] - x) 
            left = mid + 1;
        else
            right = mid;
    }

    return vector<int>(arr.begin() + left, arr.begin() + left + k);
}

int main() {
    vector<int> arr = {1,2,3,4,5};
    int k = 4, x = 3;

    vector<int> ans = findClosestElements(arr, k, x);
    for(int val : ans) cout << val << " "; // Output: 1 2 3 4
    cout << endl;

    return 0;
}
