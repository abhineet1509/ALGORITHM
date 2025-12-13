#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// ---------- Reverse Level Order Traversal ----------
vector<int> reverseLevelOrder(Node* root) {
    vector<int> ans;
    if (!root) return ans;

    queue<Node*> q;
    stack<int> st;

    q.push(root);

    while (!q.empty()) {
        Node* cur = q.front();
        q.pop();

        st.push(cur->data);

        // Push right first so left is printed first in stack
        if (cur->right) q.push(cur->right);
        if (cur->left)  q.push(cur->left);
    }

    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}


int main() {
    /*
            1
           / \
          2   3
         / \
        4   5
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> res = reverseLevelOrder(root);

    cout << "Reverse Level Order: ";
    for (int x : res) cout << x << " ";

    return 0;
}
