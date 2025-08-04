#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Merge two sorted linked lists
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode* tail = &dummy;

    while (l1 && l2) {
        if (l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    tail->next = (l1) ? l1 : l2;  // attach remaining nodes
    return dummy.next;
}

// Merge k sorted linked lists sequentially
ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.empty()) return NULL;

    ListNode* merged = lists[0];
    for (int i = 1; i < lists.size(); i++) {
        merged = mergeTwoLists(merged, lists[i]);
    }
    return merged;
}

// Helper to print list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Example usage
int main() {
    // Creating 3 sorted linked lists
    ListNode* a = new ListNode(1);
    a->next = new ListNode(4);
    a->next->next = new ListNode(5);

    ListNode* b = new ListNode(1);
    b->next = new ListNode(3);
    b->next->next = new ListNode(4);

    ListNode* c = new ListNode(2);
    c->next = new ListNode(6);

    vector<ListNode*> lists = {a, b, c};

    ListNode* result = mergeKLists(lists);

    cout << "Merged List: ";
    printList(result);

    return 0;
}
