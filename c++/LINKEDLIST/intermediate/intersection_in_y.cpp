#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Insert node at end, returns head
Node* insertEnd(Node* head, int val) {
    Node* newNode = new Node(val);
    if (!head) return newNode;
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    return head;
}

int getLength(Node* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

Node* getIntersection(Node* headA, Node* headB) {
    int lenA = getLength(headA);
    int lenB = getLength(headB);

    Node* p1 = headA;
    Node* p2 = headB;

    if (lenA > lenB) {
        int diff = lenA - lenB;
        while (diff--) p1 = p1->next;
    } else {
        int diff = lenB - lenA;
        while (diff--) p2 = p2->next;
    }

    while (p1 && p2) {
        if (p1 == p2) return p1;
        p1 = p1->next;
        p2 = p2->next;
    }
    return nullptr;
}

int main() {
    int n1, n2, commonLen;
    cout << "Enter length of first list: ";
    cin >> n1;
    cout << "Enter length of second list: ";
    cin >> n2;
    cout << "Enter length of common part (intersection): ";
    cin >> commonLen;

    Node* headA = nullptr;
    Node* headB = nullptr;
    Node* common = nullptr;

    cout << "Enter elements of first list (excluding common part): ";
    for (int i = 0; i < n1 - commonLen; i++) {
        int x; cin >> x;
        headA = insertEnd(headA, x);
    }

    cout << "Enter elements of second list (excluding common part): ";
    for (int i = 0; i < n2 - commonLen; i++) {
        int x; cin >> x;
        headB = insertEnd(headB, x);
    }

    cout << "Enter elements of common part: ";
    for (int i = 0; i < commonLen; i++) {
        int x; cin >> x;
        common = insertEnd(common, x);
    }

    if (headA) {
        Node* temp = headA;
        while (temp->next) temp = temp->next;
        temp->next = common;
    } else headA = common;

    if (headB) {
        Node* temp = headB;
        while (temp->next) temp = temp->next;
        temp->next = common;
    } else headB = common;

    Node* inter = getIntersection(headA, headB);
    if (inter) cout << "Intersection at node with data " << inter->data << endl;
    else cout << "No intersection" << endl;
}
