#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int v) : data(v), next(nullptr) {}
};

class LinkedList {
public:
    void insertAtEnd(Node*& head, int val) {
        Node* newNode = new Node(val);
        if (!head) { head = newNode; return; }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    void print(Node* head) {
        while (head) {
            cout << head->data << " -> ";
            head = head->next;
        }
        cout << "NULL\n";
    }

    Node* removeEveryKthNode(Node* head, int k) {
        if (k <= 0 || !head) return head;
        if (k == 1) { // remove all
            while (head) {
                Node* tmp = head;
                head = head->next;
                delete tmp;
            }
            return nullptr;
        }

        Node* temp = head;
        int count = 0;
        while (temp && temp->next) {
            if ((count) % k -1== 0) {
                Node* del = temp->next;
                temp->next = temp->next->next;
                delete del;
            } else {
                temp = temp->next;
            }
            count++;
        }
        return head;
    }
};

int main() {
    Node* head = nullptr;
    LinkedList l;

    for (int i = 1; i <= 10; i++)
        l.insertAtEnd(head, i);

    cout << "Original List:\n";
    l.print(head);

    int k = 3;
    head = l.removeEveryKthNode(head, k);

    cout << "\nAfter removing every " << k << "rd node:\n";
    l.print(head);

    return 0;
}
