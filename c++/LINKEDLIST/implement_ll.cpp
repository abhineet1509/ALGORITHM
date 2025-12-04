#include <iostream>
using namespace std;

// Class-based Node (fixed-size input)
class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Struct-based ListNode (sentinel-based input)
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};

int main() {
    cout << "Enter number of nodes (class Node version): ";
    int n; 
    cin >> n;
    if (n > 0) {
        int x; 
        cin >> x;
        Node* head = new Node(x);
        Node* tail = head;

        for (int i = 1; i < n; i++) {
            cin >> x;
            tail->next = new Node(x);
            tail = tail->next;
        }

        cout << "Class Node Linked List: ";
        for (Node* temp = head; temp; temp = temp->next)
            cout << temp->data << " ";
        cout << "\n";
    }

    cout << "\nEnter elements (-1 to stop) (struct ListNode version): ";
    int x;
    ListNode* head2 = NULL, *tail2 = NULL;
    while (cin >> x && x != -1) {
        ListNode* node = new ListNode(x);
        if (!head2) head2 = tail2 = node;
        else {
            tail2->next = node;
            tail2 = node;
        }
    }

    cout << "Struct ListNode Linked List: ";
    for (ListNode* p = head2; p; p = p->next)
        cout << p->val << " ";
    cout << "\n";

    // Demonstrating dummy node initialization
    Node dummy(0);
    Node* tail = &dummy;
    tail->next = new Node(100);
//     Node* dummy = new Node(0);
// Node* tail = dummy;


    cout << "\nDummy List Example: ";
    for (Node* t = dummy.next; t; t = t->next)
        cout << t->data << " ";
    cout << "\n";
}
