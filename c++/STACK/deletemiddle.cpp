#include <iostream>
#include <stack>
using namespace std;

void deleteMiddle(stack<int>& st, int curr, int mid) {
    if (st.empty()) return;

    int topElement = st.top();
    st.pop();

    // Reached the middle element
    if (curr == mid) {
        return; // Do not push this back
    }

    deleteMiddle(st, curr + 1, mid);
    st.push(topElement); // Push back during backtrack
}

void deleteMiddleElement(stack<int>& st) {
    int n = st.size();
    int mid = n / 2;
    deleteMiddle(st, 0, mid);
}

void printStack(stack<int> st) {
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);  // Top of stack

    deleteMiddleElement(st);

    printStack(st);  // Output: 5 4 2 1
}
