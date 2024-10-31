#include <iostream>
#include <stack>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
bool areStacksEqual(stack<int> stack1, stack<int> stack2) {
    if (stack1.size() != stack2.size()) {
        return false;
    }
    while (!stack1.empty()) {
        if (stack1.top() != stack2.top()) {
            return false; }
        stack1.pop();
        stack2.pop();
    }
    return true;
}

int main() {
    stack<int> stack1, stack2;
  int n,data1;
  cout<<"enter the number of  elements in the stack1:";
  cin>>n;
  f(i,0,n) {cin>>data1;
  stack1.push(data1);}
  int m,data2;
  cout<<"enter the number of elements in the stack2:";
    cin>>m;
    f(i,0,m){
        cin>>data2;
        stack2.push(data2);
    }
    if (areStacksEqual(stack1, stack2)) {
        cout << "The stacks are equal." << endl;
    } else {
        cout << "The stacks are not equal." << endl;
    }

    return 0;
}