#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(NULL) {}
};

// ---------------- ITERATIVE REVERSE ----------------
Node* reverseIterative(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    while (curr) {
        Node* next = curr->next;  // store next
        curr->next = prev;        // reverse link
        prev = curr;              // move prev
        curr = next;              // move curr
    }
    return prev;  // new head
}

// ---------------- RECURSIVE REVERSE ----------------
Node* reverseRecursive(Node* head) {
    if (!head || !head->next) 
        return head;  // base case: empty list or last node

    Node* newHead = reverseRecursive(head->next);

    head->next->next = head;  // link back
    head->next = NULL;        // cut old link

    return newHead;           // pass same head up
}

// ---------------- HELPER FUNCTIONS ----------------
void insertAtEnd(Node*& head, int val) {
    if (!head) {
        head = new Node(val);
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = new Node(val);
}

void printList(Node* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// ---------------- DRIVER CODE ----------------
int main() {
    Node* head = NULL;
    // Create list: 1 -> 2 -> 3 -> 4 -> 5
    for (int i = 1; i <= 5; i++) insertAtEnd(head, i);

    cout << "Original list: ";
    printList(head);

    // Iterative Reverse
    Node* iterHead = reverseIterative(head);
    cout << "Reversed list (Iterative): ";
    printList(iterHead);

    // Reverse back using Recursive (to original order)
    Node* recHead = reverseRecursive(iterHead);
    cout << "Reversed list (Recursive): ";
    printList(recHead);

    return 0;
}
