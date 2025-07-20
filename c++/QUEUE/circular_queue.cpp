#include <bits/stdc++.h>
using namespace std;

class MyQueue {
    int* arr;
    int front, rear, size, capacity;

public:
    MyQueue(int c) {
        capacity = c;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    ~MyQueue() {
        delete[] arr;
    }

    void enqueue(int item) {
        if (size == capacity) {
            cout << "Queue is full\n";
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = item;
        size++;
    }

    void dequeue() {
        if (size == 0) {
            cout << "Queue is empty\n";
            return;
        }
        front = (front + 1) % capacity;
        size--;
    }

    int getFront() {
        if (size == 0) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[front];
    }

    int getRear() {
        if (size == 0) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[rear];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
}; // <-- semicolon was missing here

int main() {
    MyQueue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front: " << q.getFront() << endl;        // Output: 10
    cout << "Rear: " << q.getRear() << endl;          // Output: 30

    q.dequeue();

    cout << "Front after dequeue: " << q.getFront() << endl; // Output: 20
    cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl; // No
    cout << "Is queue full? " << (q.isFull() ? "Yes" : "No") << endl;   // No

    return 0;
}
