#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val): data(val), left(nullptr), right(nullptr) {}
};

// ---------------------- BFS Left View ----------------------
void leftViewBFS(Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);

    cout << "Left View (BFS): ";

    while (!q.empty()) {
        int levelSize = q.size();

        for (int i = 0; i < levelSize; i++) {
            Node* curr = q.front();
            q.pop();

            // First node of the level
            if (i == 0)
                cout << curr->data << " ";

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
    }
    cout << endl;
}

// ---------------------- DFS Left View ----------------------
void leftViewDFSUtil(Node* node, int level, int& maxLevel) {
    if (!node) return;

    if (level > maxLevel) {
        cout << node->data << " ";
        maxLevel = level;
    }

    leftViewDFSUtil(node->left, level + 1, maxLevel);
    leftViewDFSUtil(node->right, level + 1, maxLevel);
}

void leftViewDFS(Node* root) {
    int maxLevel = 0;
    cout << "Left View (DFS): ";
    leftViewDFSUtil(root, 1, maxLevel);
    cout << endl;
}

// ---------------------- Main Function ----------------------
int main() {
    /*
            1
          /   \
         2     3
          \   / \
           4 5   6
                /
               7
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->right->left = new Node(7);

    leftViewBFS(root);  // Output: 1 2 4 7
    leftViewDFS(root);  // Output: 1 2 4 7

    return 0;
}
