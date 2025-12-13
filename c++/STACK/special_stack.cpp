#include <bits/stdc++.h>
using namespace std;

class SpecialStack {
    stack<int> s, minS;

public:
    void push(int x) {
        s.push(x);
        if (minS.empty() || x <= minS.top())
            minS.push(x);
    }

    void pop() {
        if (s.empty()) return;
        if (s.top() == minS.top())
            minS.pop();
        s.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return minS.top();
    }

    bool empty() {
        return s.empty();
    }
};

// ---------------- Driver ----------------
int main() {
    SpecialStack st;
    st.push(5);
    st.push(2);
    st.push(8);
    st.push(1);

    cout << "Min = " << st.getMin() << "\n"; // 1
    st.pop();  // removes 1
    cout << "Min = " << st.getMin() << "\n"; // 2

    return 0;
}
