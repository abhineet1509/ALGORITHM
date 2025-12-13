#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

bool hasKNodes(Node* head, int k) {
    while (head && k > 0) {
        head = head->next;
        k--;
    }
    return (k == 0);
}

Node* reverseKGroup(Node* head, int k) {
  
    if (!hasKNodes(head, k)) return head;

    Node* curr = head;
    Node* prev = nullptr;
    int count = 0;

    while (curr && count < k) {
        Node* next = curr->next; 
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

   
    if (curr) {
        head->next = reverseKGroup(curr, k);
    }

    return prev; 
}


void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}


int main() {
  
    Node* head = new Node(1);
    Node* temp = head;
    for (int i = 2; i <= 8; i++) {
        temp->next = new Node(i);
        temp = temp->next;
    }

    int k = 3;
    cout << "Original List: ";
    printList(head);

    head = reverseKGroup(head, k);

    cout << "Reversed in groups of " << k << ": ";
    printList(head);

    return 0;
}
