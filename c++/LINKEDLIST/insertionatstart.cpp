#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *next;
    node(int value){
        data=value;
        next=NULL;
    }
};
int main(){
    node *head;
    head=NULL;
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    for(int i=0;i<5;i++){
        if(head==NULL){
            head=new node(arr[i]);
        }
        else{
            node *temp;
            temp=new node(arr[i]);
            temp->next=head;
            head=temp;
        }
    }
    node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
}