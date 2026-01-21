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

int main() {
    /*
            1
           / \
          2   3
         / \   \
        4   5   6
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    vector<int> preorder, inorder, postorder;
    stack<pair<Node*, int>> st;

    st.push({root, 1});

    while (!st.empty()) {
        Node* node = st.top().first;
        int state = st.top().second;
        st.pop();

        if (state == 1) {
            preorder.push_back(node->data);
            st.push({node, 2});
            if (node->left)
                st.push({node->left, 1});
        }
        else if (state == 2) {
            inorder.push_back(node->data);
            st.push({node, 3});
            if (node->right)
                st.push({node->right, 1});
        }
        else {
            postorder.push_back(node->data);
        }
    }

    cout << "Preorder: ";
    for (int x : preorder) cout << x << " ";

    cout << "\nInorder: ";
    for (int x : inorder) cout << x << " ";

    cout << "\nPostorder: ";
    for (int x : postorder) cout << x << " ";

    return 0;
}
