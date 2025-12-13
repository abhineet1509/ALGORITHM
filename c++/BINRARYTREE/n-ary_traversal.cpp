#include <bits/stdc++.h>
using namespace std;

// ---------- N-ARY TREE NODE ----------
struct Node {
    int val;
    vector<Node*> children;
    Node(int x) : val(x) {}
};

// ---------- SOLUTION ----------
class Solution {
public:
    vector<int> pre, in, post;

    // ===== PREORDER =====
    void preorder(Node* root) {
        if (!root) return;
        pre.push_back(root->val);
        for (auto child : root->children)
            preorder(child);
    }

    // ===== INORDER (GENERALIZED) =====
    void inorder(Node* root) {
        if (!root) return;

        if (!root->children.empty())
            inorder(root->children[0]);

        in.push_back(root->val);

        for (int i = 1; i < root->children.size(); i++)
            inorder(root->children[i]);
    }

    // ===== POSTORDER =====
    void postorder(Node* root) {
        if (!root) return;
        for (auto child : root->children)
            postorder(child);
        post.push_back(root->val);
    }
};

// ---------- MAIN ----------
int main() {
    /*
            1
          / | \
         2  3  4
            |
            5
    */

    Node* root = new Node(1);
    root->children.push_back(new Node(2));
    root->children.push_back(new Node(3));
    root->children.push_back(new Node(4));
    root->children[1]->children.push_back(new Node(5));

    Solution ob;

    ob.preorder(root);
    ob.inorder(root);
    ob.postorder(root);

    cout << "Preorder: ";
    for (int x : ob.pre) cout << x << " ";

    cout << "\nInorder (Generalized): ";
    for (int x : ob.in) cout << x << " ";

    cout << "\nPostorder: ";
    for (int x : ob.post) cout << x << " ";

    return 0;
}
