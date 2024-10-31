#include <iostream>
using namespace std;
class Stack {
    int* arr;         
    int size;     
    int top;         
public:
    Stack(int size) {
        size = size;
        arr = new int[size];
        top = -1;
    }
    ~Stack() {
        delete[] arr;
    }
    void push(int element) {
        if (top >= size - 1) {
            cout << "Stack overflow\n";
            return;
        }
        arr[++top] = element;
    }
    int pop() {
        if (top < 0) {
            cout << "Stack underflow\n";
            return -1;  
        }
        return arr[top--];
    }
    int peek() const {
        if (top < 0) {
            cout << "Stack is empty\n";
            return -1;
        }
        return arr[top];
    }
    bool isEmpty() const {
        return top < 0;
    }
};

int main() {
    int n,data;
    cout<<"Enter the number of element in stack:";
    cin>>n;
    Stack stack(n);   
    for(int i=0;i<n;i++){
        cin>>data;
        stack.push(data);
    }
    cout << "Top element is " << stack.peek() << "\n";
    while (!stack.isEmpty()) {
        cout << stack.pop() << " ";
    }
     stack.pop(); 
     stack.pop(); 
     stack.pop();  
    return 0;
}
