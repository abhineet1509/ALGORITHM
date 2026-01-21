#include <bits/stdc++.h>
using namespace std;

static const int MOD = 1e9 + 7;


int sumSubarrayMins(vector<int>& arr) {
    int n = arr.size();
    int sum = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int mn = INT_MAX;
            for (int k = i; k <= j; k++) {
                mn = min(mn, arr[k]);
            }
            sum += mn;
        }
    }
    return sum;
}
// we count how many subarrays each element is minimum of.
int sumSubarrayMins(vector<int>& arr) {
    int n = arr.size();
    vector<int> ple(n), nle(n);
    stack<int> st;

    // Previous Less Element (strictly less)
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] > arr[i])
            st.pop();

        ple[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }


    // Clear stack
    while (!st.empty()) st.pop();

    // Next Less Element (less or equal)
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] >= arr[i])
            st.pop();

        nle[i] = st.empty() ? n : st.top();
        st.push(i);
    }

    long long ans = 0;

    for (int i = 0; i < n; i++) {
        long long left = i - ple[i];
        long long right = nle[i] - i;
        ans = (ans + arr[i] * left % MOD * right % MOD) % MOD;
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];      // 0 3 4 5 2 3 4 1 4
                            // 3 1 2
    cout << sumSubarrayMins(arr) << "\n";
    return 0;
}
