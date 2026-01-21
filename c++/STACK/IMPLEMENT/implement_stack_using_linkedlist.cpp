#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data=val;
        next=NULL;
    }
};
class Stack {
private:
    Node* top;
public:
    Stack() {
        top=NULL;
    }
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next =  top ;
        top = newNode;
    }
    int pop() {
        if (top == nullptr) return -1;
        int value = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return value;
    }
    int peek() {
        if (top == nullptr) return -1;
        return top->data;
    }
    bool isEmpty() {
        return top == nullptr;
    }
};

int main() {
    int n,data;
    cout<<"Enter the number of elemnts in the stack:";
    cin>>n;
    Stack s;
    for(int i=0;i<n;i++){
        cin>>data;
        s.push(data);
    }
    while (!s.isEmpty()) {
        cout << s.pop() << " ";
    }
    return 0;
}
