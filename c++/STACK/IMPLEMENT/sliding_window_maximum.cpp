#include <bits/stdc++.h>
using namespace std;

vector<int> slidingWindowMax(vector<int>& a, int k) {
    int n = a.size();
    vector<int> nge(n);
    stack<int> st;

    // Step 1: Compute NGE
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && a[st.top()] <= a[i])
            st.pop();

        nge[i] = st.empty() ? n : st.top();
        st.push(i);
    }

    // Step 2: Sliding window using NGE
    vector<int> ans;
    for (int i = 0; i <= n - k; i++) {
        int j = i;
        while (nge[j] < i + k)
            j = nge[j];

        ans.push_back(a[j]);
    }

    return ans;
}

int main() {
    vector<int> a = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> res = slidingWindowMax(a, k);

    for (int x : res)
        cout << x << " ";

    return 0;
}
