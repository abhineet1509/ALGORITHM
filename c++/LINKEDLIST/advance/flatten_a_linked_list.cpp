#include <bits/stdc++.h>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

// Merge two sorted bottom-linked lists
Node* merge(Node* a, Node* b) {
    Node* dummy = new Node(-1);
    Node* temp = dummy;

    while (a && b) {
        if (a->data < b->data) {
            temp->bottom = a;
            a = a->bottom;
        } else {
            temp->bottom = b;
            b = b->bottom;
        }
        temp = temp->bottom;
    }

    if (a) temp->bottom = a;
    else temp->bottom = b;

    return dummy->bottom;
}

// Flatten function
Node* flatten(Node* root) {
    if (root == NULL || root->next == NULL)
        return root;

    root->next = flatten(root->next);
    root = merge(root, root->next);

    return root;
}

// Print flattened list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->bottom;
    }
    cout << endl;
}

int main() {
    /*
        List structure:
        5 -> 10 -> 19 -> 28
        |    |     |     |
        7    20    22    35
        |          |     |
        8          50    40
        |                |
        30               45
    */

    Node* head = new Node(5);
    head->bottom = new Node(7);
    head->bottom->bottom = new Node(8);
    head->bottom->bottom->bottom = new Node(30);

    head->next = new Node(10);
    head->next->bottom = new Node(20);

    head->next->next = new Node(19);
    head->next->next->bottom = new Node(22);
    head->next->next->bottom->bottom = new Node(50);

    head->next->next->next = new Node(28);
    head->next->next->next->bottom = new Node(35);
    head->next->next->next->bottom->bottom = new Node(40);
    head->next->next->next->bottom->bottom->bottom = new Node(45);

    Node* result = flatten(head);

    cout << "Flattened Linked List:\n";
    printList(result);

    return 0;
}
