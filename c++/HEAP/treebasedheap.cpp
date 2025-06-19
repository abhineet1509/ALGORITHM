#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

class HeapTree {
    Node* root;

    void levelOrderInsert(Node* newNode) {
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* curr = q.front(); q.pop();
            if (!curr->left) {
                curr->left = newNode;
                return;
            } else q.push(curr->left);

            if (!curr->right) {
                curr->right = newNode;
                return;
            } else q.push(curr->right);
        }
    }

public:
    HeapTree() : root(NULL) {}

    void insert(int val) {
        Node* newNode = new Node(val);
        if (!root) {
            root = newNode;
        } else {
            levelOrderInsert(newNode);
        }
    }

    void levelOrderPrint() {
        if (!root) return;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* curr = q.front(); q.pop();
            cout << curr->val << " ";
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
        cout << endl;
    }
};

int main() {
    HeapTree h;
    h.insert(10);
    h.insert(5);
    h.insert(3);
    h.insert(2);
    h.insert(7);
    h.levelOrderPrint();  // Output: 10 5 3 2 7 (not heapified yet)
}
