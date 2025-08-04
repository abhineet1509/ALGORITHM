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

void removeDuplicatesSorted(Node* head) {
    Node* curr = head;
    while (curr && curr->next) {
        if (curr->data == curr->next->data) {
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp; // free memory
        } else {
            curr = curr->next;
        }
    }
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

    cout << "Enter elements (sorted order): ";
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        insertEnd(head, x);
    }

    cout << "\nOriginal List: ";
    printList(head);

    removeDuplicatesSorted(head);

    cout << "After Removing Duplicates: ";
    printList(head);
}
