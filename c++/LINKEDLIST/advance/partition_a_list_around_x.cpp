#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* partition(ListNode* head, int x) {
    // Dummy heads for before and after lists
    ListNode* beforeHead = new ListNode(0);
    ListNode* afterHead = new ListNode(0);

    ListNode* before = beforeHead;
    ListNode* after = afterHead;
    ListNode* current = head;

    while (current != NULL) {
        if (current->val < x) {
            before->next = current;
            before = before->next;
        } else {
            after->next = current;
            after = after->next;
        }
        current = current->next;
    }

    after->next = NULL;           // terminate after list
    before->next = afterHead->next; // connect two lists

    return beforeHead->next;
}

// Helper function to print the list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Example usage
int main() {
    // Creating the linked list: 1->4->3->2->5->2
    ListNode* head = new ListNode(1);
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(2);

    int x = 3;
    cout << "Original list: ";
    printList(head);

    ListNode* result = partition(head, x);

    cout << "Partitioned list around " << x << ": ";
    printList(result);

    return 0;
}
