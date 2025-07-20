#include<bits/stdc++.h>
using namespace std;

vector<int> firstNegativeOptimized(vector<int>& arr, int k) {
    int n = arr.size();
    deque<int> dq;
    vector<int> res;

    for (int i = 0; i < n; i++) {
        // Step 1: Add current element if it's negative
        if (arr[i] < 0)
            dq.push_back(i);

        // Step 2: Remove elements out of this window
        if (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        // Step 3: Store result once window size hits k
        if (i >= k - 1) {
            res.push_back(dq.empty() ? 0 : arr[dq.front()]);
        }
    }

    return res;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    vector<int> result = firstNegativeOptimized(v,k);
    
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}