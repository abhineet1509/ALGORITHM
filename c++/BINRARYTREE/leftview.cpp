#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

vector<int> leftView(Node* root) {
    vector<int> result;
    if (!root) return result;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        int i = 0;

        // Inner while loop to traverse current level
        while (i < levelSize) {
            Node* curr = q.front();
            q.pop();

            // First node of current level
            if (i == 0) result.push_back(curr->data);

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);

            i++;
        }
    }

    return result;
}

// Example usage
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->right = new Node(7);

    vector<int> res = leftView(root);
    for (int val : res) cout << val << " ";
    return 0;
}
