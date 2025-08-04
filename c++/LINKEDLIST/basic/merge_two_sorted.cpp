#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Insert node at tail
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

// Merge two sorted linked lists
Node* mergeSortedLists(Node* head1, Node* head2) {
    // Dummy node for easier handling
    Node dummy(-1);
    Node* tail = &dummy;

    while (head1 && head2) {
        if (head1->data <= head2->data) {
            tail->next = head1;
            head1 = head1->next;
        } else {
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next;
    }

    // Attach the remaining nodes
    if (head1) tail->next = head1;
    if (head2) tail->next = head2;

    return dummy.next; // skip dummy node
}

int main() {
    Node* head1 = nullptr;
    Node* head2 = nullptr;
    int n1, n2, val;

    cout << "Enter number of nodes in first sorted list: ";
    cin >> n1;
    cout << "Enter values in sorted order: ";
    for (int i = 0; i < n1; i++) {
        cin >> val;
        insertAtTail(head1, val);
    }

    cout << "Enter number of nodes in second sorted list: ";
    cin >> n2;
    cout << "Enter values in sorted order: ";
    for (int i = 0; i < n2; i++) {
        cin >> val;
        insertAtTail(head2, val);
    }

    cout << "\nFirst List: ";
    printList(head1);
    cout << "Second List: ";
    printList(head2);

    Node* mergedHead = mergeSortedLists(head1, head2);

    cout << "\nMerged Sorted List: ";
    printList(mergedHead);

    return 0;
}
