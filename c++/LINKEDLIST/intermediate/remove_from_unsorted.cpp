#include <iostream>
#include <unordered_set>
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

void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// O(n²) Brute Force with temp trick
void removeDuplicatesBrute(Node* head) {
    Node* curr = head;
    while (curr) {
        Node* prev = curr;
        Node* runner = curr->next;
        while (runner) {
            if (runner->data == curr->data) {
                Node* temp = runner;
                prev->next = runner->next;
                runner = runner->next;
                delete temp; // safe delete
            } else {
                prev = runner;
                runner = runner->next;
            }
        }
        curr = curr->next;
    }
}

// O(n) Hashing
void removeDuplicatesHash(Node* head) {
    if (!head) return;
    unordered_set<int> seen;
    Node* curr = head;
    Node* prev = nullptr;

    while (curr) {
        if (seen.count(curr->data)) {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        } else {
            seen.insert(curr->data);
            prev = curr;
            curr = curr->next;
        }
    }
}

int main() {
    Node* head1 = nullptr;
    Node* head2 = nullptr;

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements (unsorted): ";
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        insertEnd(head1, x);
        insertEnd(head2, x); // copy for hashing version
    }

    cout << "\nOriginal List: ";
    printList(head1);

    removeDuplicatesBrute(head1);
    cout << "After Brute Force Removal: ";
    printList(head1);

    removeDuplicatesHash(head2);
    cout << "After Hashing Removal: ";
    printList(head2);
}
