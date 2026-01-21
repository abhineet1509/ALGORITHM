#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) {
        data = val;
        next = prev = NULL;
    }
};

// Insert at tail
void insertAtTail(Node* &head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

// Remove duplicates from sorted DLL
Node* removeDuplicates(Node* head) {
    if (!head) return head;

    Node* curr = head;

    while (curr && curr->next) {
        if (curr->data == curr->next->data) {
            Node* dup = curr->next;

            curr->next = dup->next;
            if (dup->next)
                dup->next->prev = curr;

            delete dup;
        } else {
            curr = curr->next;
        }
    }
    return head;
}

// Print DLL
void printDLL(Node* head) {
    while (head) {
        cout << head->data << " <-> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = NULL;

    // Sorted DLL with duplicates
    insertAtTail(head, 1);
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 4);

    cout << "Original DLL:\n";
    printDLL(head);

    head = removeDuplicates(head);

    cout << "After removing duplicates:\n";
    printDLL(head);

    return 0;
}
