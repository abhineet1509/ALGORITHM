#include<bits/stdc++.h> 
using namespace std;

//define our data structure 
class Node {
    public:
    int data;
    Node *next;
    Node(int val){
        data = val;
        next = nullptr;
    }
};

// create our linkes list 
void insertattail(Node *&head,int val){
    if(!head){
        head = new Node(val);
        return;
    }
    Node *temp = head;
    while(temp->next) {
        temp = temp->next;
    }
    temp->next = new Node(val);
}
int main(){
  Node *head = nullptr;
  insertattail(head,1);
insertattail(head,2);
insertattail(head,3);
insertattail(head,4);
insertattail(head,5);
    insertattail(head,6);
    
    Node *odd = head;
    Node *even = head->next;
    Node *evenHead = even; // store the head of even list
    
    while(odd && even && even->next){
        odd->next = even->next; // link odd nodes
        odd = odd->next; // move to next odd node
        even->next = odd ? odd->next : nullptr; // link even nodes
        even = even->next; // move to next even node
    }
    
    odd->next = evenHead; // link end of odd list to head of even list
    
    // Print the modified list
    Node *temp = head;
    while(temp){
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
    
    return 0;



}