#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int value){
        data=value;
        next=NULL;
    }

};
void tail(Node * &head,int value){
    Node *n=new Node(value);
    if(head==NULL){
        head=n;
        return;
    }
    Node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
   

}
 void display(Node *head){
      Node* temp=head;
      cout<<temp->data<<" ";
      temp=temp->next;
    }
int main (){
Node *head=NULL;
tail(head,1);
display(head);
}