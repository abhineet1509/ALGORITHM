#include<iostream> 
using namespace std;

 class Node {
        public:
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
 };
 Node *findmiddle(Node* head) {
        if (!head) return nullptr; // empty list
        Node* slow = head;
        Node* fast = head;
        while (fast && fast->next) {
            slow = slow->next; // move slow by 1
            fast = fast->next->next; // move fast by 2
        }
        return slow; // slow is now at the middle
    }
 Node* insertattail(Node*&head,int x){
        Node* newNode = new Node(x);
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
        return head;
 }
 void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main(){
 Node *head = new Node(1);
insertattail(head,2);
insertattail(head,3);
insertattail(head,4);
insertattail(head,5);
printList(head);
  Node* middle =   findmiddle(head);
  cout << "Middle Element: " << middle->data << endl; // Output: 3
  
}