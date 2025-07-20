#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val): data(val), next(NULL) {}
};

// Reverse a linked list
Node* reverse(Node* head) {
    Node* prev = NULL, *curr = head;
    while (curr) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Add two reversed linked lists
Node* addLists(Node* l1, Node* l2) {
    Node* dummy = new Node(-1);
    Node* temp = dummy;
    int carry = 0;

    while (l1 || l2 || carry) {
        int sum = carry;
        if (l1) sum += l1->data, l1 = l1->next;
        if (l2) sum += l2->data, l2 = l2->next;

        temp->next = new Node(sum % 10);
        carry = sum / 10;
        temp = temp->next;
    }
    return dummy->next;
}

// Main function
Node* addNumbersForward(Node* l1, Node* l2) {
    l1 = reverse(l1);
    l2 = reverse(l2);
    Node* res = addLists(l1, l2);
    return reverse(res);
}

// Utility function to print list
void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " → ";
        head = head->next;
    }
    cout << endl;
}
int main() {
    // Number 342
    Node* l1 = new Node(3);
    l1->next = new Node(4);
    l1->next->next = new Node(2);

    // Number 465
    Node* l2 = new Node(4);
    l2->next = new Node(6);
    l2->next->next = new Node(5);

    Node* result = addNumbersForward(l1, l2);
    printList(result); // Output: 8 → 0 → 7
}
