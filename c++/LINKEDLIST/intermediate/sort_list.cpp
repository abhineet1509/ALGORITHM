#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void insertEnd(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) { head = newNode; return; }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

Node* merge(Node* l1, Node* l2) {
    Node dummy(0);
    Node* tail = &dummy;

    while (l1 && l2) {
        if (l1->data < l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    tail->next = l1 ? l1 : l2;
    return dummy.next;
}

Node* getMiddle(Node* head) {
    if (!head || !head->next) return head;
    Node* slow = head;
    Node* fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* mergeSort(Node* head) {
    if (!head || !head->next) return head;

    Node* mid = getMiddle(head);
    Node* right = mid->next;
    mid->next = nullptr;

    Node* left = mergeSort(head);
    right = mergeSort(right);

    return merge(left, right);
}

void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}


int main() {
    Node* head = nullptr;
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        insertEnd(head, x);
    }

    head = mergeSort(head);

    cout << "Sorted List: ";
    printList(head);
}
