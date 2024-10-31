#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

void deleteMiddleNode(Node* head) {
    if (head == nullptr || head->next == nullptr) return;

    Node* slow = head;
    Node* fast = head;
    Node* slowNext = nullptr;

    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slowNext = slow;
        slow = slow->next;
    }

    if (slowNext != nullptr && slow != nullptr) {
        slowNext->next = slow->next;
        delete slow;
    }
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n, data;
    Node* head = nullptr;
    Node* tail = nullptr;

    cout << "Enter the number of elements in the list: ";
    cin >> n;
    cout << "Enter the elements of the list: ";
    for (int i = 0; i < n; i++) {
        cin >> data;
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    cout << "Original list: ";
    printList(head);

    deleteMiddleNode(head);

    cout << "After deleting the middle node: ";
    printList(head);

    return 0;
}
