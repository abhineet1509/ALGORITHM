#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

// inorder traversal
void inorder(Node* root, vector<int>& v) {
    if (!root) return;
    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

// merge two BSTs
vector<int> mergeBST(Node* root1, Node* root2) {
    vector<int> a, b, ans;

    inorder(root1, a);
    inorder(root2, b);

    int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) ans.push_back(a[i++]);
        else ans.push_back(b[j++]);
    }

    while (i < a.size()) ans.push_back(a[i++]);
    while (j < b.size()) ans.push_back(b[j++]);

    return ans;
}

// ---------- Driver code (sample) ----------
int main() {
    Node* root1 = new Node(2);
    root1->left = new Node(1);
    root1->right = new Node(3);

    Node* root2 = new Node(7);
    root2->left = new Node(6);
    root2->right = new Node(8);

    vector<int> res = mergeBST(root1, root2);

    for (int x : res) cout << x << " ";
    return 0;
}
