#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Insert node at tail
void insertAtTail(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Print the linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

// Rotate list by k positions
Node* rotateList(Node* head, int k) {
    if (!head || !head->next || k == 0) return head;

    // Find length and last node
    Node* temp = head;
    int len = 1;
    while (temp->next) {   // stops at last node
        temp = temp->next;
        len++;
    }

    // Make circular
    temp->next = head;

    // Normalize k
    k = k % len;
    int steps = len - k;

    // Move to new tail
    Node* newTail = head;
    while (--steps) {
        newTail = newTail->next;
    }

    // New head after newTail
    head = newTail->next;
    newTail->next = nullptr;

    return head;
}

int main() {
    Node* head = nullptr;
    int n, val, k;

    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter values: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        insertAtTail(head, val);
    }

    cout << "Enter k (rotation count): ";
    cin >> k;

    cout << "Original List: ";
    printList(head);

    head = rotateList(head, k);

    cout << "Rotated List: ";
    printList(head);

    return 0;
}
