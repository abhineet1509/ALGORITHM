#include <iostream>
using namespace std;

// AVL Tree Node structure
struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
};

// Function to get the height of the node
int height(Node* n) {
    return n ? n->height : 0;
}

// Function to get maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Create a new node
Node* newNode(int key) {
    Node* node = new Node();
    node->key = key;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1;  // New node is initially at leaf level
    return node;
}

// Right rotate subtree rooted with y
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;  // New root
}

// Left rotate subtree rooted with x
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;  // New root
}

// Get Balance factor of node n
int getBalance(Node* n) {
    return n ? height(n->left) - height(n->right) : 0;
}

// Function to find the node with minimum value
Node* minValueNode(Node* node) {
    Node* current = node;

    // Find the leftmost leaf
    while (current->left != nullptr)
        current = current->left;

    return current;
}

// Recursive function to delete a node with the given key from the AVL tree
Node* deleteNode(Node* root, int key) {
    // STEP 1: Perform standard BST delete
    if (!root)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        // Node with only one child or no child
        if (!root->left || !root->right) {
            Node* temp = root->left ? root->left : root->right;

            // No child case
            if (!temp) {
                temp = root;
                root = nullptr;
            } else  // One child case
                *root = *temp;  // Copy the contents of the non-empty child

            delete temp;
        } else {
            // Node with two children: Get the inorder successor
            Node* temp = minValueNode(root->right);

            // Copy the inorder successor's data to this node
            root->key = temp->key;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->key);
        }
    }

    // If the tree had only one node
    if (!root)
        return root;

    // STEP 2: Update height of the current node
    root->height = 1 + max(height(root->left), height(root->right));

    // STEP 3: Get the balance factor
    int balance = getBalance(root);

    // STEP 4: If the node is unbalanced, balance the tree

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Function to print the tree in preorder
void preOrder(Node* root) {
    if (root != nullptr) {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main() {
    Node* root = nullptr;

    // Constructing the AVL tree
    root = newNode(9);
    root->left = newNode(5);
    root->right = newNode(10);
    root->left->left = newNode(1);
    root->left->right = newNode(6);
    root->right->right = newNode(11);

    cout << "Preorder traversal of the AVL tree is:\n";
    preOrder(root);

    // Deleting nodes
    root = deleteNode(root, 10);

    cout << "\nPreorder traversal after deletion of 10:\n";
    preOrder(root);

    return 0;
}
