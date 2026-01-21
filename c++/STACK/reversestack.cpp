#include <iostream>
#include <stack>
 // O(N^2) O(N)
using namespace std;
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


void reverseStack(stack<int> &s) {
    if (s.empty()) return;
    int temp = s.top();
    s.pop();
    reverseStack(s);
    insertAtBottom(s, temp);
}

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
