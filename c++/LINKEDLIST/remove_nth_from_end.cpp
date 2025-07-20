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

    void print(Node* head) {
        while (head) {
            cout << head->data << " -> ";
            head = head->next;
        }
        cout << "NULL\n";
    }

    Node* removeNthFromEnd(Node* head, int n) {
        // Step 1: Count length
        int len = 0;
        Node* temp = head;
        while (temp) {
            len++;
            temp = temp->next;
        }

        // Step 2: Remove (len - n)th node from start
        if (n > len) return head; // invalid
        if (n == len) { // remove head
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            return head;
        }

        temp = head;
        for (int i = 1; i < len - n; i++) {
            temp = temp->next;
        }

        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;

        return head;
    }
};

int main() {
    Node* head = nullptr;
    LinkedList l;
    l.insertAtEnd(head, 10);
    l.insertAtEnd(head, 20);
    l.insertAtEnd(head, 30);
    l.insertAtEnd(head, 40);
    l.insertAtEnd(head, 50);

    cout << "Original: ";
    l.print(head);

    head = l.removeNthFromEnd(head, 3);  // Deletes 30

    cout << "After Deletion: ";
    l.print(head);

    return 0;
}
