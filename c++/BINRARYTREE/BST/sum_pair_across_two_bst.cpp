#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// inorder traversal
void inorder(Node* root, vector<int> &v) {
    if (!root) return;
    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

int countPairs(Node* root1, Node* root2, int X) {
    vector<int> a, b;

    inorder(root1, a);  // sorted
    inorder(root2, b);  // sorted

    int i = 0, j = b.size() - 1;
    int count = 0;

    while (i < a.size() && j >= 0) {
        int sum = a[i] + b[j];

        if (sum == X) {
            count++;
            i++;
            j--;
        }
        else if (sum < X)
            i++;
        else
            j--;
    }
    return count;
}

// ---------------- DRIVER CODE ----------------
int main() {
    /* BST 1 */
    Node* root1 = new Node(5);
    root1->left = new Node(3);
    root1->right = new Node(7);
    root1->left->left = new Node(2);
    root1->left->right = new Node(4);

    /* BST 2 */
    Node* root2 = new Node(10);
    root2->left = new Node(6);
    root2->right = new Node(15);
    root2->left->left = new Node(3);
    root2->left->right = new Node(8);

    int X = 13;

    cout << "Count of pairs = " << countPairs(root1, root2, X);
    return 0;
}
