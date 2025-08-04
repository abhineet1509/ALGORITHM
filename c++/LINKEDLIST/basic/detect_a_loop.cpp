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

// Print list (for debugging; avoid if loop exists)
void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Detect loop using Floyd's Algorithm
bool detectLoop(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) 
            return true;
    }
    return false;
}

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

    // Optional: Create loop for testing
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
    }

    if (detectLoop(head))
        cout << "Loop detected in the linked list!" << endl;
    else {
        cout << "No loop detected. Linked list is: ";
        printList(head);
    }

    return 0;
}
