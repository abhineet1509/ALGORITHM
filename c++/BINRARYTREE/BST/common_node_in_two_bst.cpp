#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

vector<int> findCommon(Node* root1, Node* root2) {
    vector<int> ans;
    stack<Node*> s1, s2;

    while (true) {

        // Push left of both trees
        while (root1) { s1.push(root1); root1 = root1->left; }
        while (root2) { s2.push(root2); root2 = root2->left; }

        // If any stack empty → done
        if (s1.empty() || s2.empty()) break;

        Node* top1 = s1.top();
        Node* top2 = s2.top();

        if (top1->data == top2->data) {
            ans.push_back(top1->data);
            s1.pop(); s2.pop();
            root1 = top1->right;
            root2 = top2->right;
        }
        else if (top1->data < top2->data) {
            s1.pop();
            root1 = top1->right;
        }
        else {
            s2.pop();
            root2 = top2->right;
        }
    }
    return ans;
}

// -------- Driver Example --------
int main() {
    Node* r1 = new Node(5);
    r1->left = new Node(1);
    r1->right = new Node(10);
    r1->left->right = new Node(4);
    r1->right->left = new Node(7);
    r1->right->right = new Node(12);

    Node* r2 = new Node(10);
    r2->left = new Node(7);
    r2->right = new Node(20);
    r2->left->left = new Node(4);
    r2->left->right = new Node(9);

    vector<int> res = findCommon(r1, r2);

    for (int x : res) cout << x << " ";
    return 0;
}
