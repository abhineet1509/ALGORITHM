#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
public:
    // Insert a new node at the head of the list
    void insertAtHead(Node*& head, int val) {
        Node* newNode = new Node(val);
        newNode->next = head; // Handles both base and general case
        head = newNode;
    }

    // Print the entire list
    void printList(Node* head) {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    Node* head = nullptr;      // Initially empty list
    LinkedList list;

    list.insertAtHead(head, 30); // Base case (empty list)
    list.insertAtHead(head, 20);
    list.insertAtHead(head, 10);

    list.printList(head);       // Output: 10 -> 20 -> 30 -> NULL

    return 0;
}
