#include <bits/stdc++.h>
using namespace std;
//SPECIAL STACK
class MinStack {
    stack<int> st;
    stack<int> mn;

public:
    MinStack() {}

    void push(int val) {
        st.push(val);
        if (mn.empty() || val <= mn.top())
            mn.push(val);
    }

    void pop() {
        if (st.top() == mn.top())
            mn.pop();
        st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return mn.top();
    }
};

int main() {
    MinStack ms;

    ms.push(5);
    ms.push(3);
    ms.push(7);
    cout << "Min: " << ms.getMin() << endl;

    ms.pop();
    cout << "Min after pop: " << ms.getMin() << endl;

    ms.pop();
    cout << "Top: " << ms.top() << endl;
    cout << "Min: " << ms.getMin() << endl;

    return 0;
}
