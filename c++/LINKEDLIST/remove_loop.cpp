#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Insert node at end
void insertAtEnd(Node* &head, int val) {
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

// Function to detect and remove loop
void removeLoop(Node* head) {
    Node *slow = head, *fast = head;

    // Step 1: Detect loop
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            // Step 2: Find start of loop
            slow = head;
            if (slow == fast) {
                while (fast->next != slow)
                    fast = fast->next;
            } else {
                while (slow->next != fast->next) {
                    slow = slow->next;
                    fast = fast->next;
                }
            }

            // Step 3: Break the loop
            fast->next = NULL;
            return;
        }
    }
}

// Function to print list (stops after 20 nodes to avoid infinite loop)
void printList(Node* head) {
    int count = 0;
    while (head && count < 20) {
        cout << head->data << " -> ";
        head = head->next;
        count++;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = NULL;

    // Creating linked list
    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtEnd(head, 4);
    insertAtEnd(head, 5);

    // Creating a loop manually: 5 -> 3
    head->next->next->next->next->next = head->next->next;

    // Remove loop
    removeLoop(head);

    // Print list
    printList(head);

    return 0;
}
