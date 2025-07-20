#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to merge two sorted linked lists
Node* merge(Node* l1, Node* l2) {
    if (!l1) return l2;
    if (!l2) return l1;

    if (l1->data < l2->data) {
        l1->next = merge(l1->next, l2);
        return l1;
    } else {
        l2->next = merge(l1, l2->next);
        return l2;
    }
}

// Function to find the middle of the linked list
Node* findMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Main merge sort function
Node* sortList(Node* head) {
    if (!head || !head->next) return head;

    // Split the list into halves
    Node* mid = findMiddle(head);
    Node* right = mid->next;
    mid->next = nullptr;

    // Recursively sort each half
    Node* leftSorted = sortList(head);
    Node* rightSorted = sortList(right);

    // Merge the sorted halves
    return merge(leftSorted, rightSorted);
}

// Utility function to print list
void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

// Utility function to append a node at the end
void append(Node*& head, int val) {
    if (!head) {
        head = new Node(val);
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = new Node(val);
}

int main() {
    Node* head = nullptr;
    append(head, 4);
    append(head, 2);
    append(head, 1);
    append(head, 3);

    cout << "Original List: ";
    printList(head);

    head = sortList(head);

    cout << "Sorted List: ";
    printList(head);

    return 0;
}
