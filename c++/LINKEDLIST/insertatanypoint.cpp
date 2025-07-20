#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
public:
    void insertAtPos(Node*& head, int pos, int val) {
        Node* newNode = new Node(val);

        if (pos == 0) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* temp = head;
        int k = pos - 1;

        while (temp && k--) temp = temp->next;

        if (!temp) {
            cout << "Position out of bounds\n";
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void print(Node* head) {
        while (head) {
            cout << head->data << " -> ";
            head = head->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    Node* head = nullptr;
    LinkedList l;

    l.insertAtPos(head, 0, 10); // Head
    l.insertAtPos(head, 1, 20); // End
    l.insertAtPos(head, 1, 15); // Middle
    l.insertAtPos(head, 5, 99); // Invalid

    l.print(head);  // Output: 10 -> 15 -> 20 -> NULL

    return 0;
}
