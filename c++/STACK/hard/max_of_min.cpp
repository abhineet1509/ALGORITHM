#include <bits/stdc++.h>
using namespace std;

vector<int> maxOfMin(vector<int>& arr) {
    int n = arr.size();
    vector<int> left(n), right(n), res(n+1);

    stack<int> s;

    // Previous smaller
    for(int i=0;i<n;i++){
        while(!s.empty() && arr[s.top()] >= arr[i]) s.pop();
        left[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }

    while(!s.empty()) s.pop();

    // Next smaller
    for(int i=n-1;i>=0;i--){
        while(!s.empty() && arr[s.top()] >= arr[i]) s.pop();
        right[i] = s.empty() ? n : s.top();
        s.push(i);
    }

    // Fill result
    for(int i=0;i<n;i++){
        int len = right[i] - left[i] - 1;
        res[len] = max(res[len], arr[i]);
    }

    // Fill remaining
    for(int i=n-1;i>=1;i--)
        res[i] = max(res[i], res[i+1]);

    return vector<int>(res.begin()+1, res.end());
}

int main() {
    vector<int> arr = {10, 20, 30, 50, 10, 70, 30};
    vector<int> ans = maxOfMin(arr);
    for(int x: ans) cout << x << " ";
    cout << endl;
}
