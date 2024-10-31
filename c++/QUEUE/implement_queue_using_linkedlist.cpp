#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        data=value;
        next=NULL;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;
public:
    Queue() {
        front=rear=NULL;
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (rear == NULL) {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    void dequeue() {
        if (front == NULL) return;
        Node* temp = front;
        front = front->next;
        if (front == NULL) rear = NULL;
        delete temp;
    }

    int peek() {
        if (front == NULL) throw "Queue is empty";
        return front->data;
    }

    bool isEmpty() {
        return front == NULL;
    }
};

int main() {
    Queue q;
   int n,data;
   cout<<"Enter the number of elements in the queue:";
   cin>>n;
   for(int i=0;i<n;i++){
    cin>>data;
    q.enqueue(data);
   }
    cout << "Front element is: " << q.peek() << endl;
    q.dequeue();
    cout << "Front element after dequeue is: " << q.peek() << endl;
    return 0;
}
