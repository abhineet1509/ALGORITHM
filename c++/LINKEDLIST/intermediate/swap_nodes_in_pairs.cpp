#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* swapPairsIterative(ListNode* head) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* prev = dummy;

    while (head && head->next) {
        ListNode* first = head;
        ListNode* second = head->next;

        prev->next = second;
        first->next = second->next;
        second->next = first;

        prev = first;
        head = first->next;
    }

    return dummy->next;
}

ListNode* swapPairsRecursive(ListNode* head) {
    if (!head || !head->next)
        return head;

    ListNode* newHead = head->next;
    head->next = swapPairsRecursive(newHead->next);
    newHead->next = head;
    return newHead;
}

ListNode* createList(vector<int> vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* curr = head;
    for (int i = 1; i < vals.size(); i++) {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
    }
    return head;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    vector<int> vals = {1, 2, 3, 4};
    ListNode* head = createList(vals);

    cout << "Original List: ";
    printList(head);

    ListNode* iterativeResult = swapPairsIterative(head);
    cout << "After Iterative Swap: ";
    printList(iterativeResult);

    head = createList(vals);
    ListNode* recursiveResult = swapPairsRecursive(head);
    cout << "After Recursive Swap: ";
    printList(recursiveResult);

    return 0;
}
