#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int data;
    ListNode* next;
    ListNode* prev;

    ListNode(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class Solution {
public:
    ListNode* deleteAllOccurrences(ListNode* head, int target) {
        if (head == NULL) return head;

        ListNode* temp = head;

        while (temp != NULL) {
            if (temp->data == target) {
                ListNode* del = temp;

                // If node to delete is head
                if (temp->prev == NULL) {
                    head = temp->next;
                    if (head)
                        head->prev = NULL;
                }
                // If node is middle or last
                else {
                    temp->prev->next = temp->next;
                    if (temp->next)
                        temp->next->prev = temp->prev;
                }

                temp = temp->next; // move forward
                delete del;
            } else {
                temp = temp->next;
            }
        }
        return head;
    }
};

// Utility function to print DLL
void printList(ListNode* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Utility function to insert at end
ListNode* insertEnd(ListNode* head, int val) {
    ListNode* newNode = new ListNode(val);
    if (!head) return newNode;

    ListNode* temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

int main() {
    ListNode* head = NULL;

    // Create DLL: 1 2 3 2 4 2 5
    head = insertEnd(head, 1);
    head = insertEnd(head, 2);
    head = insertEnd(head, 3);
    head = insertEnd(head, 2);
    head = insertEnd(head, 4);
    head = insertEnd(head, 2);
    head = insertEnd(head, 5);
    //  Node* head = new Node(1);
    // head->next = new Node(2);
    // head->next->prev = head;
    // head->next->next = new Node(3);
    // head->next->next->prev = head->next;
    // head->next->next->next = new Node(2);
    // head->next->next->next->prev = head->next->next;
    // head->next->next->next->next = new Node(4);
    // head->next->next->next->next->prev = head->next->next->next;
    cout << "Original DLL: ";
    printList(head);

    Solution sol;
    head = sol.deleteAllOccurrences(head, 2);

    cout << "After deleting 2: ";
    printList(head);

    return 0;
}
