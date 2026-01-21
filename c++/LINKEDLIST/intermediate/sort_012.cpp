#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
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
}

// Sort 0s,1s,2s in linked list
void sort012(Node* head) {
    int count[3] = {0, 0, 0};
    Node* temp = head;

    // Count 0s,1s,2s
    while (temp) {
        count[temp->data]++;
        temp = temp->next;
    }

    temp = head;
    int i = 0;
    while (temp) {
        if (count[i] == 0) i++;
        temp->data = i;
        count[i]--;
        temp = temp->next;
    }
}

// Display linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = NULL;

    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 0);
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 0);

    cout << "Original List:\n";
    printList(head);

    sort012(head);

    cout << "Sorted List:\n";
    printList(head);

    return 0;
}
