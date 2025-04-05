#include <iostream>
#include <stack>

using namespace std;

// Insert element at bottom of the stack
void insertAtBottom(stack<int> &s, int value) {
    if (s.empty()) {
        s.push(value);
        return;
    }
    int temp = s.top();
    s.pop();
    insertAtBottom(s, value);
    s.push(temp);
}

// Function to reverse the stack using recursion
void reverseStack(stack<int> &s) {
    if (s.empty()) return;
    int temp = s.top();
    s.pop();
    reverseStack(s);
    insertAtBottom(s, temp);
}

// Function to display stack contents
void displayStack(stack<int> s) {
    cout << "Stack elements: ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    cout << "Original Stack:\n";
    displayStack(s);

    reverseStack(s);

    cout << "Reversed Stack:\n";
    displayStack(s);

    return 0;
}
