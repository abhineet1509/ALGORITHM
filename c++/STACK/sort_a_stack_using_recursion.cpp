#include <iostream>
#include <stack>
using namespace std;

void sortedInsert(stack<int>& st, int element) {
    if (st.empty() || st.top() <= element) {
        st.push(element);
        return;
    }
    int topElement = st.top();
    st.pop();
    sortedInsert(st, element);
    st.push(topElement);
}

void sortStack(stack<int>& st) {
    if (st.empty()) {
        return;
    }
    int topElement = st.top();
    st.pop();
    sortStack(st);
    sortedInsert(st, topElement);
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
    st.push(3);
    st.push(1);
    st.push(4);
    st.push(2);
    st.push(5);

    cout << "Original Stack: ";
    printStack(st);

    st.push(3);
    st.push(1);
    st.push(4);
    st.push(2);
    st.push(5);

    sortStack(st);

    cout << "Sorted Stack: ";
    printStack(st);

    return 0;
}

