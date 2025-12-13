#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Find LCA of two nodes
Node* LCA(Node* root, int a, int b) {
    if(!root) return NULL;
    if(root->data == a || root->data == b) return root;

    Node* left = LCA(root->left, a, b);
    Node* right = LCA(root->right, a, b);

    if(left && right) return root;
    return left ? left : right;
}

// Count turns from node to target
bool countTurns(Node* root, int target, string dir, int& turns, bool firstCall=true) {
    if(!root) return false;
    if(root->data == target) return true;

    // go left
    if(countTurns(root->left, target, "left", turns, false)) {
        if(!firstCall && dir != "left") turns++;
        return true;
    }
    // go right
    if(countTurns(root->right, target, "right", turns, false)) {
        if(!firstCall && dir != "right") turns++;
        return true;
    }
    return false;
}

// Total turns between two nodes
int numberOfTurns(Node* root, int start, int end) {
    Node* lca = LCA(root, start, end);
    int turns1=0, turns2=0;

    if(lca->data != start && lca->data != end)
        countTurns(lca, start, "", turns1);
    if(lca->data != start && lca->data != end)
        countTurns(lca, end, "", turns2);

    if(lca->data != start && lca->data != end)
        return turns1 + turns2 + 1; // +1 for LCA turn
    else
        return turns1 + turns2;
}

// Example usage
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->right->left = new Node(5);
    root->left->right->right = new Node(6);

    int start = 2, end = 6;
    cout << "Number of turns: " << numberOfTurns(root, start, end) << endl; // Output: 1
}
