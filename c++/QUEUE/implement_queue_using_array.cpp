#include<iostream>
using namespace std;
class Queue{
    int *arr;
    int front,rear,size;
    public:
   
    Queue(int n){
        arr=new int[n];
        front=-1,rear=-1;
        size=n;
    }
bool IsEmpty(){
    return front==-1;
}
bool IsFull(){          
    return rear==size-1;  
}
void push( int x){
    if(IsEmpty()){
        cout<<x<<" pushed into queue first element"<<endl;
        front=rear=0;
        arr[0]=x;
    }
    else if(IsFull()){
        cout<<"queue is overloaded";
        return;
    }
    else {
        rear=rear+1;   //for circular queue rear=(rear+1)%size;
        cout<<x<<" pushed into the queue";
        arr[rear]=x;
    }
}
void pop(){
    if(IsEmpty()){
     cout<<"queue is underflow";
    }
    else {
        if(front==rear)  { front=rear=-1;}
        else front=front+1;   //for circular queue front=(front+1)%size;
    }
}
int start(){
    if(IsEmpty()){
        cout<<"queue is empty";
        return -1;
    }
    else { return arr[front];}
}
};
int main(){
    Queue q(5);
   q.push(3);
   q.push(14);
   q.push(19);
   q.pop();       //3 time pop give output queue is empty
   q.pop(); 
   q.pop();  //we didn't give cout
   cout<<q.start()<<endl;
}