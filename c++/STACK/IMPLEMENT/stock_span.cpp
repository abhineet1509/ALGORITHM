#include <bits/stdc++.h>
using namespace std;

vector<int> stockSpan(vector<int>& price) {
    int n = price.size();
    vector<int> span(n);
    stack<int> st; // stores indices

    for (int i = 0; i < n; i++) {
        while (!st.empty() && price[st.top()] <= price[i])
            st.pop();

        span[i] = st.empty() ? (i + 1) : (i - st.top());
        st.push(i);
    }

    return span;
}

int main() {
    vector<int> price = {100, 80, 60, 70, 60, 75, 85};

    vector<int> span = stockSpan(price);

    for (int x : span)
        cout << x << " ";

    return 0;
}
