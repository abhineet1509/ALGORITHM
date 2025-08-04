#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Utility to check if k nodes exist from head
bool hasKNodes(Node* head, int k) {
    while (head && k > 0) {
        head = head->next;
        k--;
    }
    return (k == 0);
}

Node* reverseKGroup(Node* head, int k) {
    // Base case: if less than k nodes remain, return as is
    if (!hasKNodes(head, k)) return head;

    Node* curr = head;
    Node* prev = nullptr;
    int count = 0;

    // Reverse first k nodes
    while (curr && count < k) {
        Node* next = curr->next; // defined inside loop
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // Recurse for remaining nodes
    if (curr) {
        head->next = reverseKGroup(curr, k);
    }

    return prev; // new head after reversal
}

// Helper to print the list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Driver
int main() {
    // Creating a sample linked list: 1->2->3->4->5->6->7->8
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
