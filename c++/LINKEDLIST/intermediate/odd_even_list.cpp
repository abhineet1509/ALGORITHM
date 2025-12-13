#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* segregateOddEvenDummy(ListNode* head) {
    if (!head) return head;

    ListNode oddDummy(0), evenDummy(0);
    ListNode *odd = &oddDummy, *even = &evenDummy;

    ListNode* cur = head;
    while (cur) {
        if (cur->val % 2 != 0) {
            odd->next = cur;
            odd = odd->next;
        } else {
            even->next = cur;
            even = even->next;
        }
        cur = cur->next;
    }

    even->next = NULL;         // end even list
    odd->next = evenDummy.next; // join odd + even

    return oddDummy.next;
}


ListNode* segregateOddEven(ListNode* head) {
    if (!head) return head;

    ListNode *oddHead = NULL, *oddTail = NULL;
    ListNode *evenHead = NULL, *evenTail = NULL;

    ListNode* cur = head;

    while (cur) {
        if (cur->val % 2 != 0) {         // odd
            if (!oddHead) oddHead = oddTail = cur;
            else oddTail = oddTail->next = cur;
        } else {                         // even
            if (!evenHead) evenHead = evenTail = cur;
            else evenTail = evenTail->next = cur;
        }
        cur = cur->next;
    }

    if (evenTail) evenTail->next = NULL;
    if (!oddHead) return evenHead;
    oddTail->next = evenHead;

    return oddHead;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}


int main() {

   
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);

    cout << "Original List: ";
    printList(head);

    // Using dummy nodes
    ListNode* res1 = segregateOddEvenDummy(head);
    cout << "Using Dummy: ";
    printList(res1);

    // Recreate list since first function rearranged it
    head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);

    // Without dummy nodes
    ListNode* res2 = segregateOddEven(head);
    cout << "Without Dummy: ";
    printList(res2);

    return 0;
}
