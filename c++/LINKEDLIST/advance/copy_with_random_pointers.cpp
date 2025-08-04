#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    Node(int v): val(v), next(nullptr), random(nullptr) {}
};

Node* copyRandomList(Node* head) {
    if (!head) return nullptr;
    unordered_map<Node*, Node*> mp;
    for (Node* p = head; p; p = p->next) {
        mp[p] = new Node(p->val);
    }
    for (Node* p = head; p; p = p->next) {
        mp[p]->next   = mp[p->next];
        mp[p]->random = mp[p->random];
    }
    return mp[head];
}

void printList(Node* head) {
    while (head) {
        int r = head->random ? head->random->val : -1;
        cout << "[" << head->val << ", r=" << r << "] -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    n1->next = n2; n2->next = n3;
    n1->random = n3;
    n2->random = n1;
    n3->random = n2;

    cout << "Original list:\n";
    printList(n1);

    Node* copyHead = copyRandomList(n1);
    cout << "\nCopied list:\n";
    printList(copyHead);

    return 0;
}
