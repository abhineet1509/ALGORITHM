#include <bits/stdc++.h>
using namespace std;

queue<int> reverseK(queue<int> q, int k) {
    stack<int> st;

    // Reverse first k elements
    for (int i = 0; i < k; i++) {
        st.push(q.front());
        q.pop();
    }

    // Push reversed back
    while (!st.empty()) {
        q.push(st.top());
        st.pop();
    }

    // Move remaining elements to maintain order
    int rem = q.size() - k;
    while (rem--) {
        q.push(q.front());
        q.pop();
    }

    return q;
}

int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    int k = 4;

    queue<int> ans = reverseK(q, k);

    cout << "Output: ";
    while (!ans.empty()) {
        cout << ans.front() << " ";
        ans.pop();
    }

    return 0;
}
