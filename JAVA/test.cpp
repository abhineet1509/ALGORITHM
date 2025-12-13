#include<bits/stdc++.h> 
using namespace std;
//create datastructure
class Node{
public:
   int data;
   Node *next;
   Node(int val) : data(val),next(nullptr) {}
};

Node* buildlist(){
    Node* head = nullptr,*tail = nullptr;
    int x ; 
    while(cin>>x && x!=-1){
        Node* newnode = new Node(x);
        if(!head) head = tail = newnode;
        else {
            tail->next = newnode;
            tail=tail->next;
        }
    }
    return head;
}
void printlist(Node *head){
    Node *temp = head;
    while(temp!=nullptr){
        cout<< temp->data << "->";
        temp= temp->next;
    }
}
//detect loop
bool detectloop(Node *head){
    Node *slow = head,*fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast= fast->next->next;
        if(slow == fast){
            return true;
        }
    }
  return false;
}
Node* rotate(Node* head, int n){
    Node *temp  = head;
    while(temp->next!=nullptr) temp = temp->next;
    temp->next = head;
    temp = head;
    while(n-->1){
       temp= temp->next;
    }
    head = temp->next;
    temp->next = nullptr;
    return head;
}
void removeloop(Node *head){
     Node *slow = head,*fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast= fast->next->next;
        if(slow == fast){
           break;
        }
    }
  if(slow!=fast){
    cout<< "no loop detected";
    return;
  }
  slow = head;
  while(slow->next != fast->next) {
    slow = slow->next;
    fast = fast->next;
  }
  fast->next = nullptr;
}
int main(){
    Node* head = buildlist();
   // printlist(head);
    // char c;
    // cin >> c;
    // if(c == 'y') {
    //     int pos;
    //     cin>>pos;
    //     Node* loopnode = head;
    //     for(int i=1;i<pos && loopnode!=nullptr;i++) loopnode = loopnode->next;
    //     Node *temp = head;
    //     while(temp->next!=NULL){
    //         temp = temp->next;
    //     }
    //     temp->next = loopnode;
    // }
    // if(detectloop(head)) {
    //     cout<< "loop detected"<<endl;
    //     removeloop(head);
    //     }
    // else cout<<"not detcted"<<endl;
   
    head = rotate(head,3);
    printlist(head);
}