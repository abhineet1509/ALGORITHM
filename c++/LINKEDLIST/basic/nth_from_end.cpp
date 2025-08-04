#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Insert at tail
void insertAtTail(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

// Find length of linked list
int length(Node* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

// Find Nth node from end using length
void nthFromEnd(Node* head, int n) {
    int len = length(head);

    if (n > len) {
        cout << "List has fewer than " << n << " nodes.\n";
        return;
    }

    int steps = len - n;  // steps from head
    Node* temp = head;

    while (steps--) {
        temp = temp->next;
    }

    cout << n << "th node from end is: " << temp->data << "\n";
}

// Print list
void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

// Driver
int main() {
    Node* head = nullptr;
    int n, val;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter values: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        insertAtTail(head, val);
    }

    cout << "Enter N: ";
    int k;
    cin >> k;

    cout << "Linked List: ";
    printList(head);

    nthFromEnd(head, k);

    return 0;
}
