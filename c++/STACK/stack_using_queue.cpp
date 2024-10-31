#include <iostream>
#include <queue>
using namespace std;
class StackUsingQueues {
private:
    queue<int> queue1, queue2;

public:
    void push(int x) {
        queue1.push(x);}
    int pop() {
        if (queue1.empty()) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        while (queue1.size() > 1) {
            queue2.push(queue1.front());
            queue1.pop();
        }
        int poppedElement = queue1.front();
        queue1.pop();
        swap(queue1, queue2);

        return poppedElement;
    }
    int top() {
        if (queue1.empty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        while (queue1.size() > 1) {
            queue2.push(queue1.front());
            queue1.pop();
        }
        int topElement = queue1.front();
        queue2.push(queue1.front());
        queue1.pop();
        swap(queue1, queue2);

        return topElement;
    }
    bool empty() {
        return queue1.empty();
    }
};

int main() {
    StackUsingQueues stack;
int n,data;
cout<<"enter  the number of elements you want to push in stack"<<endl;
cin>>n;
  for(int i=0;i<n;i++){
  cin>>data;
  stack.push(data);
  }
        cout << "Top element: " << stack.top() << endl; 
        cout << "Popped element: " << stack.pop() << endl; 
        cout << "Popped element: " << stack.pop() << endl; 
        cout << "Top element after pop: " << stack.top() << endl;  
        cout << "Is stack empty? " << (stack.empty() ? "Yes" : "No") << endl; 


    return 0;
}
