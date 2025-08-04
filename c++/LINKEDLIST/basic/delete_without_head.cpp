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

// Print linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

// Delete a node without head pointer
void deleteNode(Node* node) {
    if (!node || !node->next) {
        cout << "Can't delete this node (either NULL or last node).\n";
        return;
    }

    Node* temp = node->next;
    node->data = temp->data;  // Copy data from next
    node->next = temp->next;  // Skip next node
    delete temp;              // Free memory
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

    cout << "Linked List before deletion: ";
    printList(head);

    int pos;
    cout << "Enter position of node to delete (1-based index, not last node): ";
    cin >> pos;

    Node* temp = head;
    for (int i = 1; i < pos && temp; i++) {
        temp = temp->next;
    }

    if (temp) {
        deleteNode(temp);
        cout << "Linked List after deletion: ";
        printList(head);
    } else {
        cout << "Invalid position!\n";
    }

    return 0;
}
