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

    void deleteAtStart(Node*& head) {
        if (!head) {
            cout << "List is empty\n";
            return;
        }
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
    }

    void deleteAtEnd(Node*& head) {
        if (!head) {
            cout << "List is empty\n";
            return;
        }
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next) temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
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
    l.print(head);  // 10 -> 20 -> 30 -> NULL

    l.deleteAtStart(head);
    l.print(head);  // 20 -> 30 -> NULL

    l.deleteAtEnd(head);
    l.print(head);  // 20 -> NULL

    l.deleteAtStart(head);
    l.print(head);  // NULL

    l.deleteAtEnd(head);  // List is empty

    return 0;
}
