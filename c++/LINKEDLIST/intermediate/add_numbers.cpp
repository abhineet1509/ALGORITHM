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

Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    while (curr) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

Node* addTwoNumbers(Node* l1, Node* l2) {
    l1 = reverseList(l1);
    l2 = reverseList(l2);

    // Node* dummy = new Node(0);   // heap may momoery leakage
    // Node* curr = dummy;
     Node dummy(0);
    Node* curr = &dummy;    //stack safe and clean
    int carry = 0;

    while (l1 || l2 || carry) {
        int sum = carry;
        if (l1) { sum += l1->data; l1 = l1->next; }         //Sum = x + y + carry; carry = sum / 10; node = sum % 10
        if (l2) { sum += l2->data; l2 = l2->next; }         //Sub = x - y - borrow; if sub < 0 → sub += 10, borrow = 1

        carry = sum / 10;
        curr->next = new Node(sum % 10);
        curr = curr->next;
    }

    return reverseList(dummy.next);
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
    Node* l1 = nullptr;
    Node* l2 = nullptr;

    int n1, n2;
    cout << "Enter number of digits in first number: ";
    cin >> n1;
    cout << "Enter digits of first number (forward order): ";
    for (int i = 0; i < n1; i++) {
        int x; cin >> x;
        insertEnd(l1, x);
    }

    cout << "Enter number of digits in second number: ";
    cin >> n2;
    cout << "Enter digits of second number (forward order): ";
    for (int i = 0; i < n2; i++) {
        int x; cin >> x;
        insertEnd(l2, x);
    }

    Node* result = addTwoNumbers(l1, l2);
    cout << "Sum: ";
    printList(result);
}
