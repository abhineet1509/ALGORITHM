#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Swap nodes in pairs using 3 pointers: prev, first, second
ListNode* swapPairs(ListNode* head) {
    if (!head || !head->next) return head;

    ListNode dummy(0);
    dummy.next = head;  // Dummy node to simplify edge cases
    ListNode* prev = &dummy;

    while (prev->next && prev->next->next) {
        ListNode* first = prev->next;
        ListNode* second = first->next;

        // Perform swap
        first->next = second->next;
        second->next = first;
        prev->next = second;

        // Move prev to next pair
        prev = first;
    }

    return dummy.next;
}

// Insert at end
void insertAtEnd(ListNode*& head, int val) {
    ListNode* newNode = new ListNode(val);
    if (!head) {
        head = newNode;
        return;
    }
    ListNode* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

// Print list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Driver code
int main() {
    ListNode* head = nullptr;

    // Sample input: 1 -> 2 -> 3 -> 4
    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtEnd(head, 4);

    cout << "Original List: ";
    printList(head);

    head = swapPairs(head);

    cout << "Swapped in Pairs: ";
    printList(head);

    return 0;
}
