#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) {
        data = val;
        next = prev = NULL;
    }
};

// Insert at tail
void insertAtTail(Node* &head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

// Print DLL
void printDLL(Node* head) {
    while (head) {
        cout << head->data << " <-> ";
        head = head->next;
    }
    cout << "NULL\n";
}

// Find pairs with given sum
void findPairsWithSum(Node* head, int sum) {
    Node* first = head;
    Node* last = head;

    // Move last to the tail
    while (last->next) last = last->next;

    bool found = false;

    while (first != last && last->next != first) {
        int currSum = first->data + last->data;

        if (currSum == sum) {
            cout << "(" << first->data << ", " << last->data << ")\n";
            found = true;
            first = first->next;
            last = last->prev;
        }
        else if (currSum < sum) first = first->next;
        else last = last->prev;
    }

    if (!found) cout << "No pairs found with sum " << sum << "\n";
}

int main() {
    Node* head = NULL;

    // Sorted DLL
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    insertAtTail(head, 8);
    insertAtTail(head, 9);

    cout << "DLL:\n";
    printDLL(head);

    int sum = 7;
    cout << "\nPairs with sum " << sum << ":\n";
    findPairsWithSum(head, sum);

    return 0;
}
