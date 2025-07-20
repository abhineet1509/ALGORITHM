#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *prev, *next;
    Node(int val) {
        data = val;
        prev = next = NULL;
    }
};

// Insert at position `pos` (0-based)
void insertAtPosition(Node* &head, int pos, int val) {
    Node* newNode = new Node(val);

    if (pos == 0) {
        newNode->next = head;
        if (head) head->prev = newNode;
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp && pos-- > 1)
        temp = temp->next;

    if (!temp) {
        cout << "Position out of range\n";
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next) temp->next->prev = newNode;
    temp->next = newNode;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " <-> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = NULL;

    insertAtPosition(head, 0, 10);  // 10
    insertAtPosition(head, 1, 20);  // 10 <-> 20
    insertAtPosition(head, 1, 15);  // 10 <-> 15 <-> 20
    insertAtPosition(head, 0, 5);   // 5 <-> 10 <-> 15 <-> 20

    printList(head);
    return 0;
}
