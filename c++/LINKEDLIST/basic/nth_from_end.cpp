#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Build a linked list (stop at -1)
ListNode* buildList() {
    cout << "Enter elements (-1 to stop): ";
    int x;
    ListNode *head = NULL, *tail = NULL;

    while (cin >> x && x != -1) {
        ListNode* node = new ListNode(x);
        if (!head) head = tail = node;
        else {
            tail->next = node;
            tail = node;
        }
    }
    return head;
}

// Print the list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << "\n";
}

// Remove Nth node from the end (O(N), one pass)
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode dummy(0);
    dummy.next = head;

    ListNode *fast = &dummy, *slow = &dummy;

    while (n--) fast = fast->next;  // move fast n steps
    while (fast->next) {            // move both until fast hits end
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = slow->next->next;  // delete node

    return dummy.next;
}

int main() {
    // Build linked list
    ListNode* head = buildList();

    int n;
    cout << "Enter n (Nth from end to remove): ";
    cin >> n;

    // Remove the Nth node and update head
    head = removeNthFromEnd(head, n);

    // Display result
    cout << "List after removal: ";
    printList(head);

    return 0;
}
