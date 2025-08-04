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

// Detect and remove loop
void removeLoop(Node* head) {
    if (!head || !head->next) return;

    Node* slow = head;
    Node* fast = head;

    // Step 1: Detect loop
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) break;
    }

    if (slow != fast) {
        cout << "No loop detected.\n";
        return;
    }

    // Step 2: Reset slow to head
    slow = head;

    // Step 3: Move until just before loop start
    while (slow->next != fast->next) {
        slow = slow->next;
        fast = fast->next;
    }

    cout << "Loop removed. Loop started at node with value: "
         << slow->next->data << "\n";
    fast->next = nullptr;  // Break loop
}

// Print linked list safely
void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Driver Code
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

    // Optional: Create loop
    char choice;
    cout << "Do you want to create a loop? (y/n): ";
    cin >> choice;

    if (choice == 'y') {
        int pos;
        cout << "Enter position to connect last node to (1-based index): ";
        cin >> pos;

        Node* loopNode = head;
        for (int i = 1; i < pos && loopNode; i++)
            loopNode = loopNode->next;

        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = loopNode;

        cout << "Loop created at position " << pos << "\n";
    }

    // Remove loop if present
    removeLoop(head);

    cout << "Final Linked List: ";
    printList(head);

    return 0;
}
