#include <iostream>
using namespace std;

class Queue {
private:
    int* arr;
    int front;
    int rear;
    int capacity;

public:
    // Constructor
    Queue(int size) {
        arr = new int[size];
        capacity = size;
        front = 0;
        rear = -1;
    }

    // Destructor
    ~Queue() {
        delete[] arr;
    }

    // Check if the queue is empty
    bool isEmpty() const {
        return front > rear;
    }

    // Check if the queue is full
    bool isFull() const {
        return rear == capacity - 1;
    }

    // Enqueue operation
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue " << value << "." << endl;
            return;
        }
        arr[++rear] = value;
        cout << value << " enqueued to queue." << endl;
    }

    // Dequeue operation
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1;
        }
        return arr[front++];
    }

    // Peek front element
    int peek() const {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        return arr[front];
    }

    // Display queue elements
    void display() const {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Queue elements: ";
        for (int i = front; i <= rear; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    cout << "Dequeued: " << q.dequeue() << endl;
    q.display();

    cout << "Front element: " << q.peek() << endl;

    return 0;
}
