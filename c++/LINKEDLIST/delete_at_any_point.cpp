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
    void insertAtEnd(Node*& head, int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    void deleteAtPosition(Node*& head, int pos) {
        if (!head) {
            cout << "List is empty\n";
            return;
        }

        if (pos == 0) {
            Node* nextNode = head->next;
            delete head;
            head = nextNode;
            return;
        }

        Node* temp = head;
        int k = pos - 1;

        while (temp && k--) temp = temp->next;

        if (!temp || !temp->next) {
            cout << "Position out of bounds\n";
            return;
        }

        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
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

    l.insertAtEnd(head, 10);
    l.insertAtEnd(head, 20);
    l.insertAtEnd(head, 30);
    l.insertAtEnd(head, 40);
    l.print(head);  // 10 -> 20 -> 30 -> 40 -> NULL

    l.deleteAtPosition(head, 2); // delete 30
    l.print(head);               // 10 -> 20 -> 40 -> NULL

    l.deleteAtPosition(head, 0); // delete 10 (head)
    l.print(head);               // 20 -> 40 -> NULL

    l.deleteAtPosition(head, 5); // invalid
}
