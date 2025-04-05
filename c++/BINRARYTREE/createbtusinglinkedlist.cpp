#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

Node* BinaryTree() {
    int x;
    cout << "Enter node value (-1 for NULL): ";
    cin >> x;
    if (x == -1) return NULL;
    
    Node *temp = new Node(x);
    cout << "Enter the left child of " << x << endl;
    temp->left = BinaryTree();
    cout << "Enter the right child of " << x << endl;
    temp->right = BinaryTree();
    return temp;
}

// In-order traversal
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Pre-order traversal
void preorder(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Post-order traversal
void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    cout << "Enter the root node: ";
    Node *root = BinaryTree();
    
    cout << "\nIn-order Traversal: ";
    inorder(root);
    cout << "\nPre-order Traversal: ";
    preorder(root);
    cout << "\nPost-order Traversal: ";
    postorder(root);
    cout << endl;
    
    return 0;
}
