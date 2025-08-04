#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* reverseList(Node* head) {
    Node* prev = nullptr, *curr = head;
    while (curr) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool isPalindrome(Node* head) {
    if (!head || !head->next) return true;
    Node *slow = head, *fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* second = reverseList(slow->next);
    Node* first = head;
    while (second) {
        if (first->data != second->data) return false;
        first = first->next;
        second = second->next;
    }
    return true;
}

int main() {
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(2);
    head1->next->next->next->next = new Node(1);
    cout << (isPalindrome(head1) ? "Palindrome" : "Not Palindrome") << endl;

    Node* head2 = new Node(1);
    head2->next = new Node(2);
    head2->next->next = new Node(2);
    head2->next->next->next = new Node(1);
    cout << (isPalindrome(head2) ? "Palindrome" : "Not Palindrome") << endl;

    Node* head3 = new Node(1);
    head3->next = new Node(2);
    head3->next->next = new Node(3);
    cout << (isPalindrome(head3) ? "Palindrome" : "Not Palindrome") << endl;
}
