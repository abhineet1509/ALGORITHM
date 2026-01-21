#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v) : val(v), next(NULL) {}
};

// Function to delete middle node (second middle for even length)
ListNode* deleteMiddle(ListNode* head) {
    if (!head) return NULL;          // empty list
    if (!head->next) {               // only one node
        delete head;
        return NULL;
    }

    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = NULL;

    while (fast && fast->next) {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }

    // slow points to middle (or second middle if even)
    prev->next = slow->next;
    delete slow;

    return head;
}

// Helper: Insert at tail
void insertAtTail(ListNode* &head, int val) {
    ListNode* newNode = new ListNode(val);
    if (!head) {
        head = newNode;
        return;
    }
    ListNode* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

// Helper: Print linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << "\n";
}

int main() {
    ListNode* head = NULL;

    // Example 1: Odd length
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);

    cout << "Original List (Odd length):\n";
    printList(head);

    head = deleteMiddle(head);
    cout << "After deleting middle:\n";
    printList(head);

    // Example 2: Even length
    ListNode* head2 = NULL;
    insertAtTail(head2, 10);
    insertAtTail(head2, 20);
    insertAtTail(head2, 30);
    insertAtTail(head2, 40);

    cout << "\nOriginal List (Even length):\n";
    printList(head2);

    head2 = deleteMiddle(head2);
    cout << "After deleting second middle:\n";
    printList(head2);

    return 0;
}
