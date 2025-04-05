#include <iostream>
#include <queue>

using namespace std;

void reverseQueue(queue<int>& q) {
    if (q.empty())
        return;

    int frontElement = q.front();
    q.pop();

    reverseQueue(q);

    q.push(frontElement);
}

void displayQueue(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout << "Original Queue: ";
    displayQueue(q);

    reverseQueue(q);

    cout << "Reversed Queue: ";
    displayQueue(q);

    return 0;
}
