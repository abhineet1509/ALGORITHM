#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

// Rotate list to the right by k positions
Node* rotateRight(Node* head, int k) {
    if (!head || !head->next || k == 0) return head;

    // Step 1: Get length and last node
    int len = 1;
    Node* tail = head;
    while (tail->next) {
        tail = tail->next;
        len++;
    }

    // Step 2: Make it circular
    tail->next = head;

    // Step 3: Find new tail: (len - k % len - 1)th node
    k = k % len;
    int stepsToNewTail = len - k;
    Node* newTail = head;
    while (--stepsToNewTail)
        newTail = newTail->next;

    // Step 4: Set new head and break the circle
    Node* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}

// Insert at end
void insertEnd(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

// Print list
void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

// Demo
int main() {
    Node* head = NULL;
    for (int i = 1; i <= 5; ++i)
        insertEnd(head, i);

    cout << "Original List:\n";
    printList(head);

    int k = 2;
    head = rotateRight(head, k);

    cout << "After rotating right by " << k << ":\n";
    printList(head);

    return 0;
}
