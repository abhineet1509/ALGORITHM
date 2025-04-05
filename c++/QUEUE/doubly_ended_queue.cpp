#include <iostream>
using namespace std;

class Deque {
    int* arr;
    int front, rear, size;

public:
    Deque(int n) {
        size = n;
        arr = new int[size];
        front = -1;
        rear = 0;
    }

    bool isFull() {
        return ((front == 0 && rear == size - 1) || front == rear + 1);
    }

    bool isEmpty() {
        return (front == -1);
    }

    void insertFront(int key) {
        if (isFull()) {
            cout << "Overflow\n";
            return;
        }
        if (front == -1) {
            front = 0;
            rear = 0;
        } else if (front == 0) {
            front = size - 1;
        } else {
            front = front - 1;
        }
        arr[front] = key;
    }

    void insertRear(int key) {
        if (isFull()) {
            cout << "Overflow\n";
            return;
        }
        if (front == -1) {
            front = 0;
            rear = 0;
        } else if (rear == size - 1) {
            rear = 0;
        } else {
            rear = rear + 1;
        }
        arr[rear] = key;
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }
        if (front == rear) {
            front = -1;
            rear = -1;
        } else if (front == size - 1) {
            front = 0;
        } else {
            front = front + 1;
        }
    }

    void deleteRear() {
        if (isEmpty()) {
            cout << "Underflow\n";
            return;
        }
        if (front == rear) {
            front = -1;
            rear = -1;
        } else if (rear == 0) {
            rear = size - 1;
        } else {
            rear = rear - 1;
        }
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Underflow\n";
            return -1;
        }
        return arr[front];
    }

    int getRear() {
        if (isEmpty() || rear < 0) {
            cout << "Underflow\n";
            return -1;
        }
        return arr[rear];
    }
};

int main() {
    Deque dq(5);
    dq.insertRear(5);
    dq.insertRear(10);
    cout << dq.getRear() << endl;
    dq.deleteRear();
    cout << dq.getRear() << endl;
    dq.insertFront(15);
    cout << dq.getFront() << endl;
    dq.deleteFront();
    cout << dq.getFront() << endl;
    return 0;
}
